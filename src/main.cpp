
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Graphics/Graphics.hpp"
#include "Graphics/Shader.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"
#include "Game/CubeEntity.hpp"
#include "Utils/MathUtil.hpp"

#define MOVE_SPEED	0.5f;
#define LOOK_SPEED	0.5f

static void	handleControls()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		Graphics::window->close();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		Graphics::camera.transform.position.z -= MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Graphics::camera.transform.position.z += MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		Graphics::camera.transform.position.x -= MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Graphics::camera.transform.position.x += MOVE_SPEED;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		Graphics::camera.transform.rotation.rotateX(LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		Graphics::camera.transform.rotation.rotateX(-LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		Graphics::camera.transform.rotation.rotateY(-LOOK_SPEED);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		Graphics::camera.transform.rotation.rotateY(LOOK_SPEED);
}

static void	spawnCubes()
{
	CubeEntity *	cube;
	
	for (unsigned i = 0; i < 600; i++)
	{
		cube = new CubeEntity();
		cube->transform.position.x = MathUtil::random(-50.f, 50.f);
		cube->transform.position.y = MathUtil::random(-50.f, 50.f);
		cube->transform.position.z = MathUtil::random(-50.f, 50.f);

		cube->transform.rotation.rotateX(MathUtil::random(0.f, 90.f));
		cube->transform.rotation.rotateY(MathUtil::random(0.f, 90.f));
		cube->transform.rotation.rotateZ(MathUtil::random(0.f, 90.f));

		Graphics::registerEntity(*cube);
	}
}

int main()
{
	Window &	window = Graphics::createWindow(800, 800);

	try
	{
		DefaultProgram	shaderProgram;
		shaderProgram.enable();

		spawnCubes();

		TextureManager::clearCache();
		ModelManager::clearCache();

		while (window.isOpen())
		{
			sf::Event event;

			while (window.window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					Graphics::window->close();
				else if (event.type == sf::Event::Resized)
					glViewport(0, 0, event.size.width, event.size.height);
			}

			handleControls();

			Graphics::render();
		}
	}
	catch (std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}

	ModelManager::cleanUp();
	TextureManager::cleanUp();
	Graphics::unload();

	return 0;
}
