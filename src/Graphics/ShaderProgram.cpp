
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

void	ShaderProgram::loadUniform(const std::string & name, GLfloat * buffer, size_t length) const
{
	glUniform1fv(uniforms.at(name), length, buffer);
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

void	ShaderProgram::loadUniform(const std::string & name, const Vec2 & vec) const
{
	glUniform2f(uniforms.at(name), vec.x, vec.y);
}

void	ShaderProgram::loadUniform(const std::string & name, const Vec3 & vec) const
{
	glUniform3f(uniforms.at(name), vec.x, vec.y, vec.z);
}

void	ShaderProgram::loadUniform(const std::string & name, const Vec4 & vec) const
{
	glUniform4f(uniforms.at(name), vec.w, vec.x, vec.y, vec.z);
}

void	ShaderProgram::loadUniform(const std::string & name, const Matrix4 & matrix) const
{
	glUniformMatrix4fv(uniforms.at(name), 1, GL_FALSE, matrix.data);
}

void	ShaderProgram::loadUniform(const std::string & name, const Light & light, int index) const
{
	std::string	fullName(name);

	if (index != -1)
		fullName.append("[").append(std::to_string(index)).append("]");

	loadUniform(fullName + ".position", light.transform.position);
	loadUniform(fullName + ".ambient", light.ambient);
	loadUniform(fullName + ".diffuse", light.diffuse);
	loadUniform(fullName + ".specular", light.specular);
	loadUniform(fullName + ".attenuation", light.attenuation);
}

void	ShaderProgram::loadNormalMatrixUniform(const std::string & name, const Matrix4 & matrix) const
{
	GLfloat		buffer[9] = {
		matrix.data[0], matrix.data[1], matrix.data[2],
		matrix.data[4], matrix.data[5], matrix.data[6],
		matrix.data[8], matrix.data[9], matrix.data[10]
	};

	glUniformMatrix3fv(uniforms.at(name), 1, GL_FALSE, buffer);
}
