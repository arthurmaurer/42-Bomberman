
#ifndef _MODEL_GENERATOR_HPP
# define _MODEL_GENERATOR_HPP

# include "Vec2.hpp"

class Model;

class ModelGenerator
{
public:
	static Model &	generatePlane(const Vec2 & size);
};

#endif /* _MODEL_GENERATOR_HPP */