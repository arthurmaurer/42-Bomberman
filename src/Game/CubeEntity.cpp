
#include "Game/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"
#include "Utils/MathUtil.hpp"

CubeEntity::CubeEntity() :
	Entity(ModelManager::loadFromOBJ("cube.obj"))
{
	model->texture = &TextureManager::loadTexture("cube.bmp");
}

void	CubeEntity::update()
{}
