//             .-'''''-.
//           .'         `.
//          :             :   File       : TestState.cpp
//         :               :  Creation   : 2015-10-17 07:50:58
//         :      _/|      :  Last Edit  : 2015-10-18 04:25:15
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <memory>

#include "Game/States/TestState.hpp"
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/Renderer.hpp"

TestState::TestState(StateStack & stateStack, State::Context & context) :
	State(stateStack, context),
	root(new CubeEntity())
{
	root->transform.position.set(2.f, 0, -20.f);
	root->transform.scale = 10.f;
	root->move = true;

	Renderer::registerEntity(*root);
	std::unique_ptr<CubeEntity>	cube2(new CubeEntity());

	cube2->transform.position.x = 3.f;
	cube2->move = false;

	Renderer::registerEntity(cube2.get());
	root->attachChild(std::move(cube2));
}

void	TestState::render()
{
	Renderer::render(*context.window);
}

bool	TestState::update(sf::Time dt)
{
	root->updateNode(dt);
	return false;
}

bool	TestState::handleEvent(const sf::Event &)
{
	return false;
}