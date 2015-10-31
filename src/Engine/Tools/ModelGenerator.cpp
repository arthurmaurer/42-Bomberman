
#include "Engine/Core/Vec2.hpp"
#include "Engine/Graphics/Model.hpp"
#include "Engine/Tools/ModelGenerator.hpp"
#include "Engine/Tools/ModelManager.hpp"

Model &		ModelGenerator::generatePlane(const Vec2 & size)
{
	RawModelData	modelData;
	float			with2 = size.x / 2.f;
	float			height2 = size.y / 2.f;

	modelData.positions.push_back(Vec3(-with2, -height2, 0));
	modelData.positions.push_back(Vec3(with2, -height2, 0));
	modelData.positions.push_back(Vec3(with2, height2, 0));
	modelData.positions.push_back(Vec3(-with2, height2, 0));

	modelData.uvs.push_back(Vec2(0, 0));
	modelData.uvs.push_back(Vec2(1.f, 0));
	modelData.uvs.push_back(Vec2(1.f, 1.f));
	modelData.uvs.push_back(Vec2(0, 1.f));

	modelData.normals.push_back(Vec3(0, 0, 1.f));
	modelData.normals.push_back(Vec3(0, 0, 1.f));
	modelData.normals.push_back(Vec3(0, 0, 1.f));
	modelData.normals.push_back(Vec3(0, 0, 1.f));

	modelData.indices.push_back(0);
	modelData.indices.push_back(1);
	modelData.indices.push_back(2);
	modelData.indices.push_back(2);
	modelData.indices.push_back(3);
	modelData.indices.push_back(0);

	return ModelManager::createModel(modelData);
}

# define POINT_A		-width2, height2, depth2
# define POINT_B		width2, height2, depth2
# define POINT_C		width2, -height2, depth2
# define POINT_D		-width2, -height2, depth2
# define POINT_E		-width2, height2, -depth2
# define POINT_F		width2, height2, -depth2
# define POINT_G		width2, -height2, -depth2
# define POINT_H		-width2, -height2, -depth2

Model &		ModelGenerator::generateCube(const Vec3 & size)
{
	RawModelData	modelData;
	float			width2 = size.x / 2.f;
	float			height2 = size.y / 2.f;
	float			depth2 = size.z / 2.f;

	modelData.positions.push_back(Vec3(POINT_A));
	modelData.positions.push_back(Vec3(POINT_B));
	modelData.positions.push_back(Vec3(POINT_C));
	modelData.positions.push_back(Vec3(POINT_D));

	modelData.indices.push_back(2);
	modelData.indices.push_back(1);
	modelData.indices.push_back(0);
	modelData.indices.push_back(0);
	modelData.indices.push_back(3);
	modelData.indices.push_back(2);

	modelData.normals.push_back(Vec3(0, 0, 1.f));
	modelData.normals.push_back(Vec3(0, 0, 1.f));
	modelData.normals.push_back(Vec3(0, 0, 1.f));
	modelData.normals.push_back(Vec3(0, 0, 1.f));

	modelData.uvs.push_back(Vec2(0.25f, 0.25f));
	modelData.uvs.push_back(Vec2(0.5f, 0.25f));
	modelData.uvs.push_back(Vec2(0.5f, 0.5f));
	modelData.uvs.push_back(Vec2(0.25f, 0.5f));

	modelData.positions.push_back(Vec3(POINT_E));
	modelData.positions.push_back(Vec3(POINT_F));
	modelData.positions.push_back(Vec3(POINT_G));
	modelData.positions.push_back(Vec3(POINT_H));

	modelData.indices.push_back(4);
	modelData.indices.push_back(5);
	modelData.indices.push_back(6);
	modelData.indices.push_back(6);
	modelData.indices.push_back(7);
	modelData.indices.push_back(4);

	modelData.normals.push_back(Vec3(0, 0, -1.f));
	modelData.normals.push_back(Vec3(0, 0, -1.f));
	modelData.normals.push_back(Vec3(0, 0, -1.f));
	modelData.normals.push_back(Vec3(0, 0, -1.f));

	modelData.uvs.push_back(Vec2(0.25f, 0.75f));
	modelData.uvs.push_back(Vec2(0.5f, 0.75f));
	modelData.uvs.push_back(Vec2(0.5f, 1.0f));
	modelData.uvs.push_back(Vec2(0.25f, 1.0f));

	modelData.positions.push_back(Vec3(POINT_B));
	modelData.positions.push_back(Vec3(POINT_F));
	modelData.positions.push_back(Vec3(POINT_G));
	modelData.positions.push_back(Vec3(POINT_C));

	modelData.indices.push_back(10);
	modelData.indices.push_back(9);
	modelData.indices.push_back(8);
	modelData.indices.push_back(8);
	modelData.indices.push_back(11);
	modelData.indices.push_back(10);

	modelData.normals.push_back(Vec3(1.f, 0, 0));
	modelData.normals.push_back(Vec3(1.f, 0, 0));
	modelData.normals.push_back(Vec3(1.f, 0, 0));
	modelData.normals.push_back(Vec3(1.f, 0, 0));

	modelData.uvs.push_back(Vec2(0.5f, 0.25f));
	modelData.uvs.push_back(Vec2(0.75f, 0.25f));
	modelData.uvs.push_back(Vec2(0.75f, 0.5f));
	modelData.uvs.push_back(Vec2(0.5f, 0.5f));

	modelData.positions.push_back(Vec3(POINT_E));
	modelData.positions.push_back(Vec3(POINT_A));
	modelData.positions.push_back(Vec3(POINT_D));
	modelData.positions.push_back(Vec3(POINT_H));

	modelData.indices.push_back(14);
	modelData.indices.push_back(13);
	modelData.indices.push_back(12);
	modelData.indices.push_back(12);
	modelData.indices.push_back(15);
	modelData.indices.push_back(14);

	modelData.normals.push_back(Vec3(-1.f, 0, 0));
	modelData.normals.push_back(Vec3(-1.f, 0, 0));
	modelData.normals.push_back(Vec3(-1.f, 0, 0));
	modelData.normals.push_back(Vec3(-1.f, 0, 0));

	modelData.uvs.push_back(Vec2(0.f, 0.25f));
	modelData.uvs.push_back(Vec2(0.25f, 0.25f));
	modelData.uvs.push_back(Vec2(0.25f, 0.5f));
	modelData.uvs.push_back(Vec2(0.f, 0.5f));

	modelData.positions.push_back(Vec3(POINT_E));
	modelData.positions.push_back(Vec3(POINT_F));
	modelData.positions.push_back(Vec3(POINT_B));
	modelData.positions.push_back(Vec3(POINT_A));

	modelData.indices.push_back(18);
	modelData.indices.push_back(17);
	modelData.indices.push_back(16);
	modelData.indices.push_back(16);
	modelData.indices.push_back(19);
	modelData.indices.push_back(18);

	modelData.normals.push_back(Vec3(0, -1.f, 0));
	modelData.normals.push_back(Vec3(0, -1.f, 0));
	modelData.normals.push_back(Vec3(0, -1.f, 0));
	modelData.normals.push_back(Vec3(0, -1.f, 0));

	modelData.uvs.push_back(Vec2(0.25f, 0.f));
	modelData.uvs.push_back(Vec2(0.5f, 0.f));
	modelData.uvs.push_back(Vec2(0.5f, 0.25f));
	modelData.uvs.push_back(Vec2(0.25f, 0.25f));

	modelData.positions.push_back(Vec3(POINT_H));
	modelData.positions.push_back(Vec3(POINT_G));
	modelData.positions.push_back(Vec3(POINT_C));
	modelData.positions.push_back(Vec3(POINT_D));

	modelData.indices.push_back(20);
	modelData.indices.push_back(21);
	modelData.indices.push_back(22);
	modelData.indices.push_back(22);
	modelData.indices.push_back(23);
	modelData.indices.push_back(20);

	modelData.normals.push_back(Vec3(0, 1.f, 0));
	modelData.normals.push_back(Vec3(0, 1.f, 0));
	modelData.normals.push_back(Vec3(0, 1.f, 0));
	modelData.normals.push_back(Vec3(0, 1.f, 0));

	modelData.uvs.push_back(Vec2(0.25f, 0.5f));
	modelData.uvs.push_back(Vec2(0.5f, 0.5f));
	modelData.uvs.push_back(Vec2(0.5f, 0.75f));
	modelData.uvs.push_back(Vec2(0.25f, 0.75f));

	return ModelManager::createModel(modelData);
}
