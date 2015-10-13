#pragma once

class MathUtil
{
	static bool			randSeedSet;

public:
	static float	degToRad(float deg);

	static float	random(float min, float max, float precision = 1.f);
	static int		random(int min, int max);
};
