
#ifndef _MODEL_MANAGER_HPP
# define _MODEL_MANAGER_HPP

# include <string>
# include <vector>
# include <map>

# include <tiny_obj_loader.h>

# include "Engine/Core/Vec2.hpp"
# include "Engine/Core/Vec3.hpp"
# include "Engine/Graphics/Model.hpp"

#define VERTEX_DATA_LENGTH	8

namespace Fothon
{
	typedef std::vector<tinyobj::shape_t>		ShapeList;
	typedef std::vector<tinyobj::material_t>	MaterialList;

	typedef struct
	{
		ShapeList		shapes;
		MaterialList	materials;
	}					obj_t;

	typedef struct
	{
		std::vector<Vec3>		positions;
		std::vector<Vec2>		uvs;
		std::vector<Vec3>		normals;
		std::vector<unsigned>	indices;
	}							RawModelData;

	class ModelManager
	{
		static std::map<std::string, obj_t *>	_cachedOBJs;
		static std::vector<GLuint>				_vbos;
		static std::vector<GLuint>				_vaos;
		static std::vector<GLuint>				_ibos;

		static void		_getModelData(RawModelData & modelData, const ShapeList & shapes, const MaterialList & materials);

		static void		_fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs, const std::vector<Vec3> & normals);
		static GLuint	_loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs, const std::vector<Vec3> & normals);

		static void		_fillIBO(GLuint * buffer, const std::vector<GLuint> & indices);
		static GLuint	_loadIBO(const std::vector<GLuint> & indices);

		static GLuint	_loadVAO();

		static obj_t &	_loadOBJ(const std::string & path);

		static void		_unloadVBO(GLuint vboID);
		static void		_unloadVAO(GLuint vaoID);
		static void		_unloadIBO(GLuint iboID);

		static void		_unloadVBOs();
		static void		_unloadVAOs();
		static void		_unloadIBOs();

	public:
		static Model &	createModel(const RawModelData & modelData);
		static Model &	loadFromOBJ(const std::string & objPath);
		static void		unloadModel(Model & model);
		static void		clearCache();
		static void		cleanUp();
	};
}

#endif /* _MODEL_MANAGER_HPP */
