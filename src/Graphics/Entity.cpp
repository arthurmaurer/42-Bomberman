
#include "Graphics/Entity.hpp"
#include "Graphics/Graphics.hpp"

Entity::Entity(const Model & modelValue) :
	model(&modelValue)
{}

Entity::~Entity()
{}
