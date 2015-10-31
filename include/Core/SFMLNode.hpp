

#ifndef _SFML_NODE_HPP
# define _SFML_NODE_HPP

# include <memory>

# include "Core/SceneNode.hpp"
# include "Graphics/Model.hpp"
# include "Core/Renderable.hpp"

class SFMLNode :	public SceneNode,
					public Renderable
{
public:
	SFMLNode();

	void		render(Window & window);
};

#endif /* _SFML_NODE_HPP */
