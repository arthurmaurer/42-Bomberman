
#ifndef _APPLICATION_HPP
# define _APPLICATION_HPP

# include <SFML/System/Time.hpp>
# include <SFML/Graphics/Text.hpp>

# include "Engine/Graphics/Window.hpp"
# include "Engine/Core/StateStack.hpp"

namespace Fothon
{
	class Application
	{
	public:
		static const sf::Time	timePerFrame;

		Window		window;
		StateStack	stateStack;

		Application(unsigned windowW, unsigned windowH, const std::string & name);

		void			drawFPS();
		void			run();
		void			processInput();
		void			update(sf::Time dt);
		void			render();
		void			init();

	private:
		sf::Text		_statsString;
		sf::Time		_statsUpdateTime;
		size_t			_statsFrameCount;

		void			_updateStats(sf::Time dt);
		void			_initStats();
	};
}

#endif /* _APPLICATION_HPP */
