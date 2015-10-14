#pragma once

#include "Graphics/Entity.hpp"
#include "Matrix4.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Camera.h"
#include "Graphics/Window.hpp"

class Graphics
{
	Graphics();

public:
	static std::vector<const Entity *>	entities;
	static Matrix4						projectionMatrix;
	static const ShaderProgram *		shaderProgram;
	static Camera						camera;
	static Window *						window;

	static Window &			createWindow(unsigned width, unsigned height);
	static void				unload();
	static void				registerEntity(Entity & entity);
	static void				unregisterEntity(const Entity & entity);
	static void				render();
	static void				renderEntity(const Entity & entity);
};
