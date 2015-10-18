//             .-'''''-.
//           .'         `.
//          :             :   File       : Category.hpp
//         :               :  Creation   : 2015-10-05 06:03:39
//         :      _/|      :  Last Edit  : 2015-10-17 08:53:09
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _CATEGORY_HPP
# define _CATEGORY_HPP

namespace	Category
{
	enum	Type
	{
		None			= 0,
		Scene			= 1 << 0,
		PlayerAircraft	= 1 << 1,
		AlliedAircraft	= 1 << 2,
		EnemyAircraft	= 1 << 3
	};
}

#endif /* _CATEGORY_HPP */
