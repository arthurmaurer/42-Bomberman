
#ifndef _LIGHT_HPP
# define _LIGHT_HPP

# include "Core/SceneNode.hpp"
# include "Vec2.hpp"

class Light : public SceneNode
{
public:
	Vec3	ambient;
	Vec3	diffuse;
	Vec3	specular;
	Vec2	attenuation;

	Light();
	Light(const Vec3 & color);
	Light(const Vec3 & ambient, const Vec3 & diffuse, const Vec3 & specular);

	void	render(sf::Time dt);
};

#endif /* _LIGHT_HPP */
