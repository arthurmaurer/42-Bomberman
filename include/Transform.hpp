
#ifndef _TRANSFORM_H
# define _TRANSFORM_H

# include "Vec3.hpp"
# include "Quaternion.hpp"

class Transform
{
public:
	Vec3		position;
	Vec3		scale;
	Quaternion	rotation;

	Transform();
	Transform(const Transform & src);

	Transform &	operator=(const Transform & rhs);
	Transform	operator*(const Transform & rhs) const;
};

#endif
