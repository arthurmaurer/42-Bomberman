
#ifndef _RENDERER_H
# define _RENDERER_H

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
	static const Camera *				activeCamera;

	static void		render(Window & window);

	static void		registerEntity(SceneNode & node);
	static void		registerEntity(SceneNode * node);
	static void		unregisterEntity(const SceneNode & node);
};

#endif
