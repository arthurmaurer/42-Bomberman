//             .-'''''-.
//           .'         `.
//          :             :   File       : Game.cpp
//         :               :  Creation   : 2015-10-17 08:10:26
//         :      _/|      :  Last Edit  : 2015-10-17 08:13:57
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Game/Game.hpp"
#include "Game/States/TestState.hpp"

Game::Game() :
	Application()
{}

void	Game::init()
{
	Application::init();

	_registerStates();
	stateStack.pushState(States::Test);
}

void	Game::_registerStates()
{
	stateStack.registerState<TestState>(States::Test);
}

