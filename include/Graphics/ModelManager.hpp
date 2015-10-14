#pragma once

#include <string>
#include "Graphics/Model.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include <vector>
#include <map>
#include <tiny_obj_loader.h>

#define VERTEX_DATA_LENGTH	5

typedef std::vector<tinyobj::shape_t>		ShapeList;
typedef std::vector<tinyobj::material_t>	MaterialList;

typedef struct
{
	ShapeList		shapes;
	MaterialList	materials;
}					obj_t;

class ModelManager
{
	static std::map<std::string, obj_t *>	_cachedOBJs;
	static std::vector<GLuint>				_vbos;
	static std::vector<GLuint>				_vaos;
	static std::vector<GLuint>				_ibos;

	static void		_getModelData(std::vector<Vec3> & positions, std::vector<Vec2> & uvs, std::vector<GLuint> & indices, const ShapeList & shapes, const MaterialList & materials);

	static void		_fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs);
	static GLuint	_loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec2> & uvs);

	static void		_fillIBO(GLuint * buffer, const std::vector<GLuint> & indices);
	static GLuint	_loadIBO(const std::vector<GLuint> & indices);

	static GLuint	_loadVAO();
	static void		_loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials);

	static obj_t &	_loadOBJ(const std::string & path);

	static void		_unloadVBO(GLuint vboID);
	static void		_unloadVAO(GLuint vaoID);
	static void		_unloadIBO(GLuint iboID);

	static void		_unloadVBOs();
	static void		_unloadVAOs();
	static void		_unloadIBOs();


public:
	static Model &	loadFromOBJ(const std::string & objPath);
	static void		unloadModel(Model & model);
	static void		clearCache();
	static void		cleanUp();
};
