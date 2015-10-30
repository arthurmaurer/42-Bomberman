#include <stdexcept>

#include "Tools/FileUtil.hpp"

#if _WIN32
#	include <direct.h>
#else
#	include <unistd.h>
#endif

std::string	FileUtil::previousWorkingDirectory = "";

void		FileUtil::changeWorkingDirectory(const std::string & wd)
{
	char	buffer[200] = { 0 };

#ifdef _WIN32
	if (!_getcwd(buffer, 200))
		throw std::runtime_error("Current working directory path is too long.");
#else
	if (!getcwd(buffer, 200))
		throw std::runtime_error("Current working directory path is too long.");
#endif

	previousWorkingDirectory = buffer;

#ifdef _WIN32
	_chdir(wd.c_str());
#else
	chdir(wd.c_str());
#endif
}

void		FileUtil::restoreWorkingDirectory()
{
#ifdef _WIN32
	_chdir(previousWorkingDirectory.c_str());
#else
	chdir(previousWorkingDirectory.c_str());
#endif
	previousWorkingDirectory = "";
}
