
#include "Engine/Graphics/Model.hpp"
#include "Engine/Tools.hpp"

#include "Game/Entities/Character.hpp"

using namespace Fothon;

Character::Character(const std::string & name) :
	ModelNode(ModelGenerator::generateCube(Vec3(1.f, 1.f, 1.f))),
	name(name)
{
	model->texture = &Resource::load<TextureManager>("character", "companion_cube.jpg");
}

Character::~Character()
{}
