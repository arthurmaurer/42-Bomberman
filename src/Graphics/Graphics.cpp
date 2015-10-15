
#include "Graphics\Graphics.hpp"
#include "Utils/MathUtil.hpp"
#include "Graphics\ShaderProgram.hpp"
#include "Matrix4.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include <algorithm>

float			Graphics::fov = 45.f;
Camera			Graphics::camera;
Window *		Graphics::window = NULL;

Window &	Graphics::createWindow(unsigned width, unsigned height)
{
	window = new Window(width, height, "Bomberman");

	return *window;
}

void		Graphics::unload()
{
	delete window;
	window = NULL;
}
