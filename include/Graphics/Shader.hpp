
#ifndef _SHADER_HPP
# define _SHADER_HPP

# include <string>
# include <GL/glew.h>

class Shader
{
	Shader(const Shader & src);

	Shader &	operator=(const Shader & rhs);

	void	_compile();

public:
	GLuint			id = 0;

	Shader();
	Shader(const std::string & path, GLenum type);
	~Shader();

	void	load(const std::string & path, GLenum type);
};

#endif /* _SHADER_HPP */
