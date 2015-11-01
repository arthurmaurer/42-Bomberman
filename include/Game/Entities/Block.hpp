
#ifndef _BLOCK_HPP
# define _BLOCK_HPP

# include "Engine/Core/Nodes/ModelNode.hpp"

class Block : public Fothon::ModelNode
{
public:
	bool	walkable = false;

	Block();
	Block(Fothon::Model & model);
};

#endif /* _BLOCK_HPP */
