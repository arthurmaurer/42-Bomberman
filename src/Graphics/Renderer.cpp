
#include "Graphics/Renderer.hpp"
#include "Utils/MathUtil.hpp"

std::vector<Entity *>		Renderer::entities;
const ShaderProgram *		Renderer::shaderProgram = NULL;
const Camera *				Renderer::activeCamera = NULL;

void		Renderer::render(Window & window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (const Entity * entity : entities)
	{
		if (!entity->active)
			continue;

		renderEntity(window, *entity);
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	window.display();
}

void		Renderer::renderEntity(const Window & window, const Entity & entity)
{
	Matrix4		model;
	Matrix4		view;
	Matrix4		mvp;
	Matrix4		proj = Matrix4::getPerspective(
		MathUtil::degToRad(activeCamera->fovY),
		window.width / static_cast<float>(window.height),
		1.0f,
		1000.f
	);

	model.setFromTransform(entity.transform);
	view.setFromInversedTransform(activeCamera->transform);
	mvp = proj * view * model;
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

void		Renderer::registerEntity(Entity & entity)
{
	entities.push_back(&entity);
}

void		Renderer::unregisterEntity(const Entity & entity)
{
	std::vector<Entity *>::const_iterator	it;

	it = std::find(entities.cbegin(), entities.cend(), &entity);

	if (it != entities.cend())
		entities.erase(it);
}
