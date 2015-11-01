//             .-'''''-.
//           .'         `.
//          :             :   File       : SceneNode.cpp
//         :               :  Creation   : 2015-09-10 10:46:49
//         :      _/|      :  Last Edit  : 2015-10-18 04:28:10
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <iostream>
#include <cassert>

#include "Engine/Core/Nodes/SceneNode.hpp"
#include "Engine/Core/Command.hpp"

#include "Game/Category.hpp"
// TODO: Include from Game in Engine ?

using namespace Fothon;

SceneNode::SceneNode() :
	children(),
	parent(nullptr)
{}

void		SceneNode::attachChild(Ptr child)
{
	child->parent = this;
	children.push_back(std::move(child));
}

SceneNode::Ptr	SceneNode::detachChild(const SceneNode & node)
{
	auto found = std::find_if(children.begin(), children.end(),
		[&] (Ptr & p) { return p.get() == &node; });

	assert(found != children.end());

	Ptr	result = std::move(*found);
	result->parent = nullptr;
	children.erase(found);

	return result;
}

void	SceneNode::updateNode(sf::Time dt)
{
	if (parent != nullptr)
		absoluteTransform = transform * parent->absoluteTransform;
	else
		absoluteTransform = transform;

	update(dt);
	_updateChildren(dt);
}

void			SceneNode::onCommand(const Command & command, sf::Time dt)
{
	if (command.category & getCategory())
		command.action(*this, dt);

	for (Ptr & child : children)
		child->onCommand(command, dt);
}

unsigned int	SceneNode::getCategory() const
{
	return Category::Scene;
}

void	SceneNode::update(sf::Time)
{
}

void	SceneNode::_updateChildren(sf::Time dt)
{
	for (const Ptr & child : children)
		child->updateNode(dt);
}
