
#include "Game/Levels/Level00.hpp"
#include "Game/Entities/Block.hpp"
#include "Game/Entities/DestructibleBlock.hpp"
#include "Graphics/Renderer.hpp"

Level00::Level00() :
	Level("Level 00", 5, 5)
{
	/*
	map[1][0] = new Block();
	map[1][0]->transform.position.set(0.f, 0.f, 0.f);

	map[1][1] = new Block();
	map[1][1]->transform.position.set(0.f, 0.f, 0.f);

	map[1][2] = new DestructibleBlock();
	map[1][2]->transform.position.set(0.f, 0.f, 0.f);

	map[1][3] = new Block();
	map[1][3]->transform.position.set(0.f, 0.f, 0.f);

	map[1][4] = new Block();
	map[1][4]->transform.position.set(0.f, 0.f, 0.f);

	map[2][0] = new Block();
	map[2][0]->transform.position.set(0.f, 0.f, 0.f);

	map[2][1] = new DestructibleBlock();
	map[2][1]->transform.position.set(0.f, 0.f, 0.f);

	map[2][2] = new DestructibleBlock();
	map[2][2]->transform.position.set(0.f, 0.f, 0.f);

	map[2][3] = new DestructibleBlock();
	map[2][3]->transform.position.set(0.f, 0.f, 0.f);

	map[2][4] = new Block();
	map[2][4]->transform.position.set(0.f, 0.f, 0.f);

	map[3][0] = new Block();
	map[3][0]->transform.position.set(0.f, 0.f, 0.f);

	map[3][1] = new Block();
	map[3][1]->transform.position.set(0.f, 0.f, 0.f);

	map[3][2] = new DestructibleBlock();
	map[3][2]->transform.position.set(0.f, 0.f, 0.f);

	map[3][3] = new Block();
	map[3][3]->transform.position.set(0.f, 0.f, 0.f);

	map[3][4] = new Block();
	map[3][4]->transform.position.set(0.f, 0.f, 0.f);

	map[4][0] = new Block();
	map[4][0]->transform.position.set(0.f, 0.f, 0.f);

	map[4][1] = new Block();
	map[4][1]->transform.position.set(0.f, 0.f, 0.f);

	map[4][2] = new Block();
	map[4][2]->transform.position.set(0.f, 0.f, 0.f);

	map[4][3] = new Block();
	map[4][3]->transform.position.set(0.f, 0.f, 0.f);

	map[4][4] = new Block();
	map[4][4]->transform.position.set(0.f, 0.f, 0.f);
	*/

	for (unsigned y = 0; y < height; y++)
	{
		for (unsigned x = 0; x < width; x++)
		{
			map[y][x] = new Block();
			map[y][x]->transform.position = { (float)x - width / 2.f, (float)y - height / 2.f, -10.f };
			map[y][x]->updateNode(sf::Time());
		}
	}

	registerNodes();
}
