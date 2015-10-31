//             .-'''''-.
//           .'         `.
//          :             :   File       : NonCopyable.hpp
//         :               :  Creation   : 2015-10-18 02:06:26
//         :      _/|      :  Last Edit  : 2015-10-18 02:14:49
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _NON_COPYABLE_HPP
# define _NON_COPYABLE_HPP

class NonCopyable
{
protected:
	NonCopyable() = default;

private:
	NonCopyable(const NonCopyable &);

	NonCopyable &	operator=(const NonCopyable &);
};

#endif /* _NON_COPYABLE_HPP */
