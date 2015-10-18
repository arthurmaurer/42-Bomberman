
#ifndef _TEXTURE_MANAGER_HPP
# define _TEXTURE_MANAGER_HPP

# include <string>
# include <vector>
# include <map>
# include <SFML/Graphics.hpp>
# include "Graphics/Texture.hpp"
# include <iostream>
# include "Graphics/ImageBuffer.hpp"

class TextureManager
{
	static std::vector<GLuint>					_textures;
	static std::map<std::string, ImageBuffer *>	_cachedImages;

	static ImageBuffer &	_loadImage(const std::string & path);

public:
	static Texture &	loadTexture(const std::string & path);
	static void			unloadTexture(const Texture & texture);
	static void			clearCache();
	static void			cleanUp();
};

#endif /* _TEXTURE_MANAGER_HPP */
