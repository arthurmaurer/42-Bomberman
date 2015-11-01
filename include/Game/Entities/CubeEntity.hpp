
#ifndef _CUBE_ENTITY_HPP
# define _CUBE_ENTITY_HPP

# include <memory>

# include "Engine/Core/Nodes/ModelNode.hpp"

class CubeEntity : public Fothon::ModelNode
{
public:
	typedef std::unique_ptr<CubeEntity>	Ptr;

	bool		move;
	unsigned	count = 0;

	CubeEntity();

	void		update(sf::Time dt);
};

#endif /* _CUBE_ENTITY_HPP */
