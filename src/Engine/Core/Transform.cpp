
#include <cmath>

#include "Engine/Core/Transform.hpp"

Transform::Transform() :
	scale(Vec3(1.f, 1.f, 1.f))
{
}

Transform::Transform(const Transform & src) :
	position(src.position),
	scale(src.scale),
	rotation(src.rotation)
{
}

Transform &		Transform::operator=(const Transform & rhs)
{
	if (&rhs == this)
		return *this;

	position = rhs.position;
	scale = rhs.scale;
	rotation = rhs.rotation;

	return *this;
}

Transform		Transform::operator*(const Transform & rhs) const
{
	Transform	transform(*this);

	transform.rotateAround(rhs.position, rhs.rotation);

	return transform;
}

Transform &		Transform::operator*=(const Transform & rhs)
{
	(void)rhs;
	return *this;
}

void	Transform::rotateAround(const Vec3 & center, const Vec3 & eulerAngles)
{
	float		sinx = sinf(eulerAngles.x);
	float		siny = sinf(eulerAngles.y);
	float		sinz = sinf(eulerAngles.z);
	float		cosx = cosf(eulerAngles.x);
	float		cosy = cosf(eulerAngles.y);
	float		cosz = cosf(eulerAngles.z);
	float		tmp;

	tmp = position.y * cosx - position.z * sinx;
	position.z = position.y * sinx + position.z * cosx;
	position.y = tmp;

	tmp = position.x * cosy + position.z * siny;
	position.z = position.z * cosy - position.x * siny;
	position.x = tmp;

	tmp = position.x * cosz - position.y * sinz;
	position.y = position.x * sinz + position.y * cosz;
	position.x = tmp;

	rotation = rotation * Quaternion(eulerAngles);
	position += center;
}

void	Transform::rotateAround(const Vec3 & center, const Quaternion & quat)
{
	rotateAround(center, quat.getEulerAngles());
}
