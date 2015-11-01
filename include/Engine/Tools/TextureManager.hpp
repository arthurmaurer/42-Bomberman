//             .-'''''-.
//           .'         `.
//          :             :   File       : TextureManager.hpp
//         :               :  Creation   : 2015-10-19 00:53:12
//         :      _/|      :  Last Edit  : 2015-11-01 00:16:41
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
# include <map>

# include "Engine/Graphics/Texture.hpp"
# include "Engine/Graphics/ImageBuffer.hpp"
# include "Engine/Tools/ResourceHolder.hpp"

namespace Fothon
{
	class TextureManager : public ResourceHolder<std::string, Texture>
	{
		std::vector<GLuint>										_texturesID;
		std::map<std::string, std::unique_ptr<ImageBuffer>>		_cachedImages;

		GLuint			_loadGLTexture(const ImageBuffer & imageBuffer);
		void			_unloadGLTexture(const Texture & value);
		ImageBuffer &	_loadImage(const std::string & path);

	public:
		TextureManager();

		void			unload(const std::string & key);
		Texture &		load(const std::string & key, const std::string & param = "");
		void			clearCache();
		void			cleanUp();
	};
}

#endif /* _TEXTURE_MANAGER_HPP */
