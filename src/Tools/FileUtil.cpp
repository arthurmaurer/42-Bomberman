#include <stdexcept>

#include "Tools/FileUtil.hpp"

#if _WIN32
#	include <direct.h>
#else
#	include <unistd.h>
#endif

std::string	FileUtil::previousWorkingDirectory = "";

void		FileUtil::chdir(const std::string & path)
{
	int		result;

#ifdef _WIN32
	result = _chdir(path.c_str());
#else
	result = chdir(path.c_str());
#endif

	if (result == -1)
		throw std::runtime_error("Failed to change the current directory.");
}

char *		FileUtil::getcwd(char * buffer, size_t size)
{
	char *	result;

#ifdef _WIN32
	result = _getcwd(buffer, size);
#else
	result = getcwd(buffer, size);
#endif

	if (result == NULL)
		throw std::runtime_error("The current working directory path is too long.");

	return result;
}

void		FileUtil::changeWorkingDirectory(const std::string & wd)
{
	char	buffer[200] = { 0 };

	getcwd(buffer, 200);
	previousWorkingDirectory = buffer;
	chdir(wd);
}

void		FileUtil::restoreWorkingDirectory()
{
	chdir(previousWorkingDirectory);
	previousWorkingDirectory = "";
}
