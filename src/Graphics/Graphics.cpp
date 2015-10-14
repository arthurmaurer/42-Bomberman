
#include "Graphics\Graphics.hpp"
#include "Utils/MathUtil.hpp"
#include "Graphics\ShaderProgram.hpp"
#include "Matrix4.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include <algorithm>

sf::Window *				Graphics::window = NULL;
bool						Graphics::running = false;
std::vector<const Entity *>	Graphics::entities;
unsigned					Graphics::width = 0;
unsigned					Graphics::height = 0;
Matrix4						Graphics::projectionMatrix;
const ShaderProgram *		Graphics::shaderProgram = NULL;
Camera						Graphics::camera;

Graphics &		Graphics::operator=(const Graphics & rhs)
{
	(void)rhs;
	return *this;
}

sf::Window &	Graphics::createWindow(unsigned windowWidth, unsigned windowHeight)
{
	sf::ContextSettings	settings;

	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	width = windowWidth;
	height = windowHeight;

	window = new sf::Window(sf::VideoMode(width, height), "Bomberman");

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Glew broken" << std::endl;
		exit(EXIT_FAILURE);
	}

	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, width, height);

	projectionMatrix = Matrix4::getPerspective(MathUtil::degToRad(45.f), (float)width / height, 1.0f, 10.f);

	running = true;

	return *window;
}

void			Graphics::unload()
{
	if (running)
		stop();

	delete window;
	window = NULL;
}

void			Graphics::stop()
{
	window->close();
	running = false;
}

void			Graphics::setTitle(std::string title)
{
	window->setTitle(title);
}

void			Graphics::registerEntity(Entity & entity)
{
	entities.push_back(&entity);
}

void			Graphics::unregisterEntity(const Entity & entity)
{
	std::vector<const Entity *>::const_iterator	it;

	it = std::find(entities.cbegin(), entities.cend(), &entity);

	if (it != entities.cend())
		entities.erase(it);
}

void			Graphics::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (const Entity * entity : entities)
	{
		if (!entity->active)
			continue;

		renderEntity(*entity);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	window->display();
}

void	Graphics::renderEntity(const Entity & entity)
{
	Matrix4		model;
	Matrix4		view;
	Matrix4		mvp;

	model.setFromTransform(entity.transform);
	view.setFromInversedTransform(camera.transform);
	mvp = projectionMatrix * view * model;
	shaderProgram->loadUniform("mvp", mvp);

	glBindVertexArray(entity.model->vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, entity.model->vboID);

	if (entity.model->texture != NULL)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, entity.model->texture->id);
	}

	glDrawElements(GL_TRIANGLES, entity.model->indexCount, GL_UNSIGNED_INT, (void*)0);
}
