
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Shader.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/Light.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "Matrix4.hpp"

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
	if (Renderer::shaderProgram != NULL)
		Renderer::shaderProgram->disable();

	Renderer::shaderProgram = this;
	glUseProgram(id);
}

void	ShaderProgram::disable() const
{
	if (Renderer::shaderProgram == this)
		Renderer::shaderProgram = NULL;

	glUseProgram(0);
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

void	ShaderProgram::loadUniform(const std::string & name, const Light & value) const
{
	loadUniform(name + ".position", value.transform.position);
	loadUniform(name + ".ambient", value.ambient);
	loadUniform(name + ".diffuse", value.diffuse);
	loadUniform(name + ".specular", value.specular);
}

void	ShaderProgram::loadNormalMatrixUniform(const std::string & name, const Matrix4 & value) const
{
	GLfloat		buffer[9] = {
		value.data[0], value.data[1], value.data[2],
		value.data[4], value.data[5], value.data[6],
		value.data[8], value.data[9], value.data[10]
	};

	glUniformMatrix3fv(uniforms.at(name), 1, GL_FALSE, buffer);
}
