
#ifndef _SHADER_PROGRAM_HPP
# define _SHADER_PROGRAM_HPP

# include <map>
# include <string>

# include <GL/glew.h>

class Vec2;
class Vec3;
class Vec4;
class Matrix4;
class Light;

class ShaderProgram
{
public:
	GLuint							id = 0;
	GLuint							vao;
	std::map<std::string, GLint>	uniforms;
	unsigned						maxRenderedLights;

	ShaderProgram();
	ShaderProgram(const std::string & vertexPath, const std::string & fragmentPath);
	~ShaderProgram();

	void			load(const std::string & vertexPath, const std::string & fragmentPath);
	void			cleanUp();

	GLint			getUniformLocation(const std::string & name);
	void			loadUniform(const std::string & name, GLfloat value) const;
	void			loadUniform(const std::string & name, GLfloat * buffer, size_t length) const;
	void			loadUniform(const std::string & name, GLint value) const;
	void			loadUniform(const std::string & name, bool value) const;
	void			loadUniform(const std::string & name, const Vec2 & vec) const;
	void			loadUniform(const std::string & name, const Vec3 & vec) const;
	void			loadUniform(const std::string & name, const Vec4 & vec) const;
	void			loadUniform(const std::string & name, const Matrix4 & matrix) const;
	void			loadUniform(const std::string & name, const Light & light, int index = -1) const;
	void			loadNormalMatrixUniform(const std::string & name, const Matrix4 & matrix) const;
	virtual void	getUniformLocations() = 0;

	void			enable() const;
	void			disable() const;
};

#endif /* _SHADER_PROGRAM_HPP */
