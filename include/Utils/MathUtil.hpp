
#ifndef _MATH_UTIL_H
# define _MATH_UTIL_H

class MathUtil
{
	static bool			randSeedSet;

public:
	static float	rad(float deg);
	static float	deg(float rad);

	static float	random(float min, float max);
	static int		random(int min, int max);
	static float	clamp(float value, float min, float max);
};

#endif
