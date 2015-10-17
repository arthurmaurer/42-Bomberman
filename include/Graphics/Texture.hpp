
#ifndef _TEXTURE_H
# define _TEXTURE_H

# include <GL/glew.h>

class Texture
{
public:
	const GLuint	id = 0;

	Texture(GLuint id);
	~Texture();
};

#endif
