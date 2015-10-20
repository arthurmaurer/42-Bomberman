
#ifndef _LIGHT_HPP
# define _LIGHT_HPP

# include "Core/SceneNode.hpp"

class Light : public SceneNode
{
public:
	Vec3	ambient;
	Vec3	diffuse;
	Vec3	specular;

	void	render(sf::Time dt);
};

#endif /* _LIGHT_HPP */
