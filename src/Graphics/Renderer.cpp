
#include "Graphics/Renderer.hpp"
#include "Utils/MathUtil.hpp"
#include "Graphics/Graphics.hpp"

std::vector<const Entity *>		Renderer::entities;
const ShaderProgram *			Renderer::shaderProgram = NULL;

Matrix4		Renderer::projectionMatrix = Matrix4::getPerspective(
	MathUtil::degToRad(Graphics::fov),
	1200.f / 800.f,
	1.0f,
	1000.f
);

void		Renderer::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (const Entity * entity : entities)
	{
		if (!entity->active)
			continue;

		renderEntity(*entity);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	Graphics::window->display();
}

void		Renderer::renderEntity(const Entity & entity)
{
	Matrix4		model;
	Matrix4		view;
	Matrix4		mvp;

	model.setFromTransform(entity.transform);
	view.setFromInversedTransform(Graphics::camera.transform);
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

void		Renderer::registerEntity(const Entity & entity)
{
	entities.push_back(&entity);
}

void		Renderer::unregisterEntity(const Entity & entity)
{
	std::vector<const Entity *>::const_iterator	it;

	it = std::find(entities.cbegin(), entities.cend(), &entity);

	if (it != entities.cend())
		entities.erase(it);
}
