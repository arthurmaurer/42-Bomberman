
#ifndef _MATH_UTIL_HPP
# define _MATH_UTIL_HPP

class Vec3;

class MathUtil
{
	static bool			randSeedSet;

public:
	static float	rad(float deg);
	static Vec3		rad(const Vec3 & deg);
	static float	deg(float rad);
	static Vec3		deg(const Vec3 & rad);

	static float	random(float min, float max);
	static int		random(int min, int max);
	static float	clamp(float value, float min, float max);
};

#endif /* _MATH_UTIL_HPP */
