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

# include "Core/SceneNode.hpp"
# include "Graphics/Model.hpp"

class ModelNode : public SceneNode
{
private:
	void		_uploadUniforms(const Window & window) const;

public:
	typedef std::unique_ptr<SceneNode>	Ptr;

	Model *		model = nullptr;

	ModelNode() = default;
	ModelNode(Model & model);

	void		render(Window & window);
};

#endif /* _MODEL_NODE_HPP */
