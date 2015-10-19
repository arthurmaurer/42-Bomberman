//             .-'''''-.
//           .'         `.
//          :             :   File       : ResourceManager.inl
//         :               :  Creation   : 2015-10-19 00:23:36
//         :      _/|      :  Last Edit  : 2015-10-19 02:33:41
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _RESOURCE_MANAGER_INL
# define _RESOURCE_MANAGER_INL

# include <cassert>

template<typename Key, typename Resource>
typename ResourceManager<Key, Resource>::Ptr	ResourceManager<Key, Resource>::instance = nullptr;

template<typename Key, typename Resource>
ResourceManager<Key, Resource>::ResourceManager() :
	_resources()
{

}

template<typename Key, typename Resource>
Resource &	ResourceManager<Key, Resource>::load(const Key & key, const std::string & param)
{
	assert(instance != nullptr);
	return instance->_load(key, param);
}

template<typename Key, typename Resource>
void	ResourceManager<Key, Resource>::unload(const Key & key)
{
	assert(instance != nullptr);
	instance->_unload(key);
}

/*template<typename Key, typename Resource>
void	ResourceManager<Key, Resource>::unload(const Resource & res)
{
	init();
	instance->_unload(res);
}*/

#endif /* _RESOURCE_MANAGER_INL */
