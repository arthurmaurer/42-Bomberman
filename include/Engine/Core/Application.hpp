
#ifndef _APPLICATION_HPP
# define _APPLICATION_HPP

# include <SFML/System/Time.hpp>
# include <SFML/Graphics/Text.hpp>

# include "Engine/Graphics/Window.hpp"
# include "Engine/Core/StateStack.hpp"

class Application
{
public:
	static const sf::Time	timePerFrame;

	Window		window;
	StateStack	stateStack;

	Application();

	void			drawFPS();
	void			run();
	void			processInput();
	void			update(sf::Time dt);
	void			render();
	void			init();

	// TODO: clean this shit
	sf::Font		_statsFont;

private:
	sf::Text		_statsString;
	sf::Time		_statsUpdateTime;
	size_t			_statsFrameCount;

	void			_updateStats(sf::Time dt);
	void			_initStats();
};

#endif /* _APPLICATION_HPP */
