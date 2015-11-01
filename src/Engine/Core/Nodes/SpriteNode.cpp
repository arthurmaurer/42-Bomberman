
#include "Engine/Core/Nodes/SpriteNode.hpp"
#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Tools/MathUtil.hpp"

using namespace Fothon;

SpriteNode::SpriteNode(const sf::Texture & texture) :
	texture(&texture)
{}

void	SpriteNode::render(Window & window)
{
	// TODO: binding sprite sfml (origin & move & ...)
	_sprite.setPosition(absoluteTransform.position.x, absoluteTransform.position.y);
	_sprite.setScale(absoluteTransform.scale.x, absoluteTransform.scale.y);
	_sprite.setRotation(MathUtil::deg(absoluteTransform.rotation.getEulerAngles().z));
	_sprite.setTexture(*texture);
	window.window.draw(_sprite);
}
