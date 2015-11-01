//             .-'''''-.
//           .'         `.
//          :             :   File       : Resource.inl
//         :               :  Creation   : 2015-10-31 23:45:34
//         :      _/|      :  Last Edit  : 2015-11-01 00:20:26
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _RESOURCE_INL
# define _RESOURCE_INL

# include "Engine/Tools/Resource.hpp"

namespace Fothon
{
	template<typename ResourceHolder, typename... Args>
	typename ResourceHolder::ResourceType &	Resource::load(const typename ResourceHolder::KeyType & key, Args... args)
	{
		return std::get<ResourceHolder>(_tuple).load(key, args...);
	}

	template<typename ResourceHolder, typename... Args>
	void	Resource::unload(const typename ResourceHolder::KeyType & key, Args... args)
	{
		return std::get<ResourceHolder>(_tuple).unload(key, args...);
	}
}

#endif /* _RESOURCE_INL	 */
