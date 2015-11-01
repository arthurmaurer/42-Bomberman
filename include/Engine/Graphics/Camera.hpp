
#ifndef _CAMERA_HPP
# define _CAMERA_HPP

# include "Engine/Core/Transformable.hpp"

namespace Fothon
{
	class Camera : public virtual Transformable
	{
	public:
		float		fovY;
		float		nearPlane;
		float		farPlane;

		Camera(float fovY);
	};
}

#endif /* _CAMERA_HPP */
