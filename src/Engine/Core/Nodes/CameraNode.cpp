//             .-'''''-.
//           .'         `.
//          :             :   File       : CameraNode.cpp
//         :               :  Creation   : 2015-11-01 08:43:28
//         :      _/|      :  Last Edit  : 2015-11-01 10:03:45
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <ostream>

#include "Game/Category.hpp"

#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Core/Nodes/CameraNode.hpp"

using namespace Fothon;

CameraNode::CameraNode(float fovY, float moveSpeed, float lookSpeed) :
	Camera(fovY),
	moveSpeed(moveSpeed),
	lookSpeed(lookSpeed)
{
	if (Renderer::activeCamera == nullptr)
		setActive(true);
}

void	CameraNode::update(sf::Time)
{
	if (!isActive())
		return ;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		transform.position -= transform.rotation * (Vec3::forward * moveSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		transform.position -= transform.rotation * (Vec3::back * moveSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		transform.position += transform.rotation * (Vec3::left * moveSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		transform.position += transform.rotation * (Vec3::right * moveSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		transform.rotation.rotateX(lookSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		transform.rotation.rotateX(-lookSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		transform.rotation.rotateY(-lookSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		transform.rotation.rotateY(lookSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		setActive(false);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		setActive(true);
}

void	CameraNode::setActive(bool active)
{
	if (active)
		Renderer::activeCamera = this;
	else if (Renderer::activeCamera == this)
		Renderer::activeCamera = nullptr;
}

bool	CameraNode::isActive() const
{
	return Renderer::activeCamera == this;
}
