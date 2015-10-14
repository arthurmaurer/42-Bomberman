#pragma once

class MathUtil
{
	static bool			randSeedSet;

public:
	static float	degToRad(float deg);

	static float	random(float min, float max);
	static int		random(int min, int max);
};
