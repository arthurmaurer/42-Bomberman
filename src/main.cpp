
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
#ifdef _WIN32
		system("pause");
#endif
		return EXIT_FAILURE;
	}
}
