
#include "ShaderProgram/DefaultProgram.hpp"
#include <iostream>

DefaultProgram::DefaultProgram() :
	ShaderProgram("shader/per_pixel.vertex.glsl", "shader/per_pixel.fragment.glsl")
{
	maxRenderedLights = 3;
	getUniformLocations();
}

void	DefaultProgram::getUniformLocations()
{
	std::string		name;

	getUniformLocation("mvp");
	getUniformLocation("modelViewMatrix");
	getUniformLocation("normalMatrix");

	for (unsigned i = 0; i < maxRenderedLights; i++)
	{
		name.clear();
		name.append("light[").append(std::to_string(i)).append("].");

		getUniformLocation(name + "position");
		getUniformLocation(name + "ambient");
		getUniformLocation(name + "diffuse");
		getUniformLocation(name + "specular");
		getUniformLocation(name + "attenuation");
	}
}
