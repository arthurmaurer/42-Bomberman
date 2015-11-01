//             .-'''''-.
//           .'         `.
//          :             :   File       : Application.cpp
//         :               :  Creation   : 2015-10-17 05:00:19
//         :      _/|      :  Last Edit  : 2015-11-01 02:16:38
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

#include "Engine/Core/Application.hpp"
#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/DefaultProgram.hpp"
#include "Engine/Graphics/Camera.hpp"
#include "Engine/Tools/MathUtil.hpp"
#include "Engine/Tools/Resource.hpp"
#include "Engine/Tools/FontManager.hpp"

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
	Renderer::activeCamera = new Camera(45.f);
	Renderer::activeCamera->transform.position.z = 10.f;
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

#define MOVE_SPEED	0.1f
#define LOOK_SPEED	0.01f

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
