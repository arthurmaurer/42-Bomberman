
#include "Utils/MathUtil.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

#ifndef M_PI
# define M_PI	3.14159265358979323846
#endif

bool	MathUtil::randSeedSet = false;

float	MathUtil::rad(float deg)
{
	return (deg * (static_cast<float>(M_PI) / 180.f));
}

float	MathUtil::deg(float rad)
{
	return ((rad * 180.f) / static_cast<float>(M_PI));
}

float		MathUtil::random(float min, float max)
{
	float	random;
	float	diff;
	float	result;
	
	random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	diff = max - min;
	result = random * diff + min;

	return result;
}

int		MathUtil::random(int min, int max)
{
	if (!randSeedSet)
	{
		randSeedSet = true;
		srand(static_cast<unsigned>(time(NULL)));
	}

	return (rand() % (max - min) + min);
}

float	MathUtil::clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;

	return value;
}
