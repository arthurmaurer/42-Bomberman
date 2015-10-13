
#include "Game/TestEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"

TestEntity::TestEntity() :
	Entity(ModelManager::loadFromOBJ("cube.obj"))
{
	model->texture = &TextureManager::loadTexture("texture.jpg");
	transform.position.z = -1.5f;
	transform.scale = Vec3(0.5f, 0.5f, 0.5f);
}

void	TestEntity::update()
{
	transform.rotation.rotateX(0.05f);
	transform.rotation.rotateZ(0.02f);
	transform.rotation.rotateY(-0.03f);
}
