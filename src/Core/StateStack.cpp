//             .-'''''-.
//           .'         `.
//          :             :   File       : StateStack.cpp
//         :               :  Creation   : 2015-10-11 18:43:38
//         :      _/|      :  Last Edit  : 2015-10-17 07:47:10
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <cassert>

#include "Core/StateStack.hpp"

StateStack::StateStack(State::Context context) :
	_context(context)
{
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID) :
	action(action),
	stateID(stateID)
{
}

void StateStack::handleEvent(const sf::Event & event)
{
	for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}
	applyPendingChanges();
}

void StateStack::update(sf::Time dt)
{
	for (auto itr = _stack.rbegin(); itr != _stack.rend(); ++itr)
	{
		if (!(*itr)->update(dt))
			break;
	}
	applyPendingChanges();
}

void StateStack::draw()
{
	for (auto & state : _stack)
		state->draw();
}

State::Ptr StateStack::createState(States::ID stateID)
{
	auto	found = _factories.find(stateID);

	assert(found != _factories.end());
	return found->second();
}

void	StateStack::applyPendingChanges()
{
	for (PendingChange change : _pendingList)
	{
		switch (change.action)
		{
			case Push:
				_stack.push_back(createState(change.stateID));
				break ;

			case Pop:
				_stack.pop_back();
				break ;

			case Clear:
				_stack.clear();
				break ;
		}
	}
	_pendingList.clear();
}

void StateStack::pushState(States::ID stateID)
{
	_pendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState()
{
	_pendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
	_pendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
	return _stack.empty();
}
