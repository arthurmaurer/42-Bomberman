
#include "Quaternion.hpp"
#include <cmath>

Quaternion	Quaternion::identity = Quaternion(0, 0, 0, 1.f);

Quaternion::Quaternion() :
	w(1.0f),
	x(0),
	y(0),
	z(0)
{
}

Quaternion::Quaternion(const Quaternion & src)
{
	*this = src;
}

Quaternion::Quaternion(float wVal, float xVal, float yVal, float zVal) :
	w(wVal),
	x(xVal),
	y(yVal),
	z(zVal)
{
}

Quaternion &	Quaternion::operator=(const Quaternion & rhs)
{
	if (&rhs == this)
		return *this;

	w = rhs.w;
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

Quaternion		Quaternion::operator*(const Quaternion & rhs) const
{
	Quaternion	quat;

	quat.w = w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z;
	quat.x = w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y;
	quat.y = w * rhs.y - x * rhs.z + y * rhs.w + z * rhs.x;
	quat.z = w * rhs.z + x * rhs.y - y * rhs.x + z * rhs.w;

	return quat;
}

Vec3			Quaternion::operator*(const Vec3 & rhs) const
{
	Quaternion	vec;

	vec.setFromVector(rhs);
	vec = *this * vec * inverse();

	return Vec3(vec.x, vec.y, vec.z);
}

bool			Quaternion::operator==(const Quaternion & rhs) const
{
	return (w == rhs.w && x == rhs.x && y == rhs.y && z == rhs.z);
}

bool			Quaternion::operator!=(const Quaternion & rhs) const
{
	return (w != rhs.w || x != rhs.x || y != rhs.y || z != rhs.z);
}

void			Quaternion::set(float w, float x, float y, float z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

float			Quaternion::getNorm() const
{
	return sqrt(w * w + x * x + y * y + z * z);
}

Vec3			Quaternion::getEulerAngles() const
{
	return Vec3();
}

void			Quaternion::setFromEulerAngles(const Vec3 & eulerAngles)
{
	Quaternion	quatX;
	Quaternion	quatY;
	Quaternion	quatZ;

	*this = identity;

	quatX.rotateFromAxisAngle(Vec3::right, eulerAngles.x);
	quatY.rotateFromAxisAngle(Vec3::up, eulerAngles.y);
	quatZ.rotateFromAxisAngle(Vec3::forward, eulerAngles.z);

	*this = quatX * quatY * quatZ;
}

void			Quaternion::rotateFromAxisAngle(const Vec3 & axis, float angle)
{
	Quaternion	quat;
	float		sinA;

	angle = angle / 360.0f * (float)M_PI * 2.f;

	sinA = sinf(angle / 2.0f);

	quat.x = axis.x * sinA;
	quat.y = axis.y * sinA;
	quat.z = axis.z * sinA;
	quat.w = cosf(angle / 2.0f);
	quat = quat.normalize();

	*this = *this * quat;
}

void Quaternion::setFromVector(const Vec3 & vector)
{
	w = 0;
	x = vector.x;
	y = vector.y;
	z = vector.z;
}

void Quaternion::rotateX(float angle)
{
	rotateFromAxisAngle(Vec3::right, angle);
}

void Quaternion::rotateY(float angle)
{
	rotateFromAxisAngle(Vec3::up, angle);
}

void Quaternion::rotateZ(float angle)
{
	rotateFromAxisAngle(Vec3::forward, angle);
}

Quaternion		Quaternion::normalize() const
{
	float	norm;

	norm = getNorm();
	return Quaternion(w / norm, x / norm, y / norm, z / norm);
}

Quaternion		Quaternion::conjugate() const
{
	return Quaternion(w, x * -1.0f, y * -1.0f, z * -1.0f);
}

Quaternion		Quaternion::inverse() const
{
	return Quaternion(w, -x, -y, -z);
}

std::ostream &	operator<<(std::ostream & os, const Quaternion & rhs)
{
	os
		<< "Quaternion("
		<< rhs.w << ", "
		<< rhs.x << ", "
		<< rhs.y << ", "
		<< rhs.z << ")"
		;

	return os;
}
