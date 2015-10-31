
#include "Engine/Graphics/Model.hpp"
#include "Engine/Tools/ModelGenerator.hpp"
#include "Engine/Tools/TextureManager.hpp"

#include "Game/Entities/DestructibleBlock.hpp"

DestructibleBlock::DestructibleBlock()
{
	model->texture = &TextureManager::load("character", "cube.jpg");
}

DestructibleBlock::DestructibleBlock(unsigned hp, ModelNode & content) :
	Block(ModelGenerator::generateCube({ 1.f, 1.f, 1.f })),
	hp(hp),
	content(&content)
{}
