
#include "graphics/Model.hpp"

Model::Model()
{}

Model::~Model()
{
	cleanUp();
}

void	Model::load(const std::string & path)
{
	std::string		error;
	
	error = tinyobj::LoadObj(shapes, materials, path.c_str());

	if (error.empty() == false)
		throw std::runtime_error(error);

	vertexCount = getVertexCount();
}

GLuint	Model::getVertexCount() const
{
	GLuint	count = 0;

	for (const auto & shape : shapes)
		count += shape.mesh.indices.size();

	return count;
}

void	Model::cleanUp()
{
	if (vboID != 0)
	{
		glDeleteBuffers(1, &vboID);
		vboID = 0;
	}

	if (vaoID != 0)
	{
		glDeleteVertexArrays(1, &vaoID);
		vaoID = 0;
	}
}
