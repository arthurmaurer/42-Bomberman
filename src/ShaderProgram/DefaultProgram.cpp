
#include "ShaderProgram/DefaultProgram.hpp"

DefaultProgram::DefaultProgram() :
	ShaderProgram("shader/vertex", "shader/fragment")
{
	getUniformLocations();
	bindAttributes();
}

void	DefaultProgram::getUniformLocations()
{
	getUniformLocation("mvp");
}

void	DefaultProgram::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "color");
}
