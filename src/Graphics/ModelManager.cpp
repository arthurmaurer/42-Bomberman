
#include "Graphics\ModelManager.hpp"
#include "Graphics/Graphics.hpp"
#include <algorithm>

void	ModelManager::getModelData(std::vector<Vec3> & positions, std::vector<Vec3> & diffuseColors, std::vector<GLuint> & indices, const ShapeList & shapes, const MaterialList & materials)
{
	std::vector<Vec3>::const_iterator	it;
	Vec3								position;
	Vec3								diffuseColor;
	const tinyobj::material_t *			material;

	for (const auto & shape : shapes)
	{
		material = &(materials[shape.mesh.material_ids[0]]);
		diffuseColor.x = material->diffuse[0];
		diffuseColor.y = material->diffuse[1];
		diffuseColor.z = material->diffuse[2];

		for (GLuint indice : shape.mesh.indices)
		{
			position.x = shape.mesh.positions[indice * 3];
			position.y = shape.mesh.positions[indice * 3 + 1];
			position.z = shape.mesh.positions[indice * 3 + 2];

			it = std::find(positions.cbegin(), positions.cend(), position);

			if (it == positions.cend())
			{
				positions.push_back(position);
				indices.push_back(positions.size() - 1);
				diffuseColors.push_back(diffuseColor);
			}
			else
			{
				indices.push_back(it - positions.cbegin());
			}
		}
	}
}

void		ModelManager::fillVBO(GLfloat * buffer, const std::vector<Vec3>& positions, const std::vector<Vec3>& diffuseColors)
{
	size_t	positionsLength = positions.size();
	size_t	diffuseColorsLength = diffuseColors.size();

	for (size_t i = 0; i < positionsLength; i++)
	{
		buffer[i * 6] = positions[i].x;
		buffer[i * 6 + 1] = positions[i].y;
		buffer[i * 6 + 2] = positions[i].z;
		
		if (i < diffuseColorsLength)
		{
			buffer[i * 6 + 3] = diffuseColors[i].x;
			buffer[i * 6 + 4] = diffuseColors[i].y;
			buffer[i * 6 + 5] = diffuseColors[i].z;
		}
		else
		{
			buffer[i * 6 + 3] = 0;
			buffer[i * 6 + 4] = 0;
			buffer[i * 6 + 5] = 0;
		}
	}
}

GLuint		ModelManager::loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec3> & diffuseColors)
{
	GLuint		vboID;
	GLuint		programID;
	GLuint		attribLocation;
	GLuint		dataLength;
	GLfloat *	data;

	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	dataLength = positions.size() * 6;
	data = new GLfloat[dataLength];
	fillVBO(data, positions, diffuseColors);
	glBufferData(GL_ARRAY_BUFFER, dataLength * sizeof(GLfloat), data, GL_STATIC_DRAW);
	delete[] data;

	programID = Graphics::shaderProgram->id;

	attribLocation = glGetAttribLocation(programID, "position");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);

	attribLocation = glGetAttribLocation(programID, "color");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));

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
	GLuint		iboID;
	GLuint *	data;
	size_t		dataLength;

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
	GLuint	vaoID;

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	return vaoID;
}

void		ModelManager::loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials)
{
	std::vector<Vec3>		positions;
	std::vector<Vec3>		diffuseColors;
	std::vector<unsigned>	indices;
	
	getModelData(positions, diffuseColors, indices, shapes, materials);
	model.indexCount = indices.size();
	model.vaoID = loadVAO();
	model.vboID = loadVBO(positions, diffuseColors);
	model.iboID = loadIBO(indices);

	glBindVertexArray(0);
}

Model &		ModelManager::loadFromOBJ(const std::string & objPath)
{
	std::string		error;
	ShapeList		shapes;
	MaterialList	materials;
	Model *			model;

	error = tinyobj::LoadObj(shapes, materials, objPath.c_str());

	if (error.empty() == false)
		throw std::runtime_error(error);

	model = new Model();

	loadBuffer(*model, shapes, materials);

	return *model;
}
