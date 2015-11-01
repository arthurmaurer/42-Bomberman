//             .-'''''-.
//           .'         `.
//          :             :   File       : CommandQueue.hpp
//         :               :  Creation   : 2015-10-05 06:23:16
//         :      _/|      :  Last Edit  : 2015-10-17 08:52:21
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _COMMAND_QUEUE_HPP
# define _COMMAND_QUEUE_HPP

# include <ostream>
# include <queue>

# include "Engine/Core/Command.hpp"

namespace Fothon
{
	class				CommandQueue
	{
	public:
		void			push(const Command &);
		Command			pop();
		bool			isEmpty() const;

	private:
		std::queue<Command>	_queue;
	};
}

#endif /* _COMMAND_QUEUE_HPP */
