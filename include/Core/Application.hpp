
#ifndef _APPLICATION_HPP
# define _APPLICATION_HPP

# include <SFML/System/Time.hpp>
# include <SFML/Graphics/Text.hpp>

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
	void			init();

private:
	sf::Font		_statsFont;
	sf::Text		_statsString;
	sf::Time		_statsUpdateTime;
	size_t			_statsFrameCount;

	void			_updateStats(sf::Time dt);
};

#endif /* _APPLICATION_HPP */
