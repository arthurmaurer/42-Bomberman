
#ifndef _APPLICATION_HPP
# define _APPLICATION_HPP

# include <SFML/System/Time.hpp>

# include "Graphics/Window.hpp"
# include "Core/StateStack.hpp"

class Application
{
public:
	static const sf::Time	timePerFrame;

	Window		window;
	StateStack	stateStack;

	Application();

	void			run();
	void			processInput();
	void			update(sf::Time dt);
	void			render();
	virtual void	init();
};

#endif /* _APPLICATION_HPP */
