//             .-'''''-.
//           .'         `.
//          :             :   File       : Game.cpp
//         :               :  Creation   : 2015-10-17 08:10:26
//         :      _/|      :  Last Edit  : 2015-10-27 22:19:26
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Game/Game.hpp"
#include "Game/States/LevelState.hpp"

using namespace Fothon;

Game::Game() :
	Application(640, 480, "Bomberman")
{}

void	Game::init()
{
	Application::init();

	_registerStates();
	stateStack.pushState(States::LevelState);
}

void	Game::_registerStates()
{
	stateStack.registerState<LevelState>(States::LevelState);
}

