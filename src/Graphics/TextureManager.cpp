
#include "Graphics/TextureManager.hpp"
#include "Utils/FileUtil.hpp"
#include <algorithm>
#include <memory>

std::vector<GLuint>						TextureManager::_textures;
std::map<std::string, ImageBuffer *>	TextureManager::_cachedImages;

ImageBuffer &	TextureManager::_loadImage(const std::string & path)
{
	bool			success = false;
	sf::Image		image;
	ImageBuffer *	buffer = NULL;

	buffer = _cachedImages[path];

	if (buffer == NULL)
	{
		FileUtil::changeWorkingDirectory("resources/");
		success = image.loadFromFile(path);
		FileUtil::restoreWorkingDirectory();

		if (!success)
			throw std::runtime_error("Could not load the texture file.");

		image.flipVertically();

		buffer = new ImageBuffer(image.getSize().x, image.getSize().y);
		memcpy(buffer->data, image.getPixelsPtr(), buffer->size);

		_cachedImages[path] = buffer;
	}

	return *buffer;
}

Texture &	TextureManager::loadTexture(const std::string & path)
{
	GLuint			textureID = 0;
	Texture *		texture = NULL;
	ImageBuffer &	imageBuffer = _loadImage(path);

	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		imageBuffer.width,
		imageBuffer.height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		imageBuffer.data
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

void		TextureManager::clearCache()
{
	for (std::pair<std::string, ImageBuffer *> image : _cachedImages)
		delete image.second;

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

	clearCache();
}
