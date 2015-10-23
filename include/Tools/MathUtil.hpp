
#ifndef _MATH_UTIL_HPP
# define _MATH_UTIL_HPP

#ifndef M_PI
# define M_PI	3.14159265358979323846
#endif

#ifndef M_PI_2
# define M_PI_2	1.57079632679489661923
#endif

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
