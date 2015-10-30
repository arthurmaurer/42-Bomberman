
#ifndef _DESTRUCTIBLE_BLOCK_HPP
# define _DESTRUCTIBLE_BLOCK_HPP

# include "Game/Entities/Block.hpp"

class DestructibleBlock : public Block
{
public:
	unsigned	hp = 1;
	ModelNode *	content = nullptr;

	DestructibleBlock();
	DestructibleBlock(unsigned hp, ModelNode & content);
};

#endif /* _DESTRUCTIBLE_BLOCK_HPP */
