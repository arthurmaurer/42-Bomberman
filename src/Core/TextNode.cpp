
#include "Core/TextNode.hpp"

TextNode::TextNode(const std::string & text, const sf::Font & font, unsigned characterSize) :
	text(text),
	font(font),
	characterSize(characterSize)
{}

void	TextNode::render(Window & window)
{
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(characterSize);
	_text.setPosition(absoluteTransform.position.x, absoluteTransform.position.y);
	window.window.draw(_text);
}
