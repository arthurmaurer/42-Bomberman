
#ifndef _LIGHT_HPP
# define _LIGHT_HPP

# include "Engine/Core/Nodes/SceneNode.hpp"
# include "Engine/Core/Vec2.hpp"

namespace Fothon
{
	class Light : public SceneNode
	{
	public:
		enum class	LightType
		{
			None,
			Point,
			Directional,
			Spot,
			Ambient
		};

		LightType	type = LightType::None;
		Vec3		ambient;
		Vec3		diffuse;
		Vec3		specular;
		Vec2		attenuation;

		Light(LightType type);
		Light(LightType type, const Vec3 & color);
	};
}

#endif /* _LIGHT_HPP */
