
#include "Graphics/Light.hpp"
#include "Vec2.hpp"

Light::Light() :
	ambient(Vec3(1.f, 1.f, 1.f)),
	diffuse(ambient),
	specular(ambient),
	attenuation(Vec2(0, 0))
{}

Light::Light(const Vec3 & color) :
	ambient(color),
	diffuse(color),
	specular(color),
	attenuation(Vec2(0, 0))
{}

Light::Light(const Vec3 & ambient, const Vec3 & diffuse, const Vec3 & specular) :
	ambient(ambient),
	diffuse(diffuse),
	specular(specular),
	attenuation(Vec2(0, 0))
{}

void	Light::render(sf::Time)
{}
