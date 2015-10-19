
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Tools/TextureManager.hpp"

CubeEntity::CubeEntity() :
	ModelNode(ModelManager::loadFromOBJ("cube.obj"))
{
	model->texture = &TextureManager::load("Cube", "cube.bmp");
}

void	CubeEntity::update(sf::Time dt)
{
	transform.rotation.rotateX(0.01f * dt.asMilliseconds());
	transform.rotation.rotateY(0.01f * dt.asMilliseconds());
	transform.rotation.rotateZ(0.01f * dt.asMilliseconds());
}
