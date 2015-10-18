
#ifndef _MATRIX4_HPP
# define _MATRIX4_HPP

# include "Quaternion.hpp"
# include "Transform.hpp"
# include "Vec3.hpp"
# include <iostream>

class Matrix4
{
public:
	float	data[16];

	Matrix4();
	Matrix4(const Matrix4 & src);
	Matrix4(const Quaternion & quat);

	Matrix4 &	operator=(const Matrix4 & rhs);
	Matrix4		operator*(const Matrix4 & rhs) const;
	Matrix4 &	operator*=(const Matrix4 & rhs);
	
	Matrix4		translate(const Vec3 & amount) const;

	Matrix4		scale(const Vec3 & amount) const;
	Matrix4		scale(float amount) const;
	Matrix4		scale(float amountX, float amountY, float amountZ) const;

	Matrix4		rotate(const Quaternion & amount);
	Matrix4		rotateX(float amount) const;
	Matrix4		rotateY(float amount) const;
	Matrix4		rotateZ(float amount) const;

	static Matrix4	getPerspective(float fov, float aspect, float nearPlane, float farPlane);

	void		setIdentity();
	void		setFromQuaternion(const Quaternion & quat);
	void		setFromTransform(const Transform & trans);
	void		setFromInversedTransform(const Transform & trans);
};

std::ostream &	operator<<(std::ostream & os, const Matrix4 & rhs);

#endif /* _MATRIX4_HPP */
