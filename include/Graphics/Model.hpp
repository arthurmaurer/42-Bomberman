#pragma once

#include <string>
#include <tiny_obj_loader.h>
#include <GL/glew.h>

class Model
{
public:
	std::vector<tinyobj::shape_t>		shapes;
	std::vector<tinyobj::material_t>	materials;
	GLuint		vertexCount = 0;
	GLuint		vboID = 0;
	GLuint		vaoID = 0;
	
	Model();
	~Model();

	void		load(const std::string & path);
	GLuint		getVertexCount() const;

	void		cleanUp();
};
