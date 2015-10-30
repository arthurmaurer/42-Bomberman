
#include "Game/Entities/Character.hpp"
#include "Tools/ModelGenerator.hpp"
#include "Tools/TextureManager.hpp"

Character::Character(const std::string & name) :
	ModelNode(ModelGenerator::generateCube(Vec3(1.f, 1.f, 1.f))),
	name(name)
{
	model->texture = &TextureManager::load("character", "companion_cube.jpg");
}

Character::~Character()
{}
