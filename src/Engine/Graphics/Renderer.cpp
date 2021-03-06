
#include <stdio.h>
#include <iostream>

#include <SFML/Graphics/Texture.hpp>

#include "Engine/Core/Matrix4.hpp"
#include "Engine/Core/Nodes/ModelNode.hpp"
#include "Engine/Core/Nodes/SFMLNode.hpp"
#include "Engine/Core/Nodes/SceneNode.hpp"
#include "Engine/Core/Nodes/SpriteNode.hpp"
#include "Engine/Graphics/ShaderProgram.hpp"
#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/Light.hpp"
#include "Engine/Graphics/Window.hpp"
#include "Engine/Graphics/Camera.hpp"
#include "Engine/Tools/MathUtil.hpp"

using namespace Fothon;

std::function<void(Window &)>	Renderer::noCameraHandler = Renderer::_noCamera;
std::vector<SFMLNode *>			Renderer::sfmlNodes;
std::vector<ModelNode *>		Renderer::modelNodes;
std::vector<Light *>			Renderer::lightNodes;

const ShaderProgram *			Renderer::shaderProgram = nullptr;
Camera *						Renderer::activeCamera = nullptr;
Matrix4							Renderer::projectionMatrix;
bool							Renderer::updateProjectionMatrix = true;

void		Renderer::clear(Window &)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void		Renderer::display(Window & window)
{
	window.display();
}

void		Renderer::_noCamera(Window & window)
{
	sf::Texture	texture;
	SpriteNode	spriteNode(texture, false);

	window.resetGLState();

	texture.loadFromFile("resources/nocamera.png");
	spriteNode.absoluteTransform.scale.x = (float)window.window.getSize().x / texture.getSize().x;
	spriteNode.absoluteTransform.scale.y = (float)window.window.getSize().y / texture.getSize().y;
	spriteNode.render(window);

	window.restoreGLState();
}

void		Renderer::_renderModelNodes(Window & window)
{
	if (activeCamera == nullptr)
		return noCameraHandler(window);

	shaderProgram->enable();

	for (ModelNode * node : modelNodes)
	{
		if (node->visible)
			node->render(window);
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	shaderProgram->disable();
}

void		Renderer::_renderSFMLNodes(Window & window)
{
	window.resetGLState();

	for (SFMLNode * node : sfmlNodes)
	{
		if (node->visible)
			node->render(window);
	}

	window.restoreGLState();
}

void		Renderer::render(Window & window)
{
	clear(window);

	_renderModelNodes(window);
	_renderSFMLNodes(window);
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
