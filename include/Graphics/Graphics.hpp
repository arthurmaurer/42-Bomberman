#pragma once

#include "Graphics/Entity.hpp"
#include "Matrix4.hpp"
#include "Graphics/Camera.hpp"
#include "Graphics/Window.hpp"

class Graphics
{
	Graphics();

public:
	static float			fov;
	static Camera			camera;
	static Window *			window;

	static Window &			createWindow(unsigned width, unsigned height);
	static void				unload();
};
