
#ifndef _DEFAULT_PROGRAM_HPP
# define _DEFAULT_PROGRAM_HPP

# include "Graphics/ShaderProgram.hpp"

class DefaultProgram : public ShaderProgram
{
public:
	DefaultProgram();

	void	getUniformLocations();
};

#endif /* _DEFAULT_PROGRAM_HPP */
