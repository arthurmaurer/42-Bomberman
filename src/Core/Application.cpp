//             .-'''''-.
//           .'         `.
//          :             :   File       : Application.cpp
//         :               :  Creation   : 2015-10-17 05:00:19
//         :      _/|      :  Last Edit  : 2015-10-18 04:15:04
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Core/Application.hpp"
#include "Graphics/Renderer.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include "Graphics/Camera.hpp"

const sf::Time	Application::timePerFrame = sf::seconds(1.f / 60.f);

Application::Application() :
	window(1200, 800, "Bomberman"),
	stateStack(State::Context(window))
{
	init();
}

void		Application::init()
{
	Renderer::shaderProgram = new DefaultProgram();
	Renderer::shaderProgram->enable();
	Renderer::activeCamera = new Camera(45.f);
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

			// Check inside this loop, because stack might be empty before update() call
			if (stateStack.isEmpty())
				window.close();
		}

		render();
	}
}

void	Application::render()
{
	stateStack.render();
}

void	Application::processInput()
{
	sf::Event event;

	while (window.window.pollEvent(event))
	{
		stateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void	Application::update(sf::Time dt)
{
	stateStack.update(dt);
}
