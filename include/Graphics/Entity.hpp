
#ifndef _ENTITY_H
# define _ENTITY_H

# include "Core/Updatable.hpp"
# include "Graphics/Model.hpp"
# include "Transform.hpp"

class Entity : public Updatable
{
public:
	Transform	transform;
	bool		active = true;
	Model *		model = NULL;

	Entity(Model & model);
	virtual ~Entity();
};

#endif
