
#include "Graphics/TextureManager.hpp"
#include "Utils/FileUtil.hpp"
#include <algorithm>
#include <memory>

std::vector<GLuint>					TextureManager::_textures;
std::map<std::string, sf::Image *>	TextureManager::_cachedImages;

sf::Image &	TextureManager::_loadImage(const std::string & path)
{
	bool						success = false;
	sf::Image *					image = NULL;

	image = _cachedImages[path];

	if (image == NULL)
	{
		image = new sf::Image();
		FileUtil::changeWorkingDirectory("resources/");
		success = image->loadFromFile(path);
		FileUtil::restoreWorkingDirectory();

		if (!success)
		{
			free(image);
			throw std::runtime_error("Could not load the texture file.");
		}

		image->flipVertically();
		_cachedImages[path] = image;
	}

	return *image;
}

Texture &	TextureManager::loadTexture(const std::string & path)
{
	GLuint		textureID;
	Texture *	texture = NULL;
	sf::Image &	image = _loadImage(path);

	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		image.getSize().x,
		image.getSize().y,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		image.getPixelsPtr()
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	_textures.push_back(textureID);
	texture = new Texture(textureID);

	return *texture;
}

void		TextureManager::unloadTexture(const Texture & texture)
{
	std::vector<GLuint>::const_iterator	it;

	it = std::find(_textures.cbegin(), _textures.cend(), texture.id);

	if (it != _textures.cend())
	{
		glDeleteTextures(1, &texture.id);
		_textures.erase(it);
	}
}

void		TextureManager::deleteCache()
{
	for (std::pair<std::string, sf::Image *> image : _cachedImages)
		free(image.second);

	_cachedImages.clear();
}

void		TextureManager::cleanUp()
{
	size_t	size;

	size = _textures.size();

	if (size > 0)
	{
		glDeleteTextures(size, &_textures[0]);
		_textures.clear();
	}

	deleteCache();
}
