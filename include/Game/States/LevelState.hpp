
#ifndef _LEVEL_STATE_HPP
# define _LEVEL_STATE_HPP

# include "Core/SceneNode.hpp"
# include "Core/State.hpp"

class Level;

class LevelState : public State
{
public:
	SceneNode::Ptr	rootNode;
	Level *			level = nullptr;

	LevelState(StateStack & stateStack, State::Context & context);

	void	render();
	bool	update(sf::Time dt);
	bool	handleEvent(const sf::Event & event);
};

#endif /* _LEVEL_STATE_HPP*/
