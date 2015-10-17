//             .-'''''-.
//           .'         `.
//          :             :   File       : State.cpp
//         :               :  Creation   : 2015-10-13 20:44:32
//         :      _/|      :  Last Edit  : 2015-10-17 07:45:23
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <memory>

#include "Core/State.hpp"
#include "Core/StateStack.hpp"

State::Context::Context(Window & window) :
	window(&window)
{
}

State::State(StateStack & stack, Context context) :
	_stack(&stack),
	_context(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
	_stack->pushState(stateID);
}

void State::requestStackPop()
{
	_stack->popState();
}

void State::requestStateClear()
{
	_stack->clearStates();
}

State::Context State::getContext() const
{
	return _context;
}
