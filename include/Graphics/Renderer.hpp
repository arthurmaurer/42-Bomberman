
#ifndef _RENDERER_HPP
# define _RENDERER_HPP

# include "Matrix4.hpp"
# include "Graphics/ShaderProgram.hpp"
# include "Graphics\Camera.hpp"
# include "Graphics\Window.hpp"
# include <vector>

class SceneNode;

class Renderer
{
public:
	static std::vector<SceneNode *>		nodes;
	static const ShaderProgram *		shaderProgram;
	static Camera *						activeCamera;

	static void		render(Window & window);

	static void		registerEntity(SceneNode & node);
	static void		registerEntity(SceneNode * node);
	static void		unregisterEntity(const SceneNode & node);
};

#endif /* _RENDERER_HPP */
