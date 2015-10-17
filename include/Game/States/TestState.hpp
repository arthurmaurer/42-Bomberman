//             .-'''''-.
//           .'         `.
//          :             :   File       : TestState.hpp
//         :               :  Creation   : 2015-10-17 07:52:05
//         :      _/|      :  Last Edit  : 2015-10-17 08:02:03
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _TEST_STATE_HPP
# define _TEST_STATE_HPP

# include "Core/State.hpp"

class TestState : public State
{
public:
	TestState(StateStack & stateStack, State::Context & context);

	void	draw();
	bool	update(sf::Time dt);
	bool	handleEvent(const sf::Event & event);
};

#endif /* _TEST_STATE_HPP */
