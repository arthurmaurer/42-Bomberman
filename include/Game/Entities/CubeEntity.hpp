
#ifndef _CUBE_ENTITY_H
# define _CUBE_ENTITY_H

# include <memory>

# include "Core/ModelNode.hpp"

class CubeEntity : public ModelNode
{
public:
	typedef std::unique_ptr<CubeEntity>	Ptr;

	CubeEntity();

	void		update(sf::Time dt);
};

#endif
