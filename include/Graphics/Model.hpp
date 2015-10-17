
#ifndef _MODEL_H
# define _MODEL_H

# include <cstdlib>
# include <GL/glew.h>
# include "Graphics/Texture.hpp"

class Model
{
public:
	GLuint			indexCount = 0;
	GLuint			vboID = 0;
	GLuint			vaoID = 0;
	GLuint			iboID = 0;
	const Texture *	texture = NULL;
	
	Model();
};

#endif
