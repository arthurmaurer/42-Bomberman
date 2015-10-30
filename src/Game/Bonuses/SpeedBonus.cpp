
#include "Game/Bonuses/SpeedBonus.hpp"
#include "Game/Entities/Character.hpp"

void	SpeedBonus::apply(Character & target)
{
	Bonus::apply(target);
	character->moveSpeed += SPEED_BONUS;
}

void	SpeedBonus::remove()
{
	if (character == nullptr)
		return;

	character->moveSpeed -= SPEED_BONUS;
}

bool	SpeedBonus::update(sf::Time dt)
{
	return Bonus::update(dt);
}
