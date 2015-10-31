
#include "Engine/Graphics/ImageBuffer.hpp"
#include "Engine/Graphics/Model.hpp"
#include "Engine/Tools/ModelGenerator.hpp"
#include "Engine/Tools/TextureManager.hpp"

#include "Game/Entities/Block.hpp"

Block::Block() :
	ModelNode(ModelGenerator::generateCube(Vec3(1.f, 1.f, 1.f)))
{
	/*
	ImageBuffer	imageBuffer(1, 1);
	imageBuffer.data[0] = 0xff0000;
	*/
	model->texture = &TextureManager::load("block", "cube.jpg");
}

Block::Block(Model & model) :
	ModelNode(model)
{}
