//             .-'''''-.
//           .'         `.
//          :             :   File       : Game.hpp
//         :               :  Creation   : 2015-10-17 08:06:59
//         :      _/|      :  Last Edit  : 2015-10-17 08:12:29
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _GAME_HPP
# define _GAME_HPP

# include "Engine/Core/Application.hpp"

class Game : public Application
{
public:
	Game();

	void	init();

private:
	void			_registerStates();
};

#endif /* _GAME_HPP */
