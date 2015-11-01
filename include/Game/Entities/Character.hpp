
#ifndef _CHARACTER_HPP
# define _CHARACTER_HPP

# include <string>

# include "Engine/Core/Nodes/ModelNode.hpp"

class Character : public Fothon::ModelNode
{
public:
	const std::string	name;
	unsigned			maxBomb = 1;
	unsigned			hp = 1;
	unsigned			lives = 3;
	unsigned			blastDistance = 1;
	Fothon::Vec3			acceleration;
	float				moveSpeed = 1.f;
	bool				immortal = false;
	bool				fly = false;
	bool				detonator = false;
	bool				bombKick = false;

	Character(const std::string & name);
	virtual ~Character();
};

#endif /* _CHARACTER_HPP */
