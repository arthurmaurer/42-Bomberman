
#ifndef _LEVEL_STATE_HPP
# define _LEVEL_STATE_HPP

# include "Engine/Core/Nodes/SceneNode.hpp"
# include "Engine/Core/State.hpp"

class Level;

class LevelState : public Fothon::State
{
public:
	Fothon::SceneNode::Ptr	rootNode;
	Level *			level = nullptr;

	LevelState(Fothon::StateStack & stateStack, Fothon::State::Context & context);

	void	render();
	bool	update(sf::Time dt);
	bool	handleEvent(const sf::Event & event);
};

#endif /* _LEVEL_STATE_HPP*/
