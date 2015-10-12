#pragma once

#include "Core/Updatable.hpp"
#include "Graphics/Model.hpp"
#include "Transform.hpp"

class Entity : public Updatable
{
public:
	Transform		transform;
	bool			active;
	const Model *	mesh = NULL;
	GLfloat *		vbo = NULL;
	size_t			vboLength = 0;
	GLuint			vboId = 0;
	const Model *	model = NULL;

	Entity(const Model & modelValue);
	virtual ~Entity();
};
