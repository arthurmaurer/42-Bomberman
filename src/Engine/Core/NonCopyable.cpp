//             .-'''''-.
//           .'         `.
//          :             :   File       : NonCopyable.cpp
//         :               :  Creation   : 2015-10-18 02:08:53
//         :      _/|      :  Last Edit  : 2015-10-18 02:11:26
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include "Engine/Core/NonCopyable.hpp"

using namespace Fothon;

NonCopyable::NonCopyable(const NonCopyable &)
{}

NonCopyable &	NonCopyable::operator=(const NonCopyable &)
{
	return *this;
}
