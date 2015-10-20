
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
	void			loadUniform(const std::string & name, const Light & value) const;
	void			loadNormalMatrixUniform(const std::string & name, const Matrix4 & value) const;
	virtual void	getUniformLocations() = 0;

	void			enable() const;
	void			disable() const;
};

#endif /* _SHADER_PROGRAM_HPP */
