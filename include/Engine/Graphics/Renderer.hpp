
#ifndef _RENDERER_HPP
# define _RENDERER_HPP

# include <vector>
# include <functional>

namespace Fothon
{
	class Renderable;
	class SFMLNode;
	class ModelNode;
	class Window;
	class Camera;
	class ShaderProgram;
	class Light;
	class Matrix4;

	class Renderer
	{
		static void			_noCamera(Window & window);
		static void			_renderModelNodes(Window & window);
		static void			_renderSFMLNodes(Window & window);

	public:
		static std::function<void(Window &)>	noCameraHandler;
		static std::vector<SFMLNode *>			sfmlNodes;
		static std::vector<ModelNode *>			modelNodes;
		static std::vector<Light *>				lightNodes;

		static const ShaderProgram *		shaderProgram;
		static Camera *						activeCamera;
		static Matrix4						projectionMatrix;
		static bool							updateProjectionMatrix;

		static void			clear(Window & window);
		static void			display(Window & window);
		static void			render(Window & window);

		static void			registerNode(Light & node);
		static void			unregisterNode(const Light & node);

		static void			registerNode(SFMLNode & node);
		static void			unregisterNode(const SFMLNode & node);

		static void			registerNode(ModelNode & node);
		static void			unregisterNode(const ModelNode & node);

		static Matrix4 &	getProjectionMatrix(const Window & window);
	};
}

#endif /* _RENDERER_HPP */
