//             .-'''''-.
//           .'         `.
//          :             :   File       : State.hpp
//         :               :  Creation   : 2015-10-11 18:58:24
//         :      _/|      :  Last Edit  : 2015-10-17 07:56:52
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _STATE_HPP
# define _STATE_HPP

# include <SFML/Graphics/RenderWindow.hpp>

# include "Graphics/Window.hpp"
# include "Game/States/StateIdentifiers.hpp"

class		StateStack;

class		State
{
public:
	typedef	std::unique_ptr<State>	Ptr;

	struct	Context
	{
		Context(Window & window);

		Window *	window = NULL;
	};

	State(StateStack & stateStack, Context context);
	virtual	~State();

	virtual void	draw() = 0;
	virtual bool	update(sf::Time dt) = 0;
	virtual bool	handleEvent(const sf::Event & event) = 0;

protected:
	void			requestStackPush(States::ID stateID);
	void			requestStackPop();
	void			requestStateClear();

	Context			getContext() const;

private:
	StateStack *	_stack;
	Context			_context;
};

#endif /* _STATE_HPP */
