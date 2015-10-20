
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"
#include "Utils/MathUtil.hpp"

#define ROTATION_SPEED 1.f

CubeEntity::CubeEntity() :
	ModelNode(ModelManager::loadFromOBJ("companion_cube.obj"))
{
	model->texture = &TextureManager::loadTexture("companion_cube.jpg");
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
