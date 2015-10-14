
#include "Utils/MiscUtil.hpp"
#include <iostream>

void	MiscUtil::abort(const std::string & message, int exitValue)
{
	std::cout << message << std::endl;
	exit(exitValue);
}