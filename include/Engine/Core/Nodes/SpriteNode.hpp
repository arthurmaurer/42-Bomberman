
#ifndef _SPRITE_NODE_HPP
# define _SPRITE_NODE_HPP

# include <SFML/Graphics/Sprite.hpp>

# include "Engine/Core/Nodes/SFMLNode.hpp"
# include "Engine/Graphics/Renderable.hpp"

namespace Fothon
{
	class SpriteNode : public SFMLNode
	{
		sf::Sprite	_sprite;

	public:
		const sf::Texture *		texture = nullptr;

		SpriteNode(const sf::Texture & texture, bool autoRegister = true);

		void	render(Window & window);
	};
}

#endif /* _SPRITE_NODE_HPP */
