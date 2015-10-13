
#include "graphics/Model.hpp"

Model::Model()
{}

Model::~Model()
{
	cleanUp();
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

	if (iboID != 0)
	{
		glDeleteVertexArrays(1, &iboID);
		iboID = 0;
	}
}
