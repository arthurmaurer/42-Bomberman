
#include "Matrix4.hpp"
#include <cstring>
#include <iostream>

Matrix4::Matrix4()
{
	setIdentity();
}

Matrix4::Matrix4(const Matrix4 & src)
{
	*this = src;
}

Matrix4::Matrix4(const Quaternion & quat)
{
	setFromQuaternion(quat);
}

Matrix4 &	Matrix4::operator=(const Matrix4 & rhs)
{
	if (&rhs == this)
		return *this;

	memcpy(data, rhs.data, sizeof(data));
	return *this;
}

Matrix4		Matrix4::operator*(const Matrix4 & rhs) const
{
	Matrix4		result;
	unsigned	i;
	unsigned	j;

	i = 0;
	while (i < 16)
	{
		result.data[i] = 0;
		j = 0;
		while (j < 4)
		{
			result.data[i] += data[((i / 4) * 4 + j)] * rhs.data[(j * 4 + i % 4)];
			j++;
		}
		i++;
	}

	return result;
}

Matrix4 &	Matrix4::operator*=(const Matrix4 & rhs)
{
	if (&rhs == this)
		return *this;

	*this = *this * rhs;
	return *this;
}

Matrix4		Matrix4::translate(const Vec3 & amount) const
{
	Matrix4	trans;

	trans.data[3] = amount.x;
	trans.data[7] = amount.y;
	trans.data[11] = amount.z;

	return (*this * trans);
}

Matrix4		Matrix4::scale(const Vec3 & amount) const
{
	return scale(amount.x, amount.y, amount.z);
}

Matrix4		Matrix4::scale(float amount) const
{
	return scale(amount, amount, amount);
}

Matrix4		Matrix4::scale(float amountX, float amountY, float amountZ) const
{
	Matrix4	trans;

	trans.data[0] = amountX;
	trans.data[5] = amountY;
	trans.data[10] = amountZ;

	return (*this * trans);
}

Matrix4		Matrix4::rotateX(float amount) const
{
	Matrix4	rot;

	rot.data[5] = cosf(amount);
	rot.data[6] = sinf(amount) * -1;
	rot.data[9] = sinf(amount);
	rot.data[10] = cosf(amount);

	return (*this * rot);
}

Matrix4		Matrix4::rotateY(float amount) const
{
	Matrix4	rot;

	rot.data[0] = cosf(amount);
	rot.data[2] = sinf(amount);
	rot.data[8] = sinf(amount) * -1;
	rot.data[10] = cosf(amount);

	return (*this * rot);
}

Matrix4		Matrix4::rotateZ(float amount) const
{
	Matrix4	rot;

	rot.data[0] = cosf(amount);
	rot.data[1] = sinf(amount) * -1;
	rot.data[4] = sinf(amount);
	rot.data[5] = cosf(amount);

	return (*this * rot);
}

Matrix4 Matrix4::getPerspective(float fov, float aspect, float nearPlane, float farPlane)
{
	Matrix4	matrix;
	float	tanHalfFov;

	tanHalfFov = tanf(fov / 2.f);
	memset(matrix.data, 0, sizeof(matrix.data));
	matrix.data[0] = 1.f / (aspect * tanHalfFov);
	matrix.data[5] = 1.f / (tanHalfFov);
	matrix.data[10] = (farPlane + nearPlane) / (farPlane - nearPlane) * -1.f;
	matrix.data[11] = (2.f * farPlane * nearPlane) / (farPlane - nearPlane) * -1.f;
	matrix.data[14] = -1.f;

	return matrix;
}

void Matrix4::setIdentity()
{
	memset(data, 0, sizeof(data));
	data[0] = 1.0f;
	data[5] = 1.0f;
	data[10] = 1.0f;
	data[15] = 1.0f;
}

void Matrix4::setFromQuaternion(const Quaternion & quat)
{
	setIdentity();

	float xx = quat.x * quat.x;
	float xy = quat.x * quat.y;
	float xz = quat.x * quat.z;
	float xw = quat.x * quat.w;

	float yy = quat.y * quat.y;
	float yz = quat.y * quat.z;
	float yw = quat.y * quat.w;

	float zz = quat.z * quat.z;
	float zw = quat.z * quat.w;

	data[0] = 1.0f - 2.0f * (yy + zz);
	data[1] = 2.0f * (xy - zw);
	data[2] = 2.0f * (xz + yw);
	data[3] = 0;

	data[4] = 2.0f * (xy + zw);
	data[5] = 1.0f - 2.0f * (xx + zz);
	data[6] = 2.0f * (yz - xw);
	data[7] = 0;

	data[8] = 2.0f * (xz - yw);
	data[9] = 2.0f * (yz + xw);
	data[10] = 1.0f - 2.0f * (xx + yy);
	data[11] = 0;

	data[12] = 0;
	data[13] = 0;
	data[14] = 0;
	data[15] = 1.0f;
}

void	Matrix4::setFromTransform(const Transform & trans)
{
	setIdentity();
	*this *= scale(trans.scale);
	*this *= Matrix4(trans.rotation);
	*this *= translate(trans.position);
}

void	Matrix4::setFromInversedTransform(const Transform & trans)
{
	Vec3		inversedPosition;
	Vec3		inversedScale;
	Quaternion	inversedRotation;

	inversedPosition = trans.position * -1;

	inversedScale.x = 1.f / trans.scale.x;
	inversedScale.y = 1.f / trans.scale.y;
	inversedScale.z = 1.f / trans.scale.z;

	inversedRotation = trans.rotation.inverse();

	setIdentity();
	*this *= scale(inversedScale);
	*this *= Matrix4(inversedRotation);
	*this *= translate(inversedPosition);
}

std::ostream &	operator<<(std::ostream & os, const Matrix4 & rhs)
{
	os
		<< "Matrix4("
		<< rhs.data[0] << ", "
		<< rhs.data[1] << ", "
		<< rhs.data[2] << ", "
		<< rhs.data[3] << ", " << std::endl
		<< "        " << rhs.data[4] << ", "
		<< rhs.data[5] << ", "
		<< rhs.data[6] << ", "
		<< rhs.data[7] << ", " << std::endl
		<< "        " << rhs.data[8] << ", "
		<< rhs.data[9] << ", "
		<< rhs.data[10] << ", "
		<< rhs.data[11] << ", " << std::endl
		<< "        " << rhs.data[12] << ", "
		<< rhs.data[13] << ", "
		<< rhs.data[14] << ", "
		<< rhs.data[15] << ")" << std::endl
	;

	return os;
}
