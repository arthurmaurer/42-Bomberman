
#ifndef _TEXTURE_HPP
# define _TEXTURE_HPP

# include <memory>

# include <GL/glew.h>

namespace Fothon
{
	class Texture
	{
	public:
		const GLuint	id = 0;

		Texture(GLuint id);
		~Texture();
	};
}

#endif /* _TEXTURE_HPP */
