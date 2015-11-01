
#ifndef _SFML_TEXTURE_MANAGER_HPP
# define _SFML_TEXTURE_MANAGER_HPP

# include <string>

# include <SFML/Graphics/Texture.hpp>

# include "Engine/Tools/ResourceHolder.hpp"

namespace Fothon
{
	class SFMLTextureManager : public ResourceHolder<std::string, sf::Texture>
	{
	public:
		void			unload(const std::string & key);
		sf::Texture &	load(const std::string & key, const std::string & path = "");
	};
}

#endif /* _SFML_TEXTURE_MANAGER_HPP */
