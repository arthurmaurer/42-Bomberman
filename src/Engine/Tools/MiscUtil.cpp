
#include <iostream>

#include "Engine/Tools/MiscUtil.hpp"

void	MiscUtil::abort(const std::string & message, int exitValue)
{
	std::cout << message << std::endl;
	exit(exitValue);
}
