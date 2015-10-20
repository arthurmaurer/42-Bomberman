
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Utils/MathUtil.hpp"
#include "Vec3.hpp"

bool	MathUtil::randSeedSet = false;

float	MathUtil::rad(float deg)
{
	return (deg * (static_cast<float>(M_PI) / 180.f));
}

Vec3	MathUtil::rad(const Vec3 & deg)
{
	return Vec3(rad(deg.x), rad(deg.y), rad(deg.z));
}

float	MathUtil::deg(float rad)
{
	return ((rad * 180.f) / static_cast<float>(M_PI));
}

Vec3	MathUtil::deg(const Vec3 & rad)
{
	return Vec3(deg(rad.x), deg(rad.y), deg(rad.z));
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
		return min;
	else if (value > max)
		return max;

	return value;
}
