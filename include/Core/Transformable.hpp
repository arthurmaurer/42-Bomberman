//             .-'''''-.
//           .'         `.
//          :             :   File       : Transformable.hpp
//         :               :  Creation   : 2015-10-18 01:37:39
//         :      _/|      :  Last Edit  : 2015-10-18 04:06:25
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _TRANSFORMABLE_HPP
# define _TRANSFORMABLE_HPP

# include "Transform.hpp"

class Transformable
{
public:
	Transform	transform;
	Transform	absoluteTransform;
};

#endif /* _TRANSFORMABLE_HPP */
