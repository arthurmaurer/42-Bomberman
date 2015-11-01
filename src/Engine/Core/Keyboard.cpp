//             .-'''''-.
//           .'         `.
//          :             :   File       : Keyboard.cpp
//         :               :  Creation   : 2015-11-01 10:52:15
//         :      _/|      :  Last Edit  : 2015-11-01 11:27:28
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#include <ostream>

#include <SFML/Window/Event.hpp>

#include "Engine/Core/Keyboard.hpp"

using namespace Fothon;

std::array<Keyboard::KeyState, Keyboard::KeyCount>	Keyboard::_states;
std::deque<unsigned>								Keyboard::_frameEvents;
std::array<sf::Keyboard::Key, Keyboard::KeyCount>	Keyboard::_sfmlKeyMapping =
{
	sf::Keyboard::A,
	sf::Keyboard::B,
	sf::Keyboard::C,
	sf::Keyboard::D,
	sf::Keyboard::E,
	sf::Keyboard::F,
	sf::Keyboard::G,
	sf::Keyboard::H,
	sf::Keyboard::I,
	sf::Keyboard::J,
	sf::Keyboard::K,
	sf::Keyboard::L,
	sf::Keyboard::M,
	sf::Keyboard::N,
	sf::Keyboard::O,
	sf::Keyboard::P,
	sf::Keyboard::Q,
	sf::Keyboard::R,
	sf::Keyboard::S,
	sf::Keyboard::T,
	sf::Keyboard::U,
	sf::Keyboard::V,
	sf::Keyboard::W,
	sf::Keyboard::X,
	sf::Keyboard::Y,
	sf::Keyboard::Z,
	sf::Keyboard::Num0,
	sf::Keyboard::Num1,
	sf::Keyboard::Num2,
	sf::Keyboard::Num3,
	sf::Keyboard::Num4,
	sf::Keyboard::Num5,
	sf::Keyboard::Num6,
	sf::Keyboard::Num7,
	sf::Keyboard::Num8,
	sf::Keyboard::Num9,
	sf::Keyboard::Escape,
	sf::Keyboard::LControl,
	sf::Keyboard::LShift,
	sf::Keyboard::LAlt,
	sf::Keyboard::LSystem,
	sf::Keyboard::RControl,
	sf::Keyboard::RShift,
	sf::Keyboard::RAlt,
	sf::Keyboard::RSystem,
	sf::Keyboard::Menu,
	sf::Keyboard::LBracket,
	sf::Keyboard::RBracket,
	sf::Keyboard::SemiColon,
	sf::Keyboard::Comma,
	sf::Keyboard::Period,
	sf::Keyboard::Quote,
	sf::Keyboard::Slash,
	sf::Keyboard::BackSlash,
	sf::Keyboard::Tilde,
	sf::Keyboard::Equal,
	sf::Keyboard::Dash,
	sf::Keyboard::Space,
	sf::Keyboard::Return,
	sf::Keyboard::BackSpace,
	sf::Keyboard::Tab,
	sf::Keyboard::PageUp,
	sf::Keyboard::PageDown,
	sf::Keyboard::End,
	sf::Keyboard::Home,
	sf::Keyboard::Insert,
	sf::Keyboard::Delete,
	sf::Keyboard::Add,
	sf::Keyboard::Subtract,
	sf::Keyboard::Multiply,
	sf::Keyboard::Divide,
	sf::Keyboard::Left,
	sf::Keyboard::Right,
	sf::Keyboard::Up,
	sf::Keyboard::Down,
	sf::Keyboard::Numpad0,
	sf::Keyboard::Numpad1,
	sf::Keyboard::Numpad2,
	sf::Keyboard::Numpad3,
	sf::Keyboard::Numpad4,
	sf::Keyboard::Numpad5,
	sf::Keyboard::Numpad6,
	sf::Keyboard::Numpad7,
	sf::Keyboard::Numpad8,
	sf::Keyboard::Numpad9,
	sf::Keyboard::F1,
	sf::Keyboard::F2,
	sf::Keyboard::F3,
	sf::Keyboard::F4,
	sf::Keyboard::F5,
	sf::Keyboard::F6,
	sf::Keyboard::F7,
	sf::Keyboard::F8,
	sf::Keyboard::F9,
	sf::Keyboard::F10,
	sf::Keyboard::F11,
	sf::Keyboard::F12,
	sf::Keyboard::F13,
	sf::Keyboard::F14,
	sf::Keyboard::F15,
	sf::Keyboard::Pause
};

bool	Keyboard::isKeyPressed(Key key)
{
	return _states[key].pressed;
}

bool	Keyboard::isKeyReleased(Key key)
{
	return _states[key].released;
}

bool	Keyboard::isKeyHold(Key key)
{
	return sf::Keyboard::isKeyPressed(_sfmlKeyMapping[key]);
}

void	Keyboard::hydrate(const sf::Event & event)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:

			if (event.key.code == sf::Keyboard::Key::Unknown)
				return ;
			_states[unsigned(event.key.code)].pressed = true;
			_frameEvents.push_front(unsigned(event.key.code));
			break ;

		case sf::Event::KeyReleased:

			if (event.key.code == sf::Keyboard::Key::Unknown)
				return ;
			_states[unsigned(event.key.code)].released = true;
			_frameEvents.push_front(unsigned(event.key.code));
			break ;

		default:
			break ;
	}
}

void	Keyboard::dehydrate()
{
	for (unsigned i : _frameEvents)
	{
		_states[i].pressed = false;
		_states[i].released = false;
	}
	_frameEvents.clear();
}
