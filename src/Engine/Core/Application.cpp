//             .-'''''-.
//           .'         `.
//          :             :   File       : Application.cpp
//         :               :  Creation   : 2015-10-17 05:00:19
//         :      _/|      :  Last Edit  : 2015-11-01 11:25:40
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <stdexcept>
#include <stdlib.h>

#include <SFML/Window/Event.hpp>

#include "Engine/Core/Keyboard.hpp"
#include "Engine/Core/Application.hpp"
#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/DefaultProgram.hpp"
#include "Engine/Graphics/Camera.hpp"
#include "Engine/Tools/MathUtil.hpp"
#include "Engine/Tools/Resource.hpp"
#include "Engine/Tools/FontManager.hpp"

using namespace Fothon;

const sf::Time	Application::timePerFrame = sf::seconds(1.f / 60.f);

Application::Application() :
	window(640, 480, "Bomberman"),
	stateStack(State::Context(window, *this))
{
	_initStats();
}

void		Application::init()
{
	Renderer::shaderProgram = new DefaultProgram();
}

void		Application::run()
{
	sf::Clock	clock;
	sf::Time	timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			processInput();
			update(timePerFrame);

			// TODO: Extend Fothon input managing to more than keyboard (mouse, joystick...)
			Keyboard::dehydrate();

			if (stateStack.isEmpty())
				window.close();
		}

		_updateStats(dt);

		// TODO: Rewrite this to avoid the double isOpen condition.
		if (window.isOpen())
			render();
	}
}

void	Application::drawFPS()
{
	sf::RenderWindow &	win = window.window;

	win.pushGLStates();
	win.draw(_statsString);
	win.popGLStates();
}

void	Application::render()
{
	stateStack.render();
	drawFPS();
	window.window.display();
}

void	Application::processInput()
{
	sf::Event event;

	/* TODO:
		Try fixing SFML/JoystickManager
		http://en.sfml-dev.org/forums/index.php?topic=19082.0
	*/
	while (window.window.pollEvent(event))
	{
		stateStack.handleEvent(event);

		Keyboard::hydrate(event);

		if (event.type == sf::Event::Closed)
			window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void	Application::update(sf::Time dt)
{
	stateStack.update(dt);
}

void	Application::_updateStats(sf::Time dt)
{
	_statsUpdateTime += dt;
	_statsFrameCount += 1;

	if (_statsUpdateTime >= sf::seconds(1.0f))
	{
		_statsString.setString("FPS: " + std::to_string(_statsFrameCount));
		_statsUpdateTime -= sf::seconds(1.0f);
		_statsFrameCount = 0;
	}
}

void	Application::_initStats()
{
	_statsString.setFont(Resource::load<FontManager>("Main", "Sansation.ttf"));
	_statsString.setPosition(5.f, 5.f);
	_statsString.setCharacterSize(10);
}
