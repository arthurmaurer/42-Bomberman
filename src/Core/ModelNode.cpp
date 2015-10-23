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

ModelNode::ModelNode(Model & model) :
	SceneNode(),
	model(&model)
{}

void	ModelNode::render(Window & window)
{
	Matrix4		mvp;
	Matrix4		modelMatrix;
	Matrix4		viewMatrix;
	Matrix4		projMatrix = Matrix4::getPerspective(
		MathUtil::rad(Renderer::activeCamera->fovY),
		window.width / static_cast<float>(window.height),
		1.0f,
		1000.f
	);

	modelMatrix.setFromTransform(absoluteTransform);
	viewMatrix.setFromInversedTransform(Renderer::activeCamera->transform);
	mvp = projMatrix * viewMatrix * modelMatrix;
	Renderer::shaderProgram->loadUniform("mvp", mvp);

	glBindVertexArray(model->vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, model->vboID);

	if (model->texture != NULL)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, model->texture->id);
	}

	glDrawElements(GL_TRIANGLES, model->indexCount, GL_UNSIGNED_INT, (void*)0);
}
