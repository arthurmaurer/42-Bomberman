
#include <algorithm>
#include <cstring>
#include <tiny_obj_loader.h>

#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/ShaderProgram.hpp"
#include "Engine/Tools/ModelManager.hpp"
#include "Engine/Tools/MathUtil.hpp"
#include "Engine/Tools/FileUtil.hpp"

using namespace Fothon;

std::map<std::string, obj_t *>	ModelManager::_cachedOBJs;
std::vector<GLuint>				ModelManager::_vbos;
std::vector<GLuint>				ModelManager::_vaos;
std::vector<GLuint>				ModelManager::_ibos;

void	ModelManager::_getModelData(RawModelData & modelData, const ShapeList & shapes, const MaterialList & materials)
{
	std::vector<Vec3>::const_iterator	it;
	Vec3	position;
	Vec3	normal;
	Vec2	uv;

	for (const auto & shape : shapes)
	{
		for (GLuint indice : shape.mesh.indices)
		{
			uv = Vec2::zero;

			position.x = shape.mesh.positions[indice * 3];
			position.y = shape.mesh.positions[indice * 3 + 1];
			position.z = shape.mesh.positions[indice * 3 + 2];

			it = std::find(modelData.positions.cbegin(), modelData.positions.cend(), position);

			if (it == modelData.positions.cend())
			{
				if (indice * 2 + 1 < shape.mesh.texcoords.size())
				{
					uv.x = shape.mesh.texcoords[indice * 2];
					uv.y = shape.mesh.texcoords[indice * 2 + 1];
				}

				if (indice * 3 + 2 < shape.mesh.normals.size())
				{
					normal.x = shape.mesh.normals[indice * 3];
					normal.y = shape.mesh.normals[indice * 3 + 1];
					normal.z = shape.mesh.normals[indice * 3 + 2];
				}

				modelData.positions.push_back(position);
				modelData.uvs.push_back(uv);
				modelData.normals.push_back(normal);
				modelData.indices.push_back(modelData.positions.size() - 1);
			}
			else
			{
				modelData.indices.push_back(it - modelData.positions.cbegin());
			}
		}
	}

	(void)materials;
}

void		ModelManager::_fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs, const std::vector<Vec3> & normals)
{
	size_t		positionsLength = positions.size();
	size_t		uvsLength = uvs.size();
	size_t		normalsLength = normals.size();

	memset(buffer, 0, positionsLength * VERTEX_DATA_LENGTH);

	for (size_t i = 0; i < positionsLength; i++)
	{
		buffer[i * VERTEX_DATA_LENGTH] = positions[i].x;
		buffer[i * VERTEX_DATA_LENGTH + 1] = positions[i].y;
		buffer[i * VERTEX_DATA_LENGTH + 2] = positions[i].z;

		if (i < uvsLength)
		{
			buffer[i * VERTEX_DATA_LENGTH + 3] = uvs[i].x;
			buffer[i * VERTEX_DATA_LENGTH + 4] = uvs[i].y;
		}

		if (i < normalsLength)
		{
			buffer[i * VERTEX_DATA_LENGTH + 5] = normals[i].x;
			buffer[i * VERTEX_DATA_LENGTH + 6] = normals[i].y;
			buffer[i * VERTEX_DATA_LENGTH + 7] = normals[i].z;
		}
	}
}

GLuint		ModelManager::_loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs, const std::vector<Vec3> & normals)
{
	GLuint		vboID = 0;
	GLuint		programID = 0;
	GLuint		attribLocation = 0;
	GLuint		dataLength = 0;
	GLfloat *	data = NULL;

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	dataLength = positions.size() * VERTEX_DATA_LENGTH;
	data = new GLfloat[dataLength];
	_fillVBO(data, positions, uvs, normals);
	glBufferData(GL_ARRAY_BUFFER, dataLength * sizeof(GLfloat), data, GL_STATIC_DRAW);
	delete[] data;

	programID = Renderer::shaderProgram->id;

	attribLocation = glGetAttribLocation(programID, "position");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), 0);

	attribLocation = glGetAttribLocation(programID, "uv");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 2, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));

	attribLocation = glGetAttribLocation(programID, "normal");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 5));

	return vboID;
}

void		ModelManager::_fillIBO(GLuint * buffer, const std::vector<GLuint> & indices)
{
	unsigned	i = 0;

	for (GLuint index : indices)
	{
		buffer[i] = index;
		i++;
	}
}

GLuint		ModelManager::_loadIBO(const std::vector<GLuint>& indices)
{
	GLuint		iboID = 0;
	GLuint *	data = nullptr;
	size_t		dataLength = 0;

	glGenBuffers(1, &iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	dataLength = indices.size();
	data = new GLuint[dataLength];
	_fillIBO(data, indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataLength * sizeof(GLuint), data, GL_STATIC_DRAW);
	delete[] data;

	return iboID;
}

GLuint		ModelManager::_loadVAO()
{
	GLuint	vaoID = 0;

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	return vaoID;
}

Model &		ModelManager::createModel(const RawModelData & modelData)
{
	Model *		model = new Model();

	model->indexCount = modelData.indices.size();
	model->vaoID = _loadVAO();
	model->vboID = _loadVBO(modelData.positions, modelData.uvs, modelData.normals);
	model->iboID = _loadIBO(modelData.indices);

	glBindVertexArray(0);

	_vbos.push_back(model->vboID);
	_vaos.push_back(model->vaoID);
	_ibos.push_back(model->iboID);

	return *model;
}

obj_t &	ModelManager::_loadOBJ(const std::string & path)
{
	obj_t *			obj = nullptr;
	std::string		error;

	obj = _cachedOBJs[path];

	if (obj == nullptr)
	{
		obj = new obj_t();
		FileUtil::changeWorkingDirectory("resources/");
		error = tinyobj::LoadObj(obj->shapes, obj->materials, path.c_str());
		FileUtil::restoreWorkingDirectory();

		if (error.empty() == false)
			throw std::runtime_error(error);

		_cachedOBJs[path] = obj;
	}

	return *obj;
}

Model &		ModelManager::loadFromOBJ(const std::string & objPath)
{
	RawModelData	modelData;
	obj_t &			obj = _loadOBJ(objPath);

	_getModelData(modelData, obj.shapes, obj.materials);

	return createModel(modelData);
}

void		ModelManager::_unloadVBO(GLuint vboID)
{
	std::vector<GLuint>::iterator		it;

	it = std::find(_vbos.begin(), _vbos.end(), vboID);

	if (it != _vbos.end())
	{
		glDeleteBuffers(1, &vboID);
		_vbos.erase(it);
	}
}

void		ModelManager::_unloadVAO(GLuint vaoID)
{
	std::vector<GLuint>::iterator		it;

	it = std::find(_vaos.begin(), _vaos.end(), vaoID);

	if (it != _vaos.end())
	{
		glDeleteBuffers(1, &vaoID);
		_vaos.erase(it);
	}
}

void		ModelManager::_unloadIBO(GLuint iboID)
{
	std::vector<GLuint>::iterator		it;

	it = std::find(_ibos.begin(), _ibos.end(), iboID);

	if (it != _vbos.end())
	{
		glDeleteBuffers(1, &iboID);
		_vbos.erase(it);
	}
}

void		ModelManager::clearCache()
{
	for (std::pair<std::string, obj_t *> obj : _cachedOBJs)
		delete obj.second;

	_cachedOBJs.clear();
}

void		ModelManager::unloadModel(Model & model)
{
	_unloadVBO(model.vboID);
	model.vboID = 0;

	_unloadVAO(model.vaoID);
	model.vaoID = 0;

	_unloadIBO(model.iboID);
	model.iboID = 0;
}

void	ModelManager::_unloadVBOs()
{
	size_t	size;

	size = _vbos.size();
	if (size > 0)
	{
		glDeleteBuffers(size, &_vbos[0]);
		_vbos.clear();
	}
}

void	ModelManager::_unloadVAOs()
{
	size_t	size;

	size = _vaos.size();
	if (size > 0)
	{
		glDeleteBuffers(size, &_vaos[0]);
		_vaos.clear();
	}
}

void	ModelManager::_unloadIBOs()
{
	size_t	size;

	size = _ibos.size();
	if (size > 0)
	{
		glDeleteBuffers(size, &_ibos[0]);
		_ibos.clear();
	}
}

void	ModelManager::cleanUp()
{
	_unloadVBOs();
	_unloadVAOs();
	_unloadIBOs();
	clearCache();
}
