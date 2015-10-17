
#ifndef _APPLICATION_HPP
# define _APPLICATION_HPP

# include <SFML/System/Time.hpp>

# include "Graphics/Window.hpp"

class Application
{
public:
	static const sf::Time	timePerFrame;

	Window		window;

	Application();

	void		run();
	void		processInput();
	void		update(sf::Time dt);
	void		render();
};

#endif /* _APPLICATION_HPP */
