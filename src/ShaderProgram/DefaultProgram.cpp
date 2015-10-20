
#include "ShaderProgram/DefaultProgram.hpp"

DefaultProgram::DefaultProgram() :
	ShaderProgram("shader/per_pixel.vertex.glsl", "shader/per_pixel.fragment.glsl")
{
	getUniformLocations();
}

void	DefaultProgram::getUniformLocations()
{
	getUniformLocation("mvp");
	getUniformLocation("modelViewMatrix");
	getUniformLocation("normalMatrix");
	getUniformLocation("light.position");
	getUniformLocation("light.ambient");
	getUniformLocation("light.diffuse");
	getUniformLocation("light.specular");
}
