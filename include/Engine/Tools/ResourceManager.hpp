//             .-'''''-.
//           .'         `.
//          :             :   File       : ResourceManager.hpp
//         :               :  Creation   : 2015-10-18 15:04:50
//         :      _/|      :  Last Edit  : 2015-10-22 08:01:20
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _RESOURCE_MANAGER_HPP
# define _RESOURCE_MANAGER_HPP

# include <ostream>
# include <memory>
# include <map>
# include <string>

template<typename Key, typename Resource>
class	ResourceManager
{

public:
	typedef std::unique_ptr<ResourceManager>	Ptr;
	typedef std::unique_ptr<Resource>			ResourcePtr;

	static Ptr		instance;

	virtual ~ResourceManager() {};

	static Resource &	load(const Key & key, const std::string & param = "");
	static void			unload(const Key & key);
	static void			clear();

protected:
	std::map<Key, ResourcePtr>			_resources;

	virtual	Resource &		_load(const Key & key, const std::string & param) = 0;
	virtual void			_unload(const Key & key) = 0;

	ResourceManager();
};

# include "ResourceManager.inl"

#endif /* _RESOURCE_MANAGER_HPP */
