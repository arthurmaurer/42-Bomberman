//             .-'''''-.
//           .'         `.
//          :             :   File       : TextureManager.hpp
//         :               :  Creation   : 2015-10-19 00:53:12
//         :      _/|      :  Last Edit  : 2015-10-19 20:36:17
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _TEXTURE_MANAGER_HPP
# define _TEXTURE_MANAGER_HPP

# include <vector>

# include "Engine/Graphics/Texture.hpp"
# include "Engine/Tools/ResourceManager.hpp"

class ImageBuffer;

class		TextureManager : public ResourceManager<std::string, Texture>
{
	std::vector<GLuint>										_texturesID;
	std::map<std::string, std::unique_ptr<ImageBuffer>>		_cachedImages;

	GLuint			_loadGLTexture(const ImageBuffer & imageBuffer);
	void			_unloadGLTexture(const Texture & value);
	ImageBuffer &	_loadImage(const std::string & path);

protected:
	Texture &		_load(const std::string & key, const std::string & param = "");
	void			_unload(const std::string & key);

public:
	TextureManager();

	void				clearCache();
	void				cleanUp();
};


#endif /* _TEXTURE_MANAGER_HPP */
