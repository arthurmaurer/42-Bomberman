//             .-'''''-.
//           .'         `.
//          :             :   File       : ModelNode.hpp
//         :               :  Creation   : 2015-10-18 01:23:48
//         :      _/|      :  Last Edit  : 2015-10-18 03:14:40
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _MODEL_NODE_HPP
# define _MODEL_NODE_HPP

# include <memory>

# include "Engine/Core/Nodes/SceneNode.hpp"
# include "Engine/Graphics/Renderable.hpp"

class Model;

class ModelNode :	public SceneNode,
					public Renderable
{
private:
	void		_uploadUniforms(const Window & window) const;

public:
	Model *		model = nullptr;

	ModelNode() = default;
	ModelNode(Model & model);

	void		render(Window & window);
};

#endif /* _MODEL_NODE_HPP */
