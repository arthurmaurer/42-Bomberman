#pragma once

#include "Graphics/Texture.hpp"
#include <string>

class TextureManager
{
public:
	static Texture &	loadTexture(const std::string & path);
};
