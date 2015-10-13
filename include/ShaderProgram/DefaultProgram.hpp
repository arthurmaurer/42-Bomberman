#pragma once

#include "Graphics/ShaderProgram.hpp"

class DefaultProgram : public ShaderProgram
{
public:
	DefaultProgram();

	void	getUniformLocations();
};
