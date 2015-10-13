#pragma once

#include "Core/Updatable.hpp"
#include "Graphics/Model.hpp"
#include "Transform.hpp"

class Entity : public Updatable
{
public:
	Transform	transform;
	bool		active;
	Model *		model = NULL;

	Entity(Model & model);
	virtual ~Entity();
};
