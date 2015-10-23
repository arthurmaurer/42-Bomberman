
#ifndef _FILE_UTIL_HPP
# define _FILE_UTIL_HPP

# include <string>

class FileUtil
{
	static std::string		previousWorkingDirectory;

public:
	static void		changeWorkingDirectory(const std::string & wd);
	static void		restoreWorkingDirectory();
};

#endif /* _FILE_UTIL_HPP */
