
#ifndef _MISC_UTIL_HPP
# define _MISC_UTIL_HPP

# include <string>

class MiscUtil
{
public:
	static void		abort(const std::string & message, int exitValue = EXIT_SUCCESS);
};

#endif /* _MISC_UTIL_HPP */
