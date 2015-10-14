
#include "Graphics/TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include "Utils/FileUtil.hpp"
#include <algorithm>

std::vector<GLuint>	TextureManager::textures;

Texture &	TextureManager::loadTexture(const std::string & path)
{
	GLuint		textureID;
	Texture *	texture = NULL;
	sf::Image	image;

	FileUtil::changeWorkingDirectory("resources/");

	if (image.loadFromFile(path) == false)
		throw std::runtime_error("Could not load the texture file.");

	FileUtil::restoreWorkingDirectory();

	image.flipVertically();
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		image.getSize().x,
		image.getSize().y, 0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		image.getPixelsPtr()
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	textures.push_back(textureID);
	texture = new Texture(textureID);

	return *texture;
}

void		TextureManager::unloadTexture(const Texture & texture)
{
	std::vector<GLuint>::const_iterator	it;

	it = std::find(textures.cbegin(), textures.cend(), texture.id);

	if (it != textures.cend())
	{
		glDeleteTextures(1, &texture.id);
		textures.erase(it);
	}
}

void		TextureManager::cleanUp()
{
	size_t	size;

	size = textures.size();

	if (size > 0)
	{
		glDeleteTextures(size, &textures[0]);
		textures.clear();
	}
}
