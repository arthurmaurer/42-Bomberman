//             .-'''''-.
//           .'         `.
//          :             :   File       : ModelNode.cpp
//         :               :  Creation   : 2015-10-18 01:35:20
//         :      _/|      :  Last Edit  : 2015-10-19 00:41:12
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Core/ModelNode.hpp"
#include "Matrix4.hpp"
#include "Tools/MathUtil.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/Camera.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Graphics/Light.hpp"
#include "Graphics/Model.hpp"
#include "Graphics/Texture.hpp"

ModelNode::ModelNode(Model & model) :
	SceneNode(),
	model(&model)
{
	Renderer::registerNode(*this);
}

void	ModelNode::_uploadUniforms(const Window & window) const
{
	Matrix4		mvp;
	Matrix4		modelMatrix;
	Matrix4		viewMatrix;
	Matrix4		modelViewMatrix;
	Matrix4 &	projMatrix = Renderer::getProjectionMatrix(window);

	modelMatrix.setFromTransform(absoluteTransform);
	viewMatrix.setFromTransform(Renderer::activeCamera->transform);
	viewMatrix = viewMatrix.inverse();
	modelViewMatrix = viewMatrix * modelMatrix;
	mvp = projMatrix * modelViewMatrix;

	Renderer::shaderProgram->loadUniform("mvp", mvp);
	Renderer::shaderProgram->loadUniform("modelViewMatrix", modelViewMatrix);
	Renderer::shaderProgram->loadUniform("viewMatrix", viewMatrix);
	Renderer::shaderProgram->loadUniform("modelMatrix", modelMatrix);
	Renderer::shaderProgram->loadNormalMatrixUniform("normalMatrix", modelViewMatrix);

	for (unsigned i = 0; i < Renderer::lightNodes.size(); i++)
		Renderer::shaderProgram->loadUniform("lights", *Renderer::lightNodes.at(i), i);
}

void	ModelNode::render(Window & window)
{
	_uploadUniforms(window);

	glBindVertexArray(model->vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, model->vboID);
	
	if (model->texture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, model->texture->id);
	}

	glDrawElements(GL_TRIANGLES, model->indexCount, GL_UNSIGNED_INT, (void*)0);

	if (model->texture != nullptr)
		glBindTexture(GL_TEXTURE_2D, 0);
}
