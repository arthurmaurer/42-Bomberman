#pragma once

#include "Vec3.hpp"

#ifndef M_PI
# define M_PI	3.14159265358979323846
#endif

class Quaternion
{
public:
	float	w;
	float	x;
	float	y;
	float	z;

	static Quaternion	identity;

	Quaternion();
	Quaternion(const Quaternion & src);
	Quaternion(float wVal, float xVal, float yVal, float zVal);

	Quaternion &	operator=(const Quaternion & rhs);
	Quaternion		operator*(const Quaternion & rhs) const;
	Vec3			operator*(const Vec3 & rhs) const;
	bool			operator==(const Quaternion & rhs) const;
	bool			operator!=(const Quaternion & rhs) const;

	void			set(float wVal, float xVal, float yVal, float zVal);
	float			getNorm() const;
	Vec3			getEulerAngles() const;
	void			setFromEulerAngles(const Vec3 & eulerAngles);
	void			rotateFromAxisAngle(const Vec3 & axis, float angle);
	void			setFromVector(const Vec3 & vector);
	void			rotateX(float angle);
	void			rotateY(float angle);
	void			rotateZ(float angle);
	Quaternion		normalize() const;
	Quaternion		conjugate() const;
	Quaternion		inverse() const;
};

std::ostream &		operator<<(std::ostream & os, const Quaternion & rhs);