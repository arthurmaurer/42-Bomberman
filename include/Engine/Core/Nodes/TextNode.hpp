
#ifndef _TEXT_NODE_HPP
# define _TEXT_NODE_HPP

# include <SFML/Graphics/Text.hpp>

# include "Engine/Core/Nodes/SFMLNode.hpp"

namespace Fothon
{
	class TextNode : public SFMLNode
	{
		sf::Text			_text;

	public:
		std::string			text;
		const sf::Font *	font = nullptr;
		unsigned			characterSize;

		TextNode() = default;
		TextNode(const std::string & text, const sf::Font & font, unsigned characterSize = 10, bool autoRegister = true);

		void	render(Window & window);
	};
}

#endif /* _TEXT_NODE_HPP */
