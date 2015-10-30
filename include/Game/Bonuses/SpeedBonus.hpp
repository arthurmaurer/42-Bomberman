
#ifndef _SPEED_BONUS_HPP
# define _SPEED_BONUS_HPP

# include "Game/Bonuses/Bonus.hpp"

# define SPEED_BONUS	1.f

class Character;

class SpeedBonus : public Bonus
{
public:
	void	apply(Character & target);
	void	remove();
	bool	update(sf::Time dt);
};

#endif /* _SPEED_BONUS_HPP */
