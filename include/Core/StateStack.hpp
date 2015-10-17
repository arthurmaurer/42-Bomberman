//             .-'''''-.
//           .'         `.
//          :             :   File       : StateStack.hpp
//         :               :  Creation   : 2015-10-11 18:42:52
//         :      _/|      :  Last Edit  : 2015-10-17 07:59:05
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _STATESTACK_HPP
# define _STATESTACK_HPP

# include <map>
# include <functional>

# include "Core/State.hpp"

class		StateStack
{
public:
	enum	Action
	{
		Pop,
		Push,
		Clear
	};

	explicit	StateStack(State::Context context);

	template<typename T>
	void		registerState(States::ID stateID);

	void		update(sf::Time dt);
	void		draw();
	void		handleEvent(const sf::Event & event);

	void		pushState(States::ID stateID);
	void		popState();
	void		clearStates();

	bool		isEmpty() const;

private:
	struct			PendingChange
	{
		explicit	PendingChange(Action action, States::ID stateID = States::None);
		Action		action;
		States::ID	stateID;
	};

	State::Ptr	createState(States::ID stateID);
	void		applyPendingChanges();

	std::vector<State::Ptr>								_stack;
	std::vector<PendingChange>							_pendingList;
	State::Context										_context;
	std::map<States::ID, std::function<State::Ptr()>>	_factories;
};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
	_factories[stateID] = [this] ()
	{
		return State::Ptr(new T(*this, _context));
	};
}

#endif /* _STATE_STACK_HPP */
