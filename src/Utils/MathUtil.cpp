
#include "Utils/MathUtil.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

#ifndef M_PI
# define M_PI	3.14159265358979323846
#endif

bool	MathUtil::randSeedSet = false;

float	MathUtil::degToRad(float deg)
{
	return (deg * (static_cast<float>(M_PI) / 180.0f));
}

float		MathUtil::random(float min, float max, float precision)
{
	float	r;
	float	invPrecision = 1.f / precision;

	if (!randSeedSet)
	{
		randSeedSet = true;
		srand(static_cast<unsigned>(time(NULL)));
	}

	r = static_cast<float>(rand()) / invPrecision;
	r = fmodf(r, (max - min));
	r += min;
	r = std::trunc(invPrecision * r) / invPrecision;

	return r;
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
