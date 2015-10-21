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
#include "Graphics/Light.hpp"
#include "Graphics/Camera.hpp"
#include "Utils/MathUtil.hpp"

TestState::TestState(StateStack & stateStack, State::Context & context) :
	State(stateStack, context),
	root(new CubeEntity())
{
	root->transform.position.set(0, 0, -10.f);
	root->transform.scale = 1.f;
	root->move = true;
	Renderer::registerNode(*root);

	std::unique_ptr<CubeEntity>	cube2(new CubeEntity());
	cube2->transform.position.set(3.f, 0, 0);
	cube2->transform.scale = 0.5f;
	cube2->move = false;
	Renderer::registerNode(*cube2.get());
	root->attachChild(std::move(cube2));

	std::unique_ptr<CubeEntity>	cube3(new CubeEntity());
	cube3->transform.position.set(-3.f, 0, 0);
	cube3->transform.scale = 0.5f;
	cube3->move = false;
	Renderer::registerNode(*cube3.get());
	root->attachChild(std::move(cube3));

	Light *	light1 = new Light(Vec3(0, 1.f, 0));
	light1->transform.position.set(10.f, -5.f, -5.f);
	Renderer::registerNode(*light1);

	Light *	light2 = new Light(Vec3(1.f, 0, 0));
	light2->transform.position.set(-10.f, -5.f, -5.f);
	Renderer::registerNode(*light2);

	Light *	light3 = new Light(Vec3(0, 0, 1.f));
	light3->transform.position.set(0.f, 5.f, -5.f);
	Renderer::registerNode(*light3);
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
