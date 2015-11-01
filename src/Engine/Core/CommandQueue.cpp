//             .-'''''-.
//           .'         `.
//          :             :   File       : CommandQueue.cpp
//         :               :  Creation   : 2015-10-05 06:23:40
//         :      _/|      :  Last Edit  : 2015-10-17 08:56:49
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Engine/Core/CommandQueue.hpp"
#include "Engine/Core/Nodes/SceneNode.hpp"

using namespace Fothon;

void CommandQueue::push(const Command & command)
{
	_queue.push(command);
}

Command CommandQueue::pop()
{
	Command command = _queue.front();
	_queue.pop();
	return command;
}

bool CommandQueue::isEmpty() const
{
	return _queue.empty();
}
