
#include "Graphics/Graphics.hpp"
#include "Graphics/Shader.hpp"
#include "Game/TestEntity.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"

int main()
{
	sf::Window &	window = Graphics::createWindow(800, 800);
	
	try
	{
		DefaultProgram	shaderProgram;
		shaderProgram.enable();

		TestEntity	entity;
		Graphics::registerEntity(entity);

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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				Graphics::stop();

			entity.update();
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
