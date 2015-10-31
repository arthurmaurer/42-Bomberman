
#include <fstream>
#include <stdexcept>

#include "Engine/Graphics/Shader.hpp"

Shader::Shader(const std::string & path, GLenum type)
{
	load(path, type);
}

Shader::Shader()
{}

Shader::~Shader()
{
	if (id != 0)
		glDeleteShader(id);
}

void	Shader::load(const std::string & path, GLenum type)
{
	GLchar *		code;
	GLint			length;
	std::ifstream	file(path.c_str(), std::ios::binary);

	if (!file.good())
		throw std::runtime_error("Could not open the shader source.");

	file.seekg(0, file.end);
	length = static_cast<GLint>(file.tellg());
	file.seekg(0, file.beg);

	code = new char[length];
	file.read(code, length);

	if (id == 0)
		id = glCreateShader(type);

	if (id == 0)
		throw std::runtime_error("Could not create the shader.");

	glShaderSource(id, 1, (const char **)&code, &length);
	delete[] code;

	_compile();
}

void	Shader::_compile()
{
	GLint				success;
	GLint				logLength;
	GLchar *			log;

	glCompileShader(id);
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
		log = new char[logLength];
		glGetShaderInfoLog(id, logLength, NULL, log);
		std::runtime_error	e(log);
		delete[] log;
		throw e;
	}
}
