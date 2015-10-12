
#include "Graphics\ModelManager.hpp"
#include "Graphics/Graphics.hpp"

void	ModelManager::fillDataBuffer(GLfloat * buffer, const ShapeList & shapes, const MaterialList & materials)
{
	unsigned int	i = 0;

	for (const auto & shape : shapes)
	{
		for (unsigned indice : shape.mesh.indices)
		{
			buffer[i] = shape.mesh.positions[indice * 3];
			buffer[i + 1] = shape.mesh.positions[indice * 3 + 1];
			buffer[i + 2] = shape.mesh.positions[indice * 3 + 2];

			const tinyobj::material_t &	material = materials[shape.mesh.material_ids[0]];
			buffer[i + 3] = material.diffuse[0];
			buffer[i + 4] = material.diffuse[1];
			buffer[i + 5] = material.diffuse[2];
			i += 6;
		}
	}
}

void		ModelManager::loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials)
{
	size_t		dataLength;
	GLfloat *	data;
	GLuint		attribLocation;
	GLuint		programID;

	glGenVertexArrays(1, &model.vaoID);
	glBindVertexArray(model.vaoID);

	glGenBuffers(1, &model.vboID);
	glBindBuffer(GL_ARRAY_BUFFER, model.vboID);

	dataLength = model.vertexCount * 6;
	data = new GLfloat[dataLength];
	fillDataBuffer(data, shapes, materials);
	glBufferData(GL_ARRAY_BUFFER, dataLength * sizeof(GLfloat), data, GL_STATIC_DRAW);
	delete[] data;

	programID = Graphics::shaderProgram->id;

	attribLocation = glGetAttribLocation(programID, "position");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);

	attribLocation = glGetAttribLocation(programID, "color");
	glEnableVertexAttribArray(attribLocation);
	glVertexAttribPointer(attribLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));

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
	model->vertexCount = 0;

	for (const auto & shape : shapes)
		model->vertexCount += shape.mesh.indices.size();

	loadBuffer(*model, shapes, materials);

	return *model;
}
