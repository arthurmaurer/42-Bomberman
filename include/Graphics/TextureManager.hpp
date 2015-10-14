#pragma once

#include "Graphics/Texture.hpp"
#include <string>
#include <vector>
class TextureManager
{
	static std::vector<GLuint>	textures;

public:
	static Texture &	loadTexture(const std::string & path);
	static void			unloadTexture(const Texture & texture);
	static void			cleanUp();
};
