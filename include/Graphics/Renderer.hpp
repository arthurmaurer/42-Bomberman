#pragma once

#include "Matrix4.hpp"
#include "Graphics/Entity.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Graphics\Camera.hpp"
#include "Graphics\Window.hpp"
#include <vector>

class Renderer
{
public:
	static std::vector<Entity *>		entities;
	static const ShaderProgram *		shaderProgram;
	static const Camera *				activeCamera;

	static void		render(Window & window);
	static void		renderEntity(const Window & window, const Entity & entity);

	static void		registerEntity(Entity & entity);
	static void		unregisterEntity(const Entity & entity);
};
