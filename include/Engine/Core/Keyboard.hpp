//             .-'''''-.
//           .'         `.
//          :             :   File       : Keyboard.hpp
//         :               :  Creation   : 2015-11-01 10:24:54
//         :      _/|      :  Last Edit  : 2015-11-01 11:18:35
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _INPUT_HPP
# define _INPUT_HPP

# include <array>
# include <ostream>
# include <deque>

#include <SFML/Window/Keyboard.hpp>

namespace sf { class Event; }

namespace Fothon
{
	class		Keyboard
	{
	public:
		enum Key
		{
			Unknown = -1,
			A = 0,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			Num0,
			Num1,
			Num2,
			Num3,
			Num4,
			Num5,
			Num6,
			Num7,
			Num8,
			Num9,
			Escape,
			LControl,
			LShift,
			LAlt,
			LSystem,
			RControl,
			RShift,
			RAlt,
			RSystem,
			Menu,
			LBracket,
			RBracket,
			SemiColon,
			Comma,
			Period,
			Quote,
			Slash,
			BackSlash,
			Tilde,
			Equal,
			Dash,
			Space,
			Return,
			BackSpace,
			Tab,
			PageUp,
			PageDown,
			End,
			Home,
			Insert,
			Delete,
			Add,
			Subtract,
			Multiply,
			Divide,
			Left,
			Right,
			Up,
			Down,
			Numpad0,
			Numpad1,
			Numpad2,
			Numpad3,
			Numpad4,
			Numpad5,
			Numpad6,
			Numpad7,
			Numpad8,
			Numpad9,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F15,
			Pause,
			KeyCount
		};

		struct	KeyState
		{
			bool	pressed = false;
			bool	released = false;
		};

		static bool	isKeyPressed(Key key);
		static bool	isKeyReleased(Key key);
		static bool	isKeyHold(Key key);

		static void	hydrate(const sf::Event & event);
		static void	dehydrate();

	private:
		static std::array<KeyState, KeyCount>			_states;
		static std::array<sf::Keyboard::Key, KeyCount>	_sfmlKeyMapping;

		static std::deque<unsigned>						_frameEvents;
	};
}

#endif /* _INPUT_HPP */
