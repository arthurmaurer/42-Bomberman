
#ifndef _TRANSFORM_HPP
# define _TRANSFORM_HPP

# include "Engine/Core/Vec3.hpp"
# include "Engine/Core/Quaternion.hpp"

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
	Transform &	operator*=(const Transform & rhs);

	void		rotateAround(const Vec3 & center, const Vec3 & eulerAngles);
	void		rotateAround(const Vec3 & center, const Quaternion & quat);
};

#endif /* _TRANSFORM_HPP */
