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
#include "Utils/MathUtil.hpp"

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

		// TODO: Rewrite this to avoid the double isOpen condition.
		if (window.isOpen())
			render();
	}
}

void	Application::render()
{
	stateStack.render();
}

#define MOVE_SPEED	0.1f
#define LOOK_SPEED	0.01f

void	Application::processInput()
{
	sf::Event event;

	while (window.window.pollEvent(event))
	{
		stateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();
	}

	Camera &	camera = *Renderer::activeCamera;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		camera.transform.position -= camera.transform.rotation * (Vec3::forward * MOVE_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		camera.transform.position -= camera.transform.rotation * (Vec3::back * MOVE_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		camera.transform.position += camera.transform.rotation * (Vec3::left * MOVE_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		camera.transform.position += camera.transform.rotation * (Vec3::right * MOVE_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		camera.transform.rotation.rotateX(LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		camera.transform.rotation.rotateX(-LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camera.transform.rotation.rotateY(-LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camera.transform.rotation.rotateY(LOOK_SPEED);
}

void	Application::update(sf::Time dt)
{
	stateStack.update(dt);
}
