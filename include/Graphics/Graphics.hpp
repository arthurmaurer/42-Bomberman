#pragma once

#include <GL/glew.h>
#include <SFML\Window.hpp>
#include <SFML\OpenGL.hpp>
#include <GL/glew.h>
#include "Graphics/Entity.hpp"
#include "Matrix4.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Camera.h"

class Graphics
{
	Graphics();
	Graphics(const Graphics & src);

	Graphics &	operator=(const Graphics & rhs);

public:
	static sf::Window *					window;
	static bool							running;
	static std::vector<const Entity *>	entities;
	static GLuint						mvpUni;
	static unsigned						width;
	static unsigned						height;
	static Matrix4						projectionMatrix;
	static const ShaderProgram *		shaderProgram;
	static Camera						camera;

	static sf::Window &		createWindow(unsigned windowWidth, unsigned windowHeight);
	static void				unload();
	static void				stop();
	static void				setTitle(std::string title);
	static void				registerEntity(Entity & entity);
	static void				unregisterEntity(const Entity & entity);
	static void				render();
	static void				renderEntity(const Entity & entity);
};
