//             .-'''''-.
//           .'         `.
//          :             :   File       : TestState.hpp
//         :               :  Creation   : 2015-10-17 07:52:05
//         :      _/|      :  Last Edit  : 2015-10-18 04:02:00
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _TEST_STATE_HPP
# define _TEST_STATE_HPP

# include "Game/Entities/CubeEntity.hpp"
# include "Core/State.hpp"

class TestState : public State
{
public:
	TestState(StateStack & stateStack, State::Context & context);

	void	render();
	bool	update(sf::Time dt);
	bool	handleEvent(const sf::Event & event);

	CubeEntity::Ptr	root;
};

#endif /* _TEST_STATE_HPP */
