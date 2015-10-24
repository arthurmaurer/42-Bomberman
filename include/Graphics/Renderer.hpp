
#ifndef _RENDERER_HPP
# define _RENDERER_HPP

# include <vector>

class SceneNode;
class Window;
class Camera;
class ShaderProgram;
class Light;
class Matrix4;

class Renderer
{
public:
	static std::vector<SceneNode *>		nodes;
	static const ShaderProgram *		shaderProgram;
	static Camera *						activeCamera;
	static std::vector<Light *>			lights;
	static Matrix4						projectionMatrix;
	static bool							updateProjectionMatrix;

	static void			clear(Window & window);
	static void			display(Window & window);
	static void			render(Window & window);

	static void			registerNode(SceneNode & node);
	static void			unregisterNode(const SceneNode & node);

	static Matrix4 &	getProjectionMatrix(const Window & window);
};

#endif /* _RENDERER_HPP */
