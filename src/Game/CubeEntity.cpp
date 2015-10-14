
#include "Game/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"

CubeEntity::CubeEntity() :
	Entity(ModelManager::loadFromOBJ("cube.obj"))
{
	model->texture = &TextureManager::loadTexture("cube.bmp");
	transform.position.z = -1.5f;
}

void	CubeEntity::update()
{
	return;
	transform.rotation.rotateX(0.05f);
	transform.rotation.rotateZ(0.02f);
	transform.rotation.rotateY(-0.03f);
}
