

#ifndef _SFML_NODE_HPP
# define _SFML_NODE_HPP

# include <memory>

# include "Engine/Core/Nodes/SceneNode.hpp"
# include "Engine/Graphics/Model.hpp"
# include "Engine/Graphics/Renderable.hpp"

namespace Fothon
{
	class SFMLNode :	public SceneNode,
						public Renderable
	{
	public:
		SFMLNode();

		void		render(Window & window);
	};
}

#endif /* _SFML_NODE_HPP */
