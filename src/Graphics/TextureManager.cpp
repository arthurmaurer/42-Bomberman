
#include "Graphics/TextureManager.hpp"
#include <SFML/Graphics.hpp>
#include "Utils/FileUtil.hpp"

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

	texture = new Texture(textureID);

	return *texture;
}
