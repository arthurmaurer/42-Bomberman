//             .-'''''-.
//           .'         `.
//          :             :   File       : TestState.cpp
//         :               :  Creation   : 2015-10-17 07:50:58
//         :      _/|      :  Last Edit  : 2015-10-23 22:15:57
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <memory>

#include "Engine/Tools.hpp"
#include "Engine/Graphics.hpp"
#include "Engine/Core.hpp"

#include "Game/States/LevelState.hpp"
#include "Game/Entities/CubeEntity.hpp"
#include "Game/Levels/Level00.hpp"

LevelState::LevelState(StateStack & stateStack, State::Context & context) :
	State(stateStack, context),
	rootNode(new SceneNode())
{
	CubeEntity *	cube;
	
	cube = new CubeEntity();
	cube->transform.position.x = -3.f;
	cube->updateNode(sf::Time());
	Renderer::registerNode(*cube);

	cube = new CubeEntity();
	cube->transform.position.x = 3.f;
	cube->updateNode(sf::Time());

	Light *	light1 = new Light(Light::LightType::Point, Vec3(1.f, 1.f, 1.f));
	light1->transform.position = { 0, 0, 0 };
	light1->updateNode(sf::Time());

	light1 = new Light(Light::LightType::Directional, Vec3(1.f, 0, 1.f));
	light1->transform.rotation.rotateZ(MathUtil::rad(-30.f));
	light1->updateNode(sf::Time());

	TextNode::Ptr	text(new TextNode("Salut les mecs", context.app._statsFont));
	text->transform.position = { 50, 50, 50 };
	rootNode->attachChild(std::move(text));

	sf::Texture *	texture = new sf::Texture();
	texture->loadFromFile("resources/dude.jpg");
	SpriteNode::Ptr	sprite(new SpriteNode(*texture));
	sprite->transform.position = { 20, 100, 0 };
	sprite->transform.scale = { 0.2f, 0.2f, 1.f };
	sprite->transform.rotation.rotateZ(MathUtil::rad(45.f));
	rootNode->attachChild(std::move(sprite));
}

void	LevelState::render()
{
	Renderer::render(*context.window);
}

bool	LevelState::update(sf::Time dt)
{
	rootNode->updateNode(dt);
	return false;
}

bool	LevelState::handleEvent(const sf::Event &)
{
	return false;
}
