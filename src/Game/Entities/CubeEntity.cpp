
#include "Game/Entities/CubeEntity.hpp"
#include "Tools/MathUtil.hpp"
#include "Tools/ModelManager.hpp"
#include "Tools/TextureManager.hpp"

CubeEntity::CubeEntity() :
	ModelNode(ModelManager::load("Cube", "companion_cube.obj"))
{
	model->texture = &TextureManager::load("Cube", "companion_cube.jpg");
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
