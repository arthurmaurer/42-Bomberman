
#include <iostream>

#include "Engine/Graphics/DefaultProgram.hpp"

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
	getUniformLocation("modelMatrix");
	getUniformLocation("viewMatrix");
	getUniformLocation("normalMatrix");
	getUniformLocation("viewMatrix");

	for (unsigned i = 0; i < maxRenderedLights; i++)
	{
		name.clear();
		name.append("lights[").append(std::to_string(i)).append("].");

		getUniformLocation(name + "type");
		getUniformLocation(name + "position");
		getUniformLocation(name + "ambient");
		getUniformLocation(name + "diffuse");
		getUniformLocation(name + "specular");
		getUniformLocation(name + "attenuation");
	}
}
