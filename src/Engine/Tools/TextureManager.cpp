//             .-'''''-.
//           .'         `.
//          :             :   File       : TextureManager.cpp
//         :               :  Creation   : 2015-10-19 01:07:09
//         :      _/|      :  Last Edit  : 2015-11-01 02:33:30
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <ostream>
#include <string.h>

#include <SFML/Graphics/Image.hpp>

#include "Engine/Graphics/ImageBuffer.hpp"
#include "Engine/Tools/TextureManager.hpp"
#include "Engine/Tools/FileUtil.hpp"
#include "Engine/Tools/MiscUtil.hpp"

using namespace Fothon;

ImageBuffer &	TextureManager::_loadImage(const std::string & path)
{
	bool			success = false;
	sf::Image		image;

	try
	{
		return *_cachedImages.at(path);
	}
	catch (std::out_of_range &)
	{
		FileUtil::changeWorkingDirectory("resources/");
		success = image.loadFromFile(path);
		FileUtil::restoreWorkingDirectory();

		if (!success)
			throw std::runtime_error("Could not load the texture file.");

		image.flipVertically();

		std::unique_ptr<ImageBuffer>	buffer(new ImageBuffer(image.getSize().x, image.getSize().y));
		memcpy(buffer->data, image.getPixelsPtr(), buffer->size);

		_cachedImages[path] = std::move(buffer);
		return *_cachedImages.at(path);
	}
}

void		TextureManager::_unloadGLTexture(const Texture & texture)
{
	std::vector<GLuint>::iterator	it;

	it = std::find(_texturesID.begin(), _texturesID.end(), texture.id);

	if (it != _texturesID.end())
	{
		glDeleteTextures(1, &texture.id);
		_texturesID.erase(it);
	}
}

void		TextureManager::clearCache()
{
	_cachedImages.clear();
}

void		TextureManager::cleanUp()
{
	size_t	size;

	size = _texturesID.size();

	if (size > 0)
	{
		glDeleteTextures(size, &_texturesID[0]);
		_texturesID.clear();
	}

	clearCache();
}

GLuint		TextureManager::_loadGLTexture(const ImageBuffer & imageBuffer)
{
	GLuint	textureID;

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

	return textureID;
}

Texture &	TextureManager::load(const std::string & key, const std::string & param)
{
	try
	{
		return *_resources.at(key);
	}
	catch (std::out_of_range &)
	{
		ImageBuffer &	imageBuffer = _loadImage(param);
		GLuint			textureID = _loadGLTexture(imageBuffer);

		_texturesID.push_back(textureID);

		std::unique_ptr<Texture>	texture(new Texture(textureID));
		_resources[key] = std::move(texture);

		return *_resources.at(key);
	}
}

void		TextureManager::unload(const std::string & key)
{
	Texture & texture = *_resources.at(key);
	_unloadGLTexture(texture);
	_resources.erase(key);
}
