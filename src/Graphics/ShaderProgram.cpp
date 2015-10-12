
#include "graphics/ShaderProgram.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShaderProgram::ShaderProgram()
{}

ShaderProgram::ShaderProgram(const std::string & vertexPath, const std::string & fragmentPath)
{
	load(vertexPath, fragmentPath);
}

ShaderProgram::~ShaderProgram()
{
	cleanUp();
}

void	ShaderProgram::load(const std::string & vertexPath, const std::string & fragmentPath)
{
	Shader		vertexShader(vertexPath, GL_VERTEX_SHADER);
	Shader		fragmentShader(fragmentPath, GL_FRAGMENT_SHADER);
	GLint		success;
	GLint		logLength;
	GLchar *	log = NULL;

	if (id == 0)
		id = glCreateProgram();

	if (id == 0)
		throw std::runtime_error("Could not create the program.");

	glAttachShader(id, vertexShader.id);
	glAttachShader(id, fragmentShader.id);
	glBindFragDataLocation(id, 0, "outColor");
	glLinkProgram(id);
	glValidateProgram(id);
	glDetachShader(id, vertexShader.id);
	glDetachShader(id, fragmentShader.id);
	glDeleteShader(vertexShader.id);
	glDeleteShader(fragmentShader.id);

	glGetProgramiv(id, GL_LINK_STATUS, &success);

	if (success == GL_FALSE)
	{
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
		glGetProgramInfoLog(id, logLength, NULL, log);

		std::runtime_error	e(log);
		delete[] log;
		throw e;
	}
}

void	ShaderProgram::enable() const
{
	if (Graphics::shaderProgram != NULL)
		Graphics::shaderProgram->disable();

	Graphics::shaderProgram = this;
	glUseProgram(id);
}

void	ShaderProgram::disable() const
{
	if (Graphics::shaderProgram == this)
		Graphics::shaderProgram = NULL;

	glUseProgram(0);
}

void	ShaderProgram::bindAttribute(GLuint attribId, const std::string & attribName)
{
	glBindAttribLocation(id, attribId, attribName.c_str());
}

void	ShaderProgram::cleanUp()
{
	disable();

	if (id != 0)
		glDeleteProgram(id);
}

GLint	ShaderProgram::getUniformLocation(const std::string & name)
{
	uniforms[name] = glGetUniformLocation(id, name.c_str());
	
	return uniforms[name];
}

void	ShaderProgram::loadUniform(const std::string & name, GLfloat value) const
{
	glUniform1f(uniforms.at(name), value);
}

void	ShaderProgram::loadUniform(const std::string & name, GLint value) const
{
	glUniform1i(uniforms.at(name), value);
}

void	ShaderProgram::loadUniform(const std::string & name, bool value) const
{
	GLint	v = (value) ? 1 : 0;

	glUniform1i(uniforms.at(name), v);
}

void	ShaderProgram::loadUniform(const std::string & name, const Vec2 & value) const
{
	glUniform2f(uniforms.at(name), value.x, value.y);
}

void	ShaderProgram::loadUniform(const std::string & name, const Vec3 & value) const
{
	glUniform3f(uniforms.at(name), value.x, value.y, value.z);
}

void	ShaderProgram::loadUniform(const std::string & name, const Vec4 & value) const
{
	glUniform4f(uniforms.at(name), value.w, value.x, value.y, value.z);
}

void	ShaderProgram::loadUniform(const std::string & name, const Matrix4 & value) const
{
	glUniformMatrix4fv(uniforms.at(name), 1, GL_FALSE, value.data);
}
