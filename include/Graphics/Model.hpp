#pragma once

#include <string>
#include <tiny_obj_loader.h>
#include <GL/glew.h>

class Model
{
public:
	GLuint		indexCount = 0;
	GLuint		vboID = 0;
	GLuint		vaoID = 0;
	GLuint		iboID = 0;
	
	Model();
	~Model();

	void		cleanUp();
};
