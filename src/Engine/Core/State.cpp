//             .-'''''-.
//           .'         `.
//          :             :   File       : State.cpp
//         :               :  Creation   : 2015-10-13 20:44:32
//         :      _/|      :  Last Edit  : 2015-10-18 03:22:55
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <memory>

#include "Engine/Core/State.hpp"
#include "Engine/Core/StateStack.hpp"

State::Context::Context(Window & window, Application & app) :
	window(&window),
	app(app)
{}

State::State(StateStack & stack, Context context) :
	stack(&stack),
	context(context)
{}

State::~State()
{}

void State::requestStackPush(States::ID stateID)
{
	stack->pushState(stateID);
}

void State::requestStackPop()
{
	stack->popState();
}

void State::requestStateClear()
{
	stack->clearStates();
}
