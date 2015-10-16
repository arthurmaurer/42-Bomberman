#pragma once

#include "Transform.hpp"

class Camera
{
public:
	float		fovY;
	Transform	transform;

	Camera(float fovY);
};
