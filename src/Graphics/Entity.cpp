
#include "Graphics/Entity.hpp"
#include "Graphics/Graphics.hpp"

Entity::Entity(Model & model) :
	model(&model)
{}

Entity::~Entity()
{}
