
#ifndef _CAMERA_H
# define _CAMERA_H

# include "Transform.hpp"

class Camera
{
public:
	float		fovY;
	Transform	transform;

	Camera(float fovY);
};

#endif
