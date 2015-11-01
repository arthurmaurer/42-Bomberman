
#include "Engine/Graphics/Camera.hpp"

using namespace Fothon;

Camera::Camera(float fovY) :
	fovY(fovY),
	nearPlane(1.f),
	farPlane(1000.f)
{}