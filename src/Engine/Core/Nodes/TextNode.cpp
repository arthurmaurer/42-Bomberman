
#include "Engine/Core/Nodes/TextNode.hpp"

using namespace Fothon;

TextNode::TextNode(const std::string & text, const sf::Font & font, unsigned characterSize, bool autoRegister) :
	SFMLNode(autoRegister),
	text(text),
	font(&font),
	characterSize(characterSize)
{}

void	TextNode::render(Window & window)
{
	_text.setString(text);
	_text.setFont(*font);
	_text.setCharacterSize(characterSize);
	_text.setPosition(absoluteTransform.position.x, absoluteTransform.position.y);
	window.window.draw(_text);
}
