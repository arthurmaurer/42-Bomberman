
#include "Game/TestEntity.hpp"
#include "Graphics/ModelManager.hpp"

TestEntity::TestEntity() :
	Entity(ModelManager::loadFromOBJ("cube.obj"))
{
	transform.position.z = -1.5f;
	transform.rotation.rotateX(45.f);
	transform.rotation.rotateZ(45.f);
	transform.scale = Vec3(0.5f, 0.5f, 0.5f);
}

void	TestEntity::update()
{
	transform.rotation.rotateX(0.05f);
	transform.rotation.rotateZ(0.02f);
}
