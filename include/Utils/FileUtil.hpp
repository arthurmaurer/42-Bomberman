#pragma once

#include <string>

class FileUtil
{
	static std::string		previousWorkingDirectory;

public:
	static void		changeWorkingDirectory(const std::string & wd);
	static void		restoreWorkingDirectory();
};
