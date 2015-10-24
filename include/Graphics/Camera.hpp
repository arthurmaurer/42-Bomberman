
#ifndef _CAMERA_HPP
# define _CAMERA_HPP

# include "Transform.hpp"

class Camera
{
public:
	float		fovY;
	float		nearPlane;
	float		farPlane;
	Transform	transform;

	Camera(float fovY);
};

#endif /* _CAMERA_HPP */
