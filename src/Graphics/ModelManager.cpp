
#include "Graphics\ModelManager.hpp"
#include "Graphics/Graphics.hpp"
#include <algorithm>
#include <tiny_obj_loader.h>
#include "Utils/MathUtil.hpp"
#include "Utils/FileUtil.hpp"

std::vector<GLuint>		ModelManager::vbos;
std::vector<GLuint>		ModelManager::vaos;
std::vector<GLuint>		ModelManager::ibos;

void	ModelManager::getModelData(std::vector<Vec3> & positions, std::vector<Vec2> & uvs, std::vector<GLuint> & indices, const ShapeList & shapes, const MaterialList & materials)
{
	std::vector<Vec3>::const_iterator	it;
	Vec3								position;
	Vec2								uv;

	for (const auto & shape : shapes)
	{
		for (GLuint indice : shape.mesh.indices)
		{
			uv = Vec2::zero;

			position.x = shape.mesh.positions[indice * 3];
			position.y = shape.mesh.positions[indice * 3 + 1];
			position.z = shape.mesh.positions[indice * 3 + 2];

			it = std::find(positions.cbegin(), positions.cend(), position);

			if (it == positions.cend())
			{
				if (indice * 2 + 1 < shape.mesh.texcoords.size())
				{
					uv.x = shape.mesh.texcoords[indice * 2];
					uv.y = shape.mesh.texcoords[indice * 2 + 1];
				}

				positions.push_back(position);
				uvs.push_back(uv);
				indices.push_back(positions.size() - 1);
			}
			else
			{
				indices.push_back(it - positions.cbegin());
			}
		}
	}
}

void		ModelManager::fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs)
{
	size_t		positionsLength = positions.size();
	size_t		uvsLength = uvs.size();

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
		else
		{
			buffer[i * VERTEX_DATA_LENGTH + 3] = 0;
			buffer[i * VERTEX_DATA_LENGTH + 4] = 0;
		}
	}
}

GLuint		ModelManager::loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs)
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
	fillVBO(data, positions, uvs);
	glBufferData(GL_ARRAY_BUFFER, dataLength * sizeof(GLfloat), data, GL_STATIC_DRAW);
	delete[] data;

	programID = Graphics::shaderProgram->id;

	attribLocation = glGetAttribLocation(programID, "position");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), 0);

	attribLocation = glGetAttribLocation(programID, "uv");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 2, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));

	return vboID;
}

void		ModelManager::fillIBO(GLuint * buffer, const std::vector<GLuint> & indices)
{
	unsigned	i = 0;

	for (GLuint index : indices)
	{
		buffer[i] = index;
		i++;
	}
}

GLuint		ModelManager::loadIBO(const std::vector<GLuint>& indices)
{
	GLuint		iboID = 0;
	GLuint *	data = NULL;
	size_t		dataLength = 0;

	glGenBuffers(1, &iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

	dataLength = indices.size();
	data = new GLuint[dataLength];
	fillIBO(data, indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataLength * sizeof(GLuint), data, GL_STATIC_DRAW);
	delete[] data;

	return iboID;
}

GLuint		ModelManager::loadVAO()
{
	GLuint	vaoID = 0;

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	return vaoID;
}

void		ModelManager::loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials)
{
	std::vector<Vec3>		positions;
	std::vector<Vec2>		uvs;
	std::vector<unsigned>	indices;
	
	getModelData(positions, uvs, indices, shapes, materials);
	model.indexCount = indices.size();
	model.vaoID = loadVAO();
	model.vboID = loadVBO(positions, uvs);
	model.iboID = loadIBO(indices);

	glBindVertexArray(0);
}

Model &		ModelManager::loadFromOBJ(const std::string & objPath)
{
	std::string		error;
	ShapeList		shapes;
	MaterialList	materials;
	Model *			model = NULL;

	FileUtil::changeWorkingDirectory("resources/");
	error = tinyobj::LoadObj(shapes, materials, objPath.c_str());
	FileUtil::restoreWorkingDirectory();

	if (error.empty() == false)
		throw std::runtime_error(error);

	model = new Model();
	loadBuffer(*model, shapes, materials);

	vbos.push_back(model->vboID);
	vaos.push_back(model->vaoID);
	ibos.push_back(model->iboID);

	return *model;
}

void		ModelManager::unloadVBO(GLuint vboID)
{
	std::vector<GLuint>::const_iterator		it;

	std::find(vbos.cbegin(), vbos.cend(), vboID);

	if (it != vbos.cend())
	{
		glDeleteBuffers(1, &vboID);
		vbos.erase(it);
	}
}

void		ModelManager::unloadVAO(GLuint vaoID)
{
	std::vector<GLuint>::const_iterator		it;

	std::find(vaos.cbegin(), vaos.cend(), vaoID);

	if (it != vaos.cend())
	{
		glDeleteBuffers(1, &vaoID);
		vaos.erase(it);
	}
}

void		ModelManager::unloadIBO(GLuint iboID)
{
	std::vector<GLuint>::const_iterator		it;

	std::find(ibos.cbegin(), ibos.cend(), iboID);

	if (it != vbos.cend())
	{
		glDeleteBuffers(1, &iboID);
		vbos.erase(it);
	}
}

void		ModelManager::unloadModel(Model & model)
{
	unloadVBO(model.vboID);
	model.vboID = 0;

	unloadVAO(model.vaoID);
	model.vaoID = 0;

	unloadIBO(model.iboID);
	model.iboID = 0;
}

void	ModelManager::cleanUp()
{
	size_t	size;

	size = vbos.size();
	if (size > 0)
	{
		glDeleteBuffers(size, &vbos[0]);
		vbos.clear();
	}

	size = vaos.size();
	if (size > 0)
	{
		glDeleteVertexArrays(size, &vaos[0]);
		vaos.clear();
	}

	size = ibos.size();
	if (size > 0)
	{
		glDeleteBuffers(size, &ibos[0]);
		ibos.clear();
	}
}
