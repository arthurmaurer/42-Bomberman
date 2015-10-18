
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>

#include "Utils/MathUtil.hpp"
#include "Game/Game.hpp"

#define MOVE_SPEED	0.5f;
#define LOOK_SPEED	0.5f
/*
static void	handleControls(Window & window, Camera & camera)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		camera.transform.position.z -= MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		camera.transform.position.z += MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		camera.transform.position.x -= MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		camera.transform.position.x += MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		camera.transform.rotation.rotateX(LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		camera.transform.rotation.rotateX(-LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camera.transform.rotation.rotateY(-LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camera.transform.rotation.rotateY(LOOK_SPEED);
}

static void	spawnCubes()
{
	CubeEntity *	cube;

	for (unsigned i = 0; i < 1000; i++)
	{
		cube = new CubeEntity();
		cube->transform.position.x = MathUtil::random(-100.f, 100.f);
		cube->transform.position.y = MathUtil::random(-100.f, 100.f);
		cube->transform.position.z = MathUtil::random(-100.f, 100.f);

		cube->transform.rotation.rotateX(MathUtil::random(0.f, 90.f));
		cube->transform.rotation.rotateY(MathUtil::random(0.f, 90.f));
		cube->transform.rotation.rotateZ(MathUtil::random(0.f, 90.f));

		Renderer::registerEntity(*cube);
	}
}
*/

int main()
{
	try
	{
		Game	game;

		game.init();
		game.run();

		return EXIT_SUCCESS;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
