
#ifndef _MISC_UTIL_H
# define _MISC_UTIL_H

# include <string>

class MiscUtil
{
public:
	static void		abort(const std::string & message, int exitValue = EXIT_SUCCESS);
};

#endif
