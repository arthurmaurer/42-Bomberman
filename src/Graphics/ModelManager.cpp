
#include "Graphics\ModelManager.hpp"
#include "Graphics/Graphics.hpp"
#include <algorithm>
#include <tiny_obj_loader.h>
#include "Utils/MathUtil.hpp"

void	ModelManager::getModelData(std::vector<Vec3> & positions, std::vector<Vec3> & diffuseColors, std::vector<Vec2> & uvs, std::vector<GLuint> & indices, const ShapeList & shapes, const MaterialList & materials)
{
	std::vector<Vec3>::const_iterator	it;
	Vec3								position;
	Vec3								diffuseColor;
	Vec2								uv;

	for (const auto & shape : shapes)
	{
		for (GLuint indice : shape.mesh.indices)
		{
			position.x = shape.mesh.positions[indice * 3];
			position.y = shape.mesh.positions[indice * 3 + 1];
			position.z = shape.mesh.positions[indice * 3 + 2];

			it = std::find(positions.cbegin(), positions.cend(), position);

			if (it == positions.cend())
			{
				diffuseColor.x = MathUtil::random(0, 1.1f, 0.1f);
				diffuseColor.y = MathUtil::random(0, 1.1f, 0.1f);
				diffuseColor.z = MathUtil::random(0, 1.1f, 0.1f);

				uv.x = shape.mesh.normals[indice * 3];
				uv.y = shape.mesh.normals[indice * 3 + 1];

				positions.push_back(position);
				diffuseColors.push_back(diffuseColor);
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

void		ModelManager::fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec3> & diffuseColors, const std::vector<Vec2> & uvs)
{
	size_t		positionsLength = positions.size();
	size_t		diffuseColorsLength = diffuseColors.size();
	size_t		uvsLength = uvs.size();

	for (size_t i = 0; i < positionsLength; i++)
	{
		buffer[i * VERTEX_DATA_LENGTH] = positions[i].x;
		buffer[i * VERTEX_DATA_LENGTH + 1] = positions[i].y;
		buffer[i * VERTEX_DATA_LENGTH + 2] = positions[i].z;

		if (i < diffuseColorsLength)
		{
			buffer[i * VERTEX_DATA_LENGTH + 3] = diffuseColors[i].x;
			buffer[i * VERTEX_DATA_LENGTH + 4] = diffuseColors[i].y;
			buffer[i * VERTEX_DATA_LENGTH + 5] = diffuseColors[i].z;
		}
		else
		{
			buffer[i * VERTEX_DATA_LENGTH + 3] = 0;
			buffer[i * VERTEX_DATA_LENGTH + 4] = 0;
			buffer[i * VERTEX_DATA_LENGTH + 5] = 0;
		}

		if (i < uvsLength)
		{
			buffer[i * VERTEX_DATA_LENGTH + 6] = uvs[i].x;
			buffer[i * VERTEX_DATA_LENGTH + 7] = uvs[i].y;
		}
		else
		{
			buffer[i * VERTEX_DATA_LENGTH + 6] = 0;
			buffer[i * VERTEX_DATA_LENGTH + 7] = 0;
		}
	}
}

GLuint		ModelManager::loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec3> & diffuseColors, const std::vector<Vec2> & uvs)
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
	fillVBO(data, positions, diffuseColors, uvs);
	glBufferData(GL_ARRAY_BUFFER, dataLength * sizeof(GLfloat), data, GL_STATIC_DRAW);
	delete[] data;

	programID = Graphics::shaderProgram->id;

	attribLocation = glGetAttribLocation(programID, "position");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), 0);

	attribLocation = glGetAttribLocation(programID, "color");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));

	attribLocation = glGetAttribLocation(programID, "uv");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 2, GL_FLOAT, GL_FALSE, VERTEX_DATA_LENGTH * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 6));

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
	std::vector<Vec3>		diffuseColors;
	std::vector<Vec2>		uvs;
	std::vector<unsigned>	indices;
	
	getModelData(positions, diffuseColors, uvs, indices, shapes, materials);
	model.indexCount = indices.size();
	model.vaoID = loadVAO();
	model.vboID = loadVBO(positions, diffuseColors, uvs);
	model.iboID = loadIBO(indices);

	glBindVertexArray(0);
}

Model &		ModelManager::loadFromOBJ(const std::string & objPath)
{
	std::string		error;
	ShapeList		shapes;
	MaterialList	materials;
	Model *			model = NULL;

	error = tinyobj::LoadObj(shapes, materials, objPath.c_str());

	if (error.empty() == false)
		throw std::runtime_error(error);

	model = new Model();
	loadBuffer(*model, shapes, materials);

	return *model;
}
