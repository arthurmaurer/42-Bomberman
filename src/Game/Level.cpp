
#include "Game/Level.hpp"
#include "Game/Entities/Block.hpp"
#include "Graphics/Renderer.hpp"

Level::Level(const std::string & name, unsigned width, unsigned height) :
	name(name),
	width(width),
	height(height)
{
	map = new Block**[height];

	for (unsigned i = 0; i < height; ++i)
		map[i] = new Block*[width]();
}

Level::~Level()
{
	unregisterNodes();
	delete[] map;
}

void	Level::registerNodes() const
{
	for (unsigned y = 0; y < height; y++)
	{
		for (unsigned x = 0; x < width; x++)
			Renderer::registerNode(*map[y][x]);
	}
}

void	Level::unregisterNodes() const
{
	for (unsigned y = 0; y < height; y++)
	{
		for (unsigned x = 0; x < width; x++)
			Renderer::unregisterNode(*map[y][x]);
	}
}
