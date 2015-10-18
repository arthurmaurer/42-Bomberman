
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/TextureManager.hpp"
#include "Utils/MathUtil.hpp"

CubeEntity::CubeEntity() :
	ModelNode(ModelManager::loadFromOBJ("cube.obj"))
{
	model->texture = &TextureManager::loadTexture("cube.bmp");
}

void	CubeEntity::update(sf::Time)
{
	count++;

	if (move)
	{
		transform.rotation = Quaternion::identity;
		transform.rotation.rotateX(MathUtil::rad(30.0f * count));
		transform.rotation.rotateY(MathUtil::rad(30.0f * count));
		transform.rotation.rotateZ(MathUtil::rad(30.0f * count));
		transform.position.y += cos(count * 0.015f) / 50.f;
	}
	else
	{
		transform.rotation = Quaternion::identity;
		transform.rotation.rotateX(MathUtil::rad(30.0f * count));
		transform.rotation.rotateY(MathUtil::rad(30.0f * count));
		transform.rotation.rotateZ(MathUtil::rad(30.0f * count));
	}
}
