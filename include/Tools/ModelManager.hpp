//             .-'''''-.
//           .'         `.
//          :             :   File       : ModelManager.hpp
//         :               :  Creation   : 2015-10-22 08:34:48
//         :      _/|      :  Last Edit  : 2015-10-23 22:08:38
//          :   =/_/      :   Author     : nsierra-
//           `._/ |     .'    Mail       : nsierra-@student.42.fr
//         (   /  ,|...-'
//          \_/^\/||__
//        /~  `""~`"` \_
//    __/  -'/  `-._ `\_\__
//  /     /-'`  `\   \  \-

#ifndef _MODEL_MANAGER_HPP
# define _MODEL_MANAGER_HPP

# include <vector>

# include <GL/glew.h>
# include <tiny_obj_loader.h>

# include "Graphics/Model.hpp"
# include "Tools/ResourceManager.hpp"
# include "Vec2.hpp"
# include "Vec3.hpp"

# define VERTEX_DATA_LENGTH 5

typedef std::vector<tinyobj::shape_t>		ShapeList;
typedef std::vector<tinyobj::material_t>	MaterialList;

typedef struct
{
	ShapeList		shapes;
	MaterialList	materials;
}					obj_t;

class		ModelManager : public ResourceManager<std::string, Model>
{
	std::map<std::string, obj_t *>	_cachedOBJs;
	std::vector<GLuint>				_vbos;
	std::vector<GLuint>				_vaos;
	std::vector<GLuint>				_ibos;

	void		_getModelData(std::vector<Vec3> & positions, std::vector<Vec2> & uvs, std::vector<GLuint> & indices, const ShapeList & shapes, const MaterialList & materials);

	void		_fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs);
	GLuint		_loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs);

	void		_fillIBO(GLuint * buffer, const std::vector<GLuint> & indices);
	GLuint		_loadIBO(const std::vector<GLuint> & indices);

	GLuint		_loadVAO();
	void		_loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials);

	obj_t &		_loadOBJ(const std::string & path);

	void		_unloadVBO(GLuint vboID);
	void		_unloadVAO(GLuint vaoID);
	void		_unloadIBO(GLuint iboID);

	void		_unloadVBOs();
	void		_unloadVAOs();
	void		_unloadIBOs();

protected:
	Model &		_load(const std::string & key, const std::string & param = "");
	void		_unload(const std::string & key);

public:
	ModelManager();

	void		clearCache();
	void		cleanUp();
};

#endif /* _MODEL_MANAGER_HPP */
