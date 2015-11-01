//             .-'''''-.
//           .'         `.
//          :             :   File       : LevelState.cpp
//         :               :  Creation   : 2015-10-17 07:50:58
//         :      _/|      :  Last Edit  : 2015-11-01 09:48:47
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

using namespace Fothon;

LevelState::LevelState(StateStack & stateStack, State::Context & context) :
	State(stateStack, context),
	rootNode(new SceneNode())
{
	//Renderer::activeCamera = new Camera(45.f);
	//Renderer::activeCamera->transform.position.z = 10.f;

	CubeEntity *	cube;

	cube = new CubeEntity();
	cube->transform.position.x = -3.f;
	cube->updateNode(sf::Time());

	cube = new CubeEntity();
	cube->transform.position.x = 3.f;
	cube->updateNode(sf::Time());

	Light *	light1 = new Light(Light::LightType::Point, Vec3(1.f, 1.f, 1.f));
	light1->transform.position = { 0, 0, 0 };
	light1->updateNode(sf::Time());

	light1 = new Light(Light::LightType::Directional, Vec3(1.f, 0, 1.f));
	light1->transform.rotation.rotateZ(MathUtil::rad(-30.f));
	light1->updateNode(sf::Time());

	CameraNode::Ptr	camera(new CameraNode(45.f));
	camera->transform.position.z = 10.f;
	rootNode->attachChild(std::move(camera));

	TextNode::Ptr	text(new TextNode("Salut les mecs", Resource::load<FontManager>("Main")));
	text->transform.position = { 50, 50, 50 };
	rootNode->attachChild(std::move(text));

	SpriteNode::Ptr	sprite(new SpriteNode(Resource::load<SFMLTextureManager>("Dude", "dude.jpg")));
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
