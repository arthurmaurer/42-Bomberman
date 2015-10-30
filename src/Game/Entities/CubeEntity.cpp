
#include "Game/Entities/CubeEntity.hpp"
#include "Tools/MathUtil.hpp"
#include "Tools/ModelManager.hpp"
#include "Tools/TextureManager.hpp"
#include "Tools/ModelGenerator.hpp"

#define ROTATION_SPEED 1.f

CubeEntity::CubeEntity() :
	//ModelNode(ModelManager::loadFromOBJ("companion_cube.obj"))
	ModelNode(ModelManager::loadFromOBJ("sphere.obj"))
	//ModelNode(ModelGenerator::generateCube({ 1, 1, 1 }))
{
	model->texture = &TextureManager::load("Cube1", "texture.jpg");
}

void	CubeEntity::update(sf::Time)
{
	count++;

	if (move)
	{
		transform.rotation = Quaternion::identity;
		transform.rotation.rotateX(MathUtil::rad((ROTATION_SPEED / 2) * count));
		transform.rotation.rotateY(MathUtil::rad((ROTATION_SPEED / 2) * count));
		transform.rotation.rotateZ(MathUtil::rad((ROTATION_SPEED / 2) * count));
	}
	else
	{
		transform.rotation = Quaternion::identity;
		transform.rotation.rotateX(MathUtil::rad(ROTATION_SPEED * count));
		transform.rotation.rotateY(MathUtil::rad(ROTATION_SPEED * count));
		transform.rotation.rotateZ(MathUtil::rad(ROTATION_SPEED * count));
	}
}
