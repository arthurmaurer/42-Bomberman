
#include "Utils/FileUtil.hpp"

#if _WIN32
#	include <direct.h>
#else
#	include <unistd.h>
#endif

std::string	FileUtil::previousWorkingDirectory = "";

void		FileUtil::changeWorkingDirectory(const std::string & wd)
{
	char	buffer[200] = { 0 };

#if _WIN32
	_getcwd(buffer, 200);
#else
	getcwd(buffer, 200);
#endif

	previousWorkingDirectory = buffer;

	_chdir(wd.c_str());
}

void		FileUtil::restoreWorkingDirectory()
{
	_chdir(previousWorkingDirectory.c_str());
	previousWorkingDirectory = "";
}