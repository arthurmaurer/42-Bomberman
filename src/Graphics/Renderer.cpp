
# include <stdio.h>
#include "Graphics/Renderer.hpp"
#include "Tools/MathUtil.hpp"
#include "Core/SceneNode.hpp"

std::vector<SceneNode *>	Renderer::nodes;
const ShaderProgram *		Renderer::shaderProgram = NULL;
Camera *						Renderer::activeCamera = NULL;

void		Renderer::render(Window & window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (SceneNode * node : nodes)
	{
		node->render(window);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	window.display();
}

void		Renderer::registerEntity(SceneNode & node)
{
	nodes.push_back(&node);
}

void		Renderer::registerEntity(SceneNode * node)
{
	nodes.push_back(node);
}

void		Renderer::unregisterEntity(const SceneNode & node)
{
	std::vector<SceneNode *>::const_iterator	it;

	it = std::find(nodes.cbegin(), nodes.cend(), &node);

	if (it != nodes.cend())
		nodes.erase(it);
}
