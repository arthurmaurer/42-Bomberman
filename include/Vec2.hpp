#pragma once

#include <iostream>

class Vec2
{
public:
	float	x;
	float	y;

	static Vec2	zero;
	static Vec2	up;
	static Vec2	down;
	static Vec2	left;
	static Vec2	right;

	Vec2();
	Vec2(const Vec2 & src);
	Vec2(float x, float y);

	Vec2 &	operator=(const Vec2 & rhs);
	Vec2	operator+(const Vec2 & rhs) const;
	Vec2	operator-(const Vec2 & rhs) const;
	Vec2	operator*(float factor) const;
	Vec2	operator/(float factor) const;
	bool	operator==(const Vec2 & rhs) const;
	bool	operator!=(const Vec2 & rhs) const;

	void	set(float x, float y);
	bool	isNull() const;
	float	magnitude() const;
	Vec2	normalize() const;
	float	dot(const Vec2 & vec) const;
};

std::ostream &	operator<<(std::ostream & os, const Vec2 & rhs);
