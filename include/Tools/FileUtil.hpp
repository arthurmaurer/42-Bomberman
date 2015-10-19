
#ifndef _FILE_UTIL_H
# define _FILE_UTIL_H

# include <string>

class FileUtil
{
	static std::string		previousWorkingDirectory;

public:
	static void		changeWorkingDirectory(const std::string & wd);
	static void		restoreWorkingDirectory();
};

#endif
