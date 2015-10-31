
#include "Core/SpriteNode.hpp"
#include "Graphics/Renderer.hpp"
#include "Tools/MathUtil.hpp"

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
