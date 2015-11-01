
#ifndef _WINDOW_HPP
# define _WINDOW_HPP

# include <GL/glew.h>
# include <SFML/Graphics/RenderWindow.hpp>
# include <SFML/OpenGL.hpp>

namespace Fothon
{
	class Window
	{
		sf::ContextSettings	_getContextSettings() const;
		void				_setContext() const;

	public:
		size_t		width;
		size_t		height;
		sf::RenderWindow	window;

		Window(size_t width, size_t height, const std::string & title);
		~Window();

		void		close();
		void		setTitle(std::string title);
		bool		isOpen() const;
		void		display();
		void		resetGLState();
		void		restoreGLState();
	};
}

#endif /* _WINDOW_HPP */
