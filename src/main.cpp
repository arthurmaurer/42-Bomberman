
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Graphics/Window.hpp"
#include "Game/CubeEntity.hpp"
#include "Utils/MathUtil.hpp"
#include "Graphics\Renderer.hpp"
#include "Graphics\Camera.hpp"
#include "ShaderProgram\DefaultProgram.hpp"
#include "Graphics\TextureManager.hpp"
#include "Graphics\ModelManager.hpp"

#define MOVE_SPEED	0.5f;
#define LOOK_SPEED	0.5f

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

int main()
{
	Window		window(1200, 800, "Bomberman");
	Camera		camera(45.f);
	
	Renderer::activeCamera = &camera;

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
					window.close();
				else if (event.type == sf::Event::Resized)
					glViewport(0, 0, event.size.width, event.size.height);
			}

			handleControls(window, camera);

			for (Entity * entity : Renderer::entities)
				entity->update();

			Renderer::render(window);
		}
	}
	catch (std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}

	ModelManager::cleanUp();
	TextureManager::cleanUp();

	return 0;
}
