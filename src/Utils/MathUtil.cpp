
#include "Utils/MathUtil.hpp"
#include <cmath>

#ifndef M_PI
# define M_PI	3.14159265358979323846
#endif

float	MathUtil::degToRad(float deg)
{
	return (deg * (static_cast<float>(M_PI) / 180.0f));
}
