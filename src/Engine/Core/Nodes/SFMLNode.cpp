
#include "Engine/Core/Nodes/SFMLNode.hpp"
#include "Engine/Graphics/Renderer.hpp"

using namespace Fothon;

SFMLNode::SFMLNode()
{
	Renderer::registerNode(*this);
}

void	SFMLNode::render(Window &)
{}
