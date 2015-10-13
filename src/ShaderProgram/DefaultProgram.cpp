
#include "ShaderProgram/DefaultProgram.hpp"

DefaultProgram::DefaultProgram() :
	ShaderProgram("shader/vertex", "shader/fragment")
{
	getUniformLocations();
}

void	DefaultProgram::getUniformLocations()
{
	getUniformLocation("mvp");
}
