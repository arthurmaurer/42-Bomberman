//             .-'''''-.
//           .'         `.
//          :             :   File       : CameraNode.cpp
//         :               :  Creation   : 2015-11-01 08:43:28
//         :      _/|      :  Last Edit  : 2015-11-01 11:24:09
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
#include "Engine/Core/Keyboard.hpp"
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

	if (Keyboard::isKeyHold(Keyboard::Z))
		transform.position -= transform.rotation * (Vec3::forward * moveSpeed);

	if (Keyboard::isKeyHold(Keyboard::S))
		transform.position -= transform.rotation * (Vec3::back * moveSpeed);

	if (Keyboard::isKeyHold(Keyboard::Q))
		transform.position += transform.rotation * (Vec3::left * moveSpeed);

	if (Keyboard::isKeyHold(Keyboard::D))
		transform.position += transform.rotation * (Vec3::right * moveSpeed);

	if (Keyboard::isKeyHold(Keyboard::Up))
		transform.rotation.rotateX(lookSpeed);

	if (Keyboard::isKeyHold(Keyboard::Down))
		transform.rotation.rotateX(-lookSpeed);

	if (Keyboard::isKeyHold(Keyboard::Right))
		transform.rotation.rotateY(-lookSpeed);

	if (Keyboard::isKeyHold(Keyboard::Left))
		transform.rotation.rotateY(lookSpeed);

	if (Keyboard::isKeyHold(Keyboard::N))
		setActive(false);

	if (Keyboard::isKeyHold(Keyboard::B))
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
