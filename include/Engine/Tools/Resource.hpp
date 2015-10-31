//             .-'''''-.
//           .'         `.
//          :             :   File       : Resource.hpp
//         :               :  Creation   : 2015-10-31 23:38:44
//         :      _/|      :  Last Edit  : 2015-11-01 00:09:30
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _RESOURCE_HPP
# define _RESOURCE_HPP

# include <tuple>
# include <ostream>

# include "Engine/Tools/TextureManager.hpp"

class Resource
{
	typedef std::tuple<TextureManager>	ResourceTuple;

	static ResourceTuple	_tuple;

public:
	template<typename ResourceHolder, typename... Args>
	static typename ResourceHolder::ResourceType &	load(const typename ResourceHolder::KeyType &, Args... args);

	template<typename ResourceHolder, typename... Args>
	void	unload(const typename ResourceHolder::KeyType &, Args... args);
};

# include "Resource.inl"

#endif /* _RESOURCE_HPP */
