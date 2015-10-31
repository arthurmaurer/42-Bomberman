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

#include "Game/States/LevelState.hpp"
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/Light.hpp"
#include "Graphics/Camera.hpp"
#include "Tools//MathUtil.hpp"
#include "Game/Entities/Character.hpp"
#include "Tools/ModelGenerator.hpp"
#include "Tools/TextureManager.hpp"
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
	Renderer::registerNode(*cube);

	Light *	light1 = new Light(Light::Point, Vec3(1.f, 1.f, 1.f));
	light1->transform.position = { 0, 0, 0 };
	light1->updateNode(sf::Time());
	Renderer::registerNode(*light1);

	cube = new CubeEntity();
	cube->transform.position = light1->transform.position;
	cube->transform.scale = { 0.2f, 0.2f, 0.2f };
	cube->model->texture = &TextureManager::load("ok", "texture.jpg");
	cube->updateNode(sf::Time());
	Renderer::registerNode(*cube);
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
