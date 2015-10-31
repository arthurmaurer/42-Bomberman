
#ifndef _MODEL_GENERATOR_HPP
# define _MODEL_GENERATOR_HPP

class Vec2;
class Vec3;
class Model;

class ModelGenerator
{
public:
	static Model &	generatePlane(const Vec2 & size);
	static Model &	generateCube(const Vec3 & size);
};

#endif /* _MODEL_GENERATOR_HPP */