
#include "Engine/Graphics/Model.hpp"
#include "Engine/Tools/ModelGenerator.hpp"
#include "Engine/Tools/TextureManager.hpp"

#include "Game/Entities/Character.hpp"

Character::Character(const std::string & name) :
	ModelNode(ModelGenerator::generateCube(Vec3(1.f, 1.f, 1.f))),
	name(name)
{
	model->texture = &TextureManager::load("character", "companion_cube.jpg");
}

Character::~Character()
{}
