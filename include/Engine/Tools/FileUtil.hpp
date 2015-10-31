
#ifndef _FILE_UTIL_HPP
# define _FILE_UTIL_HPP

# include <string>

class FileUtil
{
	static std::string		previousWorkingDirectory;

public:
	static void		chdir(const std::string & path);
	static char *	getcwd(char *buffer, size_t size);
	static void		changeWorkingDirectory(const std::string & wd);
	static void		restoreWorkingDirectory();
};

#endif /* _FILE_UTIL_HPP */
