
#include "Graphics\Graphics.hpp"
#include "Utils/MathUtil.hpp"
#include "Graphics\ShaderProgram.hpp"
#include "Matrix4.hpp"
#include "ShaderProgram/DefaultProgram.hpp"
#include <algorithm>

std::vector<const Entity *>	Graphics::entities;
Matrix4						Graphics::projectionMatrix;
const ShaderProgram *		Graphics::shaderProgram = NULL;
Camera						Graphics::camera;
Window *					Graphics::window = NULL;

Window &	Graphics::createWindow(unsigned width, unsigned height)
{
	window = new Window(width, height, "Bomberman");
	projectionMatrix = Matrix4::getPerspective(MathUtil::degToRad(45.f), (float)width / height, 1.0f, 10.f);

	return *window;
}

void		Graphics::unload()
{
	delete window;
	window = NULL;
}

void		Graphics::registerEntity(Entity & entity)
{
	entities.push_back(&entity);
}

void		Graphics::unregisterEntity(const Entity & entity)
{
	std::vector<const Entity *>::const_iterator	it;

	it = std::find(entities.cbegin(), entities.cend(), &entity);

	if (it != entities.cend())
		entities.erase(it);
}

void		Graphics::render()
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

void		Graphics::renderEntity(const Entity & entity)
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
