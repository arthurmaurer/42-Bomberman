
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
#include "Core/ModelNode.hpp"
#include "Core/SFMLNode.hpp"

std::vector<SFMLNode *>		Renderer::sfmlNodes;
std::vector<ModelNode *>	Renderer::modelNodes;
std::vector<Light *>		Renderer::lightNodes;

const ShaderProgram *		Renderer::shaderProgram = nullptr;
Camera *					Renderer::activeCamera = nullptr;
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

void		Renderer::renderModelNodes(Window & window)
{
	shaderProgram->enable();

	for (ModelNode * node : modelNodes)
		node->render(window);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	shaderProgram->disable();
}

void		Renderer::renderSFMLNodes(Window & window)
{
	sf::RenderWindow &	win = window.window;

	win.pushGLStates();

	for (SFMLNode * node : sfmlNodes)
		node->render(window);

	win.popGLStates();
}

void		Renderer::render(Window & window)
{
	clear(window);

	renderModelNodes(window);
	renderSFMLNodes(window);
}

void		Renderer::registerNode(Light & node)
{
	lightNodes.push_back(&node);
}

void		Renderer::unregisterNode(const Light & node)
{
	std::vector<Light *>::iterator	it;

	it = std::find(lightNodes.begin(), lightNodes.end(), &node);

	if (it != lightNodes.end())
		lightNodes.erase(it);
}

void		Renderer::registerNode(SFMLNode & node)
{
	sfmlNodes.push_back(&node);
}

void		Renderer::unregisterNode(const SFMLNode & node)
{
	std::vector<SFMLNode *>::iterator	it;

	it = std::find(sfmlNodes.begin(), sfmlNodes.end(), &node);

	if (it != sfmlNodes.end())
		sfmlNodes.erase(it);
}

void		Renderer::registerNode(ModelNode & node)
{
	modelNodes.push_back(&node);
}

void		Renderer::unregisterNode(const ModelNode & node)
{
	std::vector<ModelNode *>::iterator	it;

	it = std::find(modelNodes.begin(), modelNodes.end(), &node);

	if (it != modelNodes.end())
		modelNodes.erase(it);
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
