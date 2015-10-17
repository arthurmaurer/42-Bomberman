
#ifndef _DEFAULT_PROGRAM_H
# define _DEFAULT_PROGRAM_H

# include "Graphics/ShaderProgram.hpp"

class DefaultProgram : public ShaderProgram
{
public:
	DefaultProgram();

	void	getUniformLocations();
};

#endif
