
#ifndef _MODEL_HPP
# define _MODEL_HPP

# include <memory>
# include <cstdlib>
# include <GL/glew.h>

class Texture;

class Model
{
public:
	typedef std::unique_ptr<Model>	Ptr;

	GLuint			indexCount = 0;
	GLuint			vboID = 0;
	GLuint			vaoID = 0;
	GLuint			iboID = 0;
	const Texture *	texture = NULL;

	Model();
};

#endif /* _MODEL_HPP */
