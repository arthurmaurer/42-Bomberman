
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"

CubeEntity::CubeEntity() :
	Entity(ModelManager::loadFromOBJ("cube.obj"))
{
	model->texture = &TextureManager::loadTexture("cube.bmp");
}

void	CubeEntity::update()
{}
