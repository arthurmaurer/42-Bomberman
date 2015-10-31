//             .-'''''-.
//           .'         `.
//          :             :   File       : Renderable.hpp
//         :               :  Creation   : 2015-10-18 03:04:25
//         :      _/|      :  Last Edit  : 2015-10-18 03:15:28
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _RENDERABLE_HPP
# define _RENDERABLE_HPP

class Window;

class Renderable
{
public:
	virtual void	render(Window & window);
};

#endif /* _RENDERABLE_HPP */
