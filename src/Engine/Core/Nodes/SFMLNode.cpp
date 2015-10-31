
#include "Engine/Core/Nodes/SFMLNode.hpp"
#include "Engine/Graphics/Renderer.hpp"

SFMLNode::SFMLNode()
{
	Renderer::registerNode(*this);
}

void	SFMLNode::render(Window &)
{}
