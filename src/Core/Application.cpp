//             .-'''''-.
//           .'         `.
//          :             :   File       : Application.cpp
//         :               :  Creation   : 2015-10-17 05:00:19
//         :      _/|      :  Last Edit  : 2015-10-17 07:24:07
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Core/Application.hpp"
#include "Graphics/Renderer.hpp"
#include "Game/CubeEntity.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include "Graphics/Camera.hpp"

const sf::Time	Application::timePerFrame = sf::seconds(1.f / 60.f);

Application::Application() :
	window(1200, 800, "Bomberman")
{
	Renderer::shaderProgram = new DefaultProgram();
	Renderer::shaderProgram->enable();
	Renderer::activeCamera = new Camera(45.f);

	CubeEntity *	cube;

	cube = new CubeEntity();
	cube->transform.position.z = -20.f;
	cube->transform.rotation.rotateX(50.f);
	cube->transform.rotation.rotateY(50.f);
	cube->transform.rotation.rotateZ(50.f);

	Renderer::registerEntity(*cube);
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
			// if (_stateStack.isEmpty())
			// 	window.close();
		}

		Renderer::render(window);
	}
}

void Application::processInput()
{
	sf::Event event;

	while (window.window.pollEvent(event))
	{
		// _stateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Application::update(sf::Time)
{
	// _stateStack.update(dt);
}
