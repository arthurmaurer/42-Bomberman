//             .-'''''-.
//           .'         `.
//          :             :   File       : Command.cpp
//         :               :  Creation   : 2015-10-05 06:12:23
//         :      _/|      :  Last Edit  : 2015-10-17 08:54:13
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <ostream>

#include "Engine/Core/Command.hpp"
#include "Game/Category.hpp"

Command::Command() :
	action(),
	category(Category::None)
{}
