
#include "Engine/Core/Vec2.hpp"
#include "Engine/Graphics/Light.hpp"
#include "Engine/Graphics/Renderer.hpp"

using namespace Fothon;

Light::Light(LightType type) :
	type(type),
	ambient(Vec3(1.f, 1.f, 1.f)),
	diffuse(ambient),
	specular(ambient),
	attenuation(Vec2(0, 0))
{
	Renderer::registerNode(*this);
}

Light::Light(LightType type, const Vec3 & color) :
	type(type),
	ambient(color),
	diffuse(color),
	specular(color),
	attenuation(Vec2(0, 0))
{
	Renderer::registerNode(*this);
}
