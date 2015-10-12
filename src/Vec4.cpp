
#include "Vec4.hpp"
#include <cmath>

Vec4::Vec4() :
	w(0),
	x(0),
	y(0),
	z(0)
{
}

Vec4::Vec4(const Vec4 & src)
{
	*this = src;
}

Vec4::Vec4(float wVal, float xVal, float yVal, float zVal) :
	w(wVal),
	x(xVal),
	y(yVal),
	z(zVal)
{
}

Vec4 &	Vec4::operator=(const Vec4 & rhs)
{
	if (this == &rhs)
		return *this;

	w = rhs.w;
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

Vec4	Vec4::operator+(const Vec4 & rhs) const
{
	Vec4	vec(*this);

	vec.w += rhs.w;
	vec.x += rhs.x;
	vec.y += rhs.y;
	vec.z += rhs.z;

	return vec;
}

Vec4	Vec4::operator-(const Vec4 & rhs) const
{
	Vec4	vec(*this);

	vec.w -= rhs.w;
	vec.x -= rhs.x;
	vec.y -= rhs.y;
	vec.z -= rhs.z;

	return vec;
}

Vec4	Vec4::operator*(float factor) const
{
	Vec4	vec(*this);

	vec.w *= factor;
	vec.x *= factor;
	vec.y *= factor;
	vec.z *= factor;

	return vec;
}

Vec4	Vec4::operator/(float factor) const
{
	Vec4	vec(*this);

	vec.w /= factor;
	vec.x /= factor;
	vec.y /= factor;
	vec.z /= factor;

	return vec;
}

bool	Vec4::operator==(const Vec4 & rhs) const
{
	return (w == rhs.w && x == rhs.x && y == rhs.y && z == rhs.z);
}

bool	Vec4::operator!=(const Vec4 & rhs) const
{
	return (w != rhs.w || x != rhs.x || y != rhs.y || z != rhs.z);
}

void	Vec4::set(float w, float x, float y, float z)
{
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

bool	Vec4::isNull() const
{
	return (w == 0 && x == 0 && y == 0 && z == 0);
}

std::ostream &	operator<<(std::ostream & os, const Vec4 & rhs)
{
	os
		<< "Vec4("
		<< rhs.w << ", "
		<< rhs.x << ", "
		<< rhs.y << ", "
		<< rhs.z << ")"
	;

	return os;
}
