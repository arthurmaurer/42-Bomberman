
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"
#include "Utils/MathUtil.hpp"

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
		transform.rotation.rotateX(MathUtil::rad(1.0f * count));
		transform.rotation.rotateY(MathUtil::rad(1.0f * count));
		transform.rotation.rotateZ(MathUtil::rad(1.0f * count));
		transform.position.y += cos(count * 0.015f) / 50.f;
	}
	else
	{
		transform.rotation = Quaternion::identity;
		transform.rotation.rotateX(MathUtil::rad(1.0f * count));
		transform.rotation.rotateY(MathUtil::rad(1.0f * count));
		transform.rotation.rotateZ(MathUtil::rad(1.0f * count));
	}
}
