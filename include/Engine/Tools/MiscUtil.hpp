
#ifndef _MISC_UTIL_H
# define _MISC_UTIL_H

# include <map>
# include <string>

class MiscUtil
{
public:
	static void		abort(const std::string & message, int exitValue = EXIT_SUCCESS);

	template<typename K, typename V>
	static K	mapFindKeyByValue(const std::map<K, V> map, const V & value);
};

template<typename K, typename V>
inline K	MiscUtil::mapFindKeyByValue(const std::map<K, V> map, const V & value)
{
	for (auto & kv : map)
	{
		if (kv.second == value)
			return kv.first;
	}
	return K();
}

#endif
