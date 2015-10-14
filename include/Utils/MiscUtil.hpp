#pragma once

#include <string>

class MiscUtil
{
public:
	static void		abort(const std::string & message, int exitValue = EXIT_SUCCESS);
};
