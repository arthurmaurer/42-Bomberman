
#include "Graphics/Graphics.hpp"
#include "Graphics/Shader.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"
#include "Game/CubeEntity.hpp"
#include "Utils/MathUtil.hpp"

#define MOVE_SPEED	0.5f;
#define LOOK_SPEED	0.1f

static void	handleControls()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		Graphics::stop();

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
	float			scale;
	
	for (unsigned i = 0; i < 200; i++)
	{
		cube = new CubeEntity();
		cube->transform.position.x = MathUtil::random(-50.f, 50.f);
		cube->transform.position.y = MathUtil::random(-50.f, 50.f);
		cube->transform.position.z = MathUtil::random(-50.f, 50.f);

		scale = MathUtil::random(3.f, 10.f);
		cube->transform.scale.x = scale;
		cube->transform.scale.y = scale;
		cube->transform.scale.z = scale;

		cube->transform.rotation.rotateX(MathUtil::random(0.f, 90.f));
		cube->transform.rotation.rotateY(MathUtil::random(0.f, 90.f));
		cube->transform.rotation.rotateZ(MathUtil::random(0.f, 90.f));

		Graphics::registerEntity(*cube);
	}
}

int main()
{
	sf::Window &	window = Graphics::createWindow(800, 800);
	
	try
	{
		DefaultProgram	shaderProgram;
		shaderProgram.enable();

		spawnCubes();

		while (Graphics::running)
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					Graphics::stop();
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

	return 0;
}
