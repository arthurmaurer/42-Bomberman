
#ifndef _MATRIX4_HPP
# define _MATRIX4_HPP

# include <iostream>

# include "Engine/Core/Quaternion.hpp"
# include "Engine/Core/Transform.hpp"
# include "Engine/Core/Vec3.hpp"

namespace Fothon
{
	class Matrix4
	{
	public:
		static Matrix4	zero;

		float	data[16];

		Matrix4();
		Matrix4(const Matrix4 & src);
		Matrix4(const Quaternion & quat);
		Matrix4(float d0, float d1, float d2, float d3, float d4, float d5,
			float d6, float d7, float d8, float d9, float d10, float d11, float d12,
			float d13, float d14, float d15);

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

		Matrix4		inverse() const;
		Matrix4		transpose() const;

		static Matrix4	getPerspective(float fov, float aspect, float nearPlane, float farPlane);

		void		setIdentity();
		void		setFromQuaternion(const Quaternion & quat);
		void		setFromTransform(const Transform & trans);
		void		setFromInversedTransform(const Transform & trans);
	};
}

std::ostream &	operator<<(std::ostream & os, const Fothon::Matrix4 & rhs);

#endif /* _MATRIX4_HPP */
