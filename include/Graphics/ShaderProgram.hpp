#pragma once

#include <string>
#include <GL/glew.h>
#include <map>
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"
#include "Matrix4.hpp"

class ShaderProgram
{
public:
	GLuint							id = 0;
	GLuint							vao;
	std::map<std::string, GLint>	uniforms;

	ShaderProgram();
	ShaderProgram(const std::string & vertexPath, const std::string & fragmentPath);
	~ShaderProgram();

	void			load(const std::string & vertexPath, const std::string & fragmentPath);
	void			cleanUp();

	GLint			getUniformLocation(const std::string & name);
	void			loadUniform(const std::string & name, GLfloat value) const;
	void			loadUniform(const std::string & name, GLint value) const;
	void			loadUniform(const std::string & name, bool value) const;
	void			loadUniform(const std::string & name, const Vec2 & value) const;
	void			loadUniform(const std::string & name, const Vec3 & value) const;
	void			loadUniform(const std::string & name, const Vec4 & value) const;
	void			loadUniform(const std::string & name, const Matrix4 & value) const;
	virtual void	getUniformLocations() = 0;

	virtual void	bindAttributes() = 0;
	void			bindAttribute(GLuint attribId, const std::string & attribName);

	void			enable() const;
	void			disable() const;
};
