//             .-'''''-.
//           .'         `.
//          :             :   File       : FontManager.cpp
//         :               :  Creation   : 2015-11-01 01:40:18
//         :      _/|      :  Last Edit  : 2015-11-01 02:03:00
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <ostream>
#include <cassert>
#include <SFML/Graphics/Font.hpp>

#include "Engine/Tools/FontManager.hpp"
#include "Engine/Tools/FileUtil.hpp"

sf::Font &	FontManager::load(const std::string & key, const std::string & fontPath)
{
	try
	{
		return *_resources.at(key);
	}
	catch (std::out_of_range &)
	{
		std::unique_ptr<sf::Font>	font(new sf::Font);

		FileUtil::changeWorkingDirectory("resources");

		if (!font->loadFromFile(fontPath))
			throw std::runtime_error("FontManager - Failed to load resource at " + fontPath);

		FileUtil::restoreWorkingDirectory();
		auto inserted = _resources.insert(std::make_pair(key, std::move(font)));
		assert(inserted.second);
		return *_resources.at(key);
	}
}

void	FontManager::unload(const std::string & key)
{
	_resources.erase(key);
}
