//             .-'''''-.
//           .'         `.
//          :             :   File       : TestState.cpp
//         :               :  Creation   : 2015-10-17 07:50:58
//         :      _/|      :  Last Edit  : 2015-10-17 08:04:03
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Game/States/TestState.hpp"
#include "Game/Entities/CubeEntity.hpp"
#include "Graphics/Renderer.hpp"

TestState::TestState(StateStack & stateStack, State::Context & context) :
	State(stateStack, context)
{
	CubeEntity *	cube;

	cube = new CubeEntity();
	cube->transform.position.z = -20.f;
	cube->transform.rotation.rotateX(50.f);
	cube->transform.rotation.rotateY(50.f);
	cube->transform.rotation.rotateZ(50.f);

	Renderer::registerEntity(*cube);
}

void	TestState::draw()
{
}

bool	TestState::update(sf::Time)
{
	return false;
}

bool	TestState::handleEvent(const sf::Event &)
{
	return false;
}
