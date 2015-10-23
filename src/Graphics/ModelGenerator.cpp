
#include "Graphics/ModelGenerator.hpp"
#include "Graphics/ModelManager.hpp"
#include "Graphics/Model.hpp"
#include "Vec2.hpp"

Model &		ModelGenerator::generatePlane(const Vec2 & size)
{
	RawModelData	modelData;

	modelData.positions.push_back(Vec3(0, 0, 0));
	modelData.positions.push_back(Vec3(size.x, 0, 0));
	modelData.positions.push_back(Vec3(size.x, size.y, 0));
	modelData.positions.push_back(Vec3(0, size.y, 0));

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
