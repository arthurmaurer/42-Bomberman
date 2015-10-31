//             .-'''''-.
//           .'         `.
//          :             :   File       : State.hpp
//         :               :  Creation   : 2015-10-11 18:58:24
//         :      _/|      :  Last Edit  : 2015-10-18 03:23:37
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _STATE_HPP
# define _STATE_HPP

# include <memory>

# include "Graphics/Window.hpp"
# include "Game/States/StateIdentifiers.hpp"
// TODO: Importing a header from Game to Core ?..

class StateStack;
class Application;

class State
{
public:
	typedef	std::unique_ptr<State>	Ptr;

	struct	Context
	{
		Context(Window & window, Application & app);

		Window *		window = NULL;
		Application &	app;
	};

	StateStack *	stack;
	Context			context;

	State(StateStack & stateStack, Context context);
	virtual	~State();

	virtual void	render() = 0;
	virtual bool	update(sf::Time dt) = 0;
	virtual bool	handleEvent(const sf::Event & event) = 0;

protected:
	void			requestStackPush(States::ID stateID);
	void			requestStackPop();
	void			requestStateClear();
};

#endif /* _STATE_HPP */
