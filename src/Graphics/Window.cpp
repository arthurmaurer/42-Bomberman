
#include "Graphics/Window.hpp"
#include "Graphics/Graphics.hpp"
#include "Utils/MiscUtil.hpp"

Window::Window(size_t width, size_t height, const std::string & title) :
	width(width),
	height(height)
{
	sf::VideoMode			videoMode(width, height);
	sf::ContextSettings		settings = _getContextSettings();

	window.create(videoMode, title.c_str(), sf::Style::Default, settings);
	_setContext();
}

Window::~Window()
{
	if (window.isOpen())
		close();
}

sf::ContextSettings		Window::_getContextSettings() const
{
	sf::ContextSettings	settings;

	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	return settings;
}

void	Window::_setContext() const
{
	if (glewInit() != GLEW_OK)
		MiscUtil::abort("Glew broken :/");

	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, width, height);
}

void	Window::close()
{
	window.close();
}

void	Window::setTitle(std::string title)
{
	window.setTitle(title);
}

bool	Window::isOpen() const
{
	return window.isOpen();
}

void	Window::display()
{
	window.display();
}
