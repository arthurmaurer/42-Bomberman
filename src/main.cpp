
#include <iostream>

#include "Tools/MathUtil.hpp"
#include "Game/Game.hpp"

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
