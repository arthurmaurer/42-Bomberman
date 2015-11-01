//             .-'''''-.
//           .'         `.
//          :             :   File       : FontManager.hpp
//         :               :  Creation   : 2015-11-01 01:06:46
//         :      _/|      :  Last Edit  : 2015-11-01 02:40:11
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _FONT_MANAGER_HPP
# define _FONT_MANAGER_HPP

# include <SFML/Graphics/Font.hpp>
# include <ostream>

# include "Engine/Tools/ResourceHolder.hpp"

namespace Fothon
{
	class		FontManager : public ResourceHolder<std::string, sf::Font>
	{
	public:
		sf::Font &	load(const std::string & key, const std::string & fontPath = "");
		void		unload(const std::string & key);

	private:
	};
}

#endif /* _FONT_MANAGER_HPP */
