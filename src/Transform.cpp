
#include "Transform.hpp"

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

	// TODO: += & ... operators
	transform.position = transform.position + rhs.position;
	transform.scale = transform.scale * rhs.scale;
	transform.rotation = transform.rotation * rhs.rotation;

	return transform;
}
