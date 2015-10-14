#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "Graphics/Texture.hpp"
#include <iostream>

class TextureManager
{
	static std::vector<GLuint>					_textures;
	static std::map<std::string, sf::Image *>	_cachedImages;

	static sf::Image &	_loadImage(const std::string & path);

public:
	static Texture &	loadTexture(const std::string & path);
	static void			unloadTexture(const Texture & texture);
	static void			deleteCache();
	static void			cleanUp();
};
