
#ifndef _BONUS_HPP
# define _BONUS_HPP

# include <SFML/System/Time.hpp>

class Character;

class Bonus
{
public:
	Character *		character = nullptr;
	sf::Time		startTime;
	sf::Time		lifeTime;

	virtual void	apply(Character & target);
	virtual void	remove() = 0;
	virtual bool	update(sf::Time dt);
};

#endif /* _BONUS_HPP */
