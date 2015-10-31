
#include "Core/SFMLNode.hpp"
#include "Graphics/Renderer.hpp"

SFMLNode::SFMLNode()
{
	Renderer::registerNode(*this);
}

void	SFMLNode::render(Window &)
{
}
