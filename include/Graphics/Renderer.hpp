#pragma once

#include "Matrix4.hpp"
#include "Graphics/Entity.hpp"
#include "Graphics/ShaderProgram.hpp"
#include <vector>

class Renderer
{
public:
	static Matrix4						projectionMatrix;
	static std::vector<const Entity *>	entities;
	static const ShaderProgram *		shaderProgram;

	static void		render();
	static void		renderEntity(const Entity & entity);

	static void		registerEntity(const Entity & entity);
	static void		unregisterEntity(const Entity & entity);
};
