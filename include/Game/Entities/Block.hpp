
#ifndef _BLOCK_HPP
# define _BLOCK_HPP

# include "Engine/Core/Nodes/ModelNode.hpp"

class Block : public ModelNode
{
public:
	bool	walkable = false;

	Block();
	Block(Model & model);
};

#endif /* _BLOCK_HPP */
