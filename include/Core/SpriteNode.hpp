
#ifndef _SPRITE_NODE_HPP
# define _SPRITE_NODE_HPP

# include <SFML/Graphics/Sprite.hpp>

# include "Core/SFMLNode.hpp"
# include "Core/Renderable.hpp"

class SpriteNode :	public SFMLNode
{
	sf::Sprite	_sprite;

public:
	const sf::Texture *		texture = nullptr;

	SpriteNode(const sf::Texture & texture);

	void	render(Window & window);
};

#endif /* _SPRITE_NODE_HPP */
