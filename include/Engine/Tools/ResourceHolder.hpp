//             .-'''''-.
//           .'         `.
//          :             :   File       : ResourceHolder.hpp
//         :               :  Creation   : 2015-10-31 23:24:47
//         :      _/|      :  Last Edit  : 2015-10-31 23:58:06
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _RESOURCE_HOLDER_HPP
# define _RESOURCE_HOLDER_HPP

# include <memory>
# include <ostream>
# include <unordered_map>

template<typename Key, typename Resource>
class ResourceHolder
{
public:
	ResourceHolder() = default;

	typedef Resource	ResourceType;
	typedef Key			KeyType;

protected:
	std::unordered_map<Key, std::unique_ptr<Resource>>	_resources;
};

#endif /* _RESOURCE_HOLDER_HPP */
