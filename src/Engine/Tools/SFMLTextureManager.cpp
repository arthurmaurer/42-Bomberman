
#include <cassert>

#include "Engine/Tools/SFMLTextureManager.hpp"
#include "Engine/Tools/FileUtil.hpp"

using namespace Fothon;

sf::Texture &	SFMLTextureManager::load(const std::string & key, const std::string & texturePath)
{
	try
	{
		return *_resources.at(key);
	}
	catch (std::out_of_range &)
	{
		std::unique_ptr<sf::Texture>	texture(new sf::Texture);

		FileUtil::changeWorkingDirectory("resources");

		if (!texture->loadFromFile(texturePath))
			throw std::runtime_error("SFMLTextureManager - Failed to load texture at " + texturePath);

		FileUtil::restoreWorkingDirectory();

		auto inserted = _resources.insert(std::make_pair(key, std::move(texture)));
		assert(inserted.second);
		return *_resources.at(key);
	}
}

void	SFMLTextureManager::unload(const std::string & key)
{
	_resources.erase(key);
}
