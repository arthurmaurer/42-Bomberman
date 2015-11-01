//             .-'''''-.
//           .'         `.
//          :             :   File       : CameraNode.hpp
//         :               :  Creation   : 2015-11-01 08:11:46
//         :      _/|      :  Last Edit  : 2015-11-01 10:00:05
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _CAMERA_NODE_HPP
# define _CAMERA_NODE_HPP

# include <ostream>

# include "Engine/Core/Nodes/SceneNode.hpp"
# include "Engine/Graphics/Camera.hpp"

namespace Fothon
{
	class CameraNode :	public SceneNode,
						public Camera
	{
	public:

		float	moveSpeed;
		float	lookSpeed;

				CameraNode(float fovY, float moveSpeed = 0.1f, float lookSpeed = 0.01f);
		bool	isActive() const;
		void	setActive(bool active);
		void	update(sf::Time dt);
	};
}

#endif /* _CAMERA_NODE_HPP */
