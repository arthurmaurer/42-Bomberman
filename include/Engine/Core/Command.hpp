//             .-'''''-.
//           .'         `.
//          :             :   File       : Command.hpp
//         :               :  Creation   : 2015-10-05 05:37:14
//         :      _/|      :  Last Edit  : 2015-10-17 08:51:43
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _COMMAND_HPP
# define _COMMAND_HPP

# include <iostream>
# include <functional>
# include <cassert>

# include <SFML/System/Time.hpp>

class SceneNode;

struct		Command
{
	Command();

	std::function<void(SceneNode & node, sf::Time de)>	action;
	unsigned int										category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode &, sf::Time)> derivedAction(Function fn)
{
	return [=] (SceneNode & node, sf::Time dt)
	{
		assert(dynamic_cast<GameObject *>(&node) != nullptr);
		fn(static_cast<GameObject &>(node), dt);
	};
}

#endif /* _COMMAND_HPP */
