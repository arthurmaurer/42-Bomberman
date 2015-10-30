
# include <stdio.h>
# include <iostream>

#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Renderer.hpp"
#include "Tools/MathUtil.hpp"
#include "Core/SceneNode.hpp"
#include "Graphics/Light.hpp"
#include "Matrix4.hpp"
#include "Graphics/Window.hpp"
#include "Graphics/Camera.hpp"

std::vector<SceneNode *>	Renderer::nodes;
const ShaderProgram *		Renderer::shaderProgram = nullptr;
Camera *					Renderer::activeCamera = nullptr;
std::vector<Light *>		Renderer::lights;
Matrix4						Renderer::projectionMatrix;
bool						Renderer::updateProjectionMatrix = true;

void		Renderer::clear(Window &)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void		Renderer::display(Window & window)
{
	window.display();
}

void		Renderer::render(Window & window)
{
	clear(window);

	shaderProgram->enable();

	for (SceneNode * node : nodes)
		node->render(window);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	shaderProgram->disable();
}

void		Renderer::registerNode(SceneNode & node)
{
	Light *	lightPtr = dynamic_cast<Light *>(&node);

	if (lightPtr != nullptr)
		lights.push_back(lightPtr);

	nodes.push_back(&node);
}

void		Renderer::unregisterNode(const SceneNode & node)
{
	std::vector<SceneNode *>::iterator	nodeIt;
	std::vector<Light *>::iterator		lightIt;

	nodeIt = std::find(nodes.begin(), nodes.end(), &node);

	if (nodeIt != nodes.end())
		nodes.erase(nodeIt);

	lightIt = std::find(lights.begin(), lights.end(), &node);

	if (lightIt != lights.end())
		lights.erase(lightIt);
}

Matrix4 &	Renderer::getProjectionMatrix(const Window & window)
{
	if (updateProjectionMatrix)
	{
		projectionMatrix = Matrix4::getPerspective(
			MathUtil::rad(activeCamera->fovY),
			window.width / (float)window.height,
			activeCamera->nearPlane,
			activeCamera->farPlane
		);

		updateProjectionMatrix = false;
	}

	return projectionMatrix;
}
