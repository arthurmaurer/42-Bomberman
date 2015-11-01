//             .-'''''-.
//           .'         `.
//          :             :   File       : SceneNode.hpp
//         :               :  Creation   : 2015-09-10 10:46:31
//         :      _/|      :  Last Edit  : 2015-10-18 04:27:47
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _SCENE_NODE_HPP
# define _SCENE_NODE_HPP

# include <ostream>
# include <vector>
# include <memory>

# include <SFML/System/Time.hpp>

# include "Engine/Core/Transformable.hpp"
# include "Engine/Core/NonCopyable.hpp"
# include "Engine/Graphics/Window.hpp"

namespace Fothon
{
	struct Command;

	class SceneNode :	public Transformable,
						private NonCopyable
	{
	public:
		typedef std::unique_ptr<SceneNode>	Ptr;

		std::vector<Ptr>	children;
		SceneNode *			parent = nullptr;

		SceneNode();

		void				attachChild(Ptr node);
		Ptr					detachChild(const SceneNode & node);
		void				updateNode(sf::Time dt);

		void				onCommand(const Command & command, sf::Time dt);
		virtual unsigned	getCategory() const;

		virtual void		update(sf::Time dt);

	private:
		void				_updateChildren(sf::Time dt);
	};
}

#endif /* _SCENE_NODE_HPP */
