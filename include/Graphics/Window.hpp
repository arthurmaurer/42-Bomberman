#pragma once

#include <GL/glew.h>
#include <SFML\Window.hpp>
#include <SFML\OpenGL.hpp>

class Window
{
	sf::ContextSettings	_getContextSettings() const;
	void				_setContext() const;

public:
	size_t		width;
	size_t		height;
	sf::Window	window;

	Window(size_t width, size_t height, const std::string & title);
	~Window();

	void		close();
	void		setTitle(std::string title);
	bool		isOpen() const;
	void		display();
};