
#include "Game/Entities/DestructibleBlock.hpp"
#include "Tools/ModelGenerator.hpp"
#include "Tools/TextureManager.hpp"
#include "Graphics/Model.hpp"

DestructibleBlock::DestructibleBlock()
{
	model->texture = &TextureManager::load("character", "cube.jpg");
}

DestructibleBlock::DestructibleBlock(unsigned hp, ModelNode & content) :
	Block(ModelGenerator::generateCube({ 1.f, 1.f, 1.f })),
	hp(hp),
	content(&content)
{}
