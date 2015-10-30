
#include "Game/Bonuses/Bonus.hpp"

void	Bonus::apply(Character & target)
{
	character = &target;
	// TODO: set startTime
}

bool	Bonus::update(sf::Time)
{
	// if life time reached
	// return false to destroy

	return true;
}
