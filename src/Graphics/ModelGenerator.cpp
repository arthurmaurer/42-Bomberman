
#include "Graphics/ModelGenerator.hpp"
#include "Tools/ModelManager.hpp"
#include "Graphics/Model.hpp"
#include "Vec2.hpp"

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

Model &		ModelGenerator::generateCube(const Vec3 & size)
{
	RawModelData	modelData;
	float			with2 = size.x / 2.f;
	float			height2 = size.y / 2.f;
	float			depth2 = size.z / 2.f;

	modelData.positions.push_back(Vec3(-with2, height2, depth2));
	modelData.positions.push_back(Vec3(with2, height2, depth2));
	modelData.positions.push_back(Vec3(with2, -height2, depth2));
	modelData.positions.push_back(Vec3(-with2, -height2, depth2));
	modelData.positions.push_back(Vec3(-with2, height2, -depth2));
	modelData.positions.push_back(Vec3(with2, height2, -depth2));
	modelData.positions.push_back(Vec3(with2, -height2, -depth2));
	modelData.positions.push_back(Vec3(-with2, -height2, -depth2));

	modelData.uvs.push_back(Vec2(0, 0));
	modelData.uvs.push_back(Vec2(1.f, 0));
	modelData.uvs.push_back(Vec2(1.f, 1.f));
	modelData.uvs.push_back(Vec2(0, 1.f));
	modelData.uvs.push_back(Vec2(0, 0));
	modelData.uvs.push_back(Vec2(1.f, 0));
	modelData.uvs.push_back(Vec2(1.f, 1.f));
	modelData.uvs.push_back(Vec2(0, 1.f));

	modelData.normals.push_back(Vec3(-1.f, 1.f, 1.f));
	modelData.normals.push_back(Vec3(1.f, 1.f, 1.f));
	modelData.normals.push_back(Vec3(1.f, -1.f, 1.f));
	modelData.normals.push_back(Vec3(-1.f, -1.f, 1.f));
	modelData.normals.push_back(Vec3(-1.f, 1.f, -1.f));
	modelData.normals.push_back(Vec3(1.f, 1.f, -1.f));
	modelData.normals.push_back(Vec3(1.f, -1.f, -1.f));
	modelData.normals.push_back(Vec3(-1.f, -1.f, -1.f));

	modelData.indices.push_back(2);
	modelData.indices.push_back(1);
	modelData.indices.push_back(0);
	modelData.indices.push_back(0);
	modelData.indices.push_back(3);
	modelData.indices.push_back(2);

	modelData.indices.push_back(4);
	modelData.indices.push_back(5);
	modelData.indices.push_back(6);
	modelData.indices.push_back(6);
	modelData.indices.push_back(7);
	modelData.indices.push_back(4);

	modelData.indices.push_back(1);
	modelData.indices.push_back(5);
	modelData.indices.push_back(4);
	modelData.indices.push_back(4);
	modelData.indices.push_back(0);
	modelData.indices.push_back(1);

	modelData.indices.push_back(6);
	modelData.indices.push_back(2);
	modelData.indices.push_back(3);
	modelData.indices.push_back(3);
	modelData.indices.push_back(7);
	modelData.indices.push_back(6);

	modelData.indices.push_back(3);
	modelData.indices.push_back(0);
	modelData.indices.push_back(4);
	modelData.indices.push_back(4);
	modelData.indices.push_back(7);
	modelData.indices.push_back(3);

	modelData.indices.push_back(6);
	modelData.indices.push_back(5);
	modelData.indices.push_back(1);
	modelData.indices.push_back(1);
	modelData.indices.push_back(2);
	modelData.indices.push_back(6);

	return ModelManager::createModel(modelData);
}
