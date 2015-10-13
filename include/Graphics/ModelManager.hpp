#pragma once

#include <string>
#include "Graphics/Model.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include <vector>
#include <tiny_obj_loader.h>

#define VERTEX_DATA_LENGTH	8

typedef std::vector<tinyobj::shape_t>		ShapeList;
typedef std::vector<tinyobj::material_t>	MaterialList;

class ModelManager
{
	static void		getModelData(std::vector<Vec3> & positions, std::vector<Vec3> & diffuseColors, std::vector<Vec2> & uvs, std::vector<GLuint> & indices, const ShapeList & shapes, const MaterialList & materials);

	static void		fillVBO(GLfloat * buffer, const std::vector<Vec3> & positions, const std::vector<Vec3> & diffuseColors, const std::vector<Vec2> & uvs);
	static GLuint	loadVBO(const std::vector<Vec3> & positions, const std::vector<Vec3> & diffuseColors, const std::vector<Vec2> & uvs);

	static void		fillIBO(GLuint * buffer, const std::vector<GLuint> & indices);
	static GLuint	loadIBO(const std::vector<GLuint> & indices);

	static GLuint	loadVAO();
	static void		loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials);

public:
	static Model &	loadFromOBJ(const std::string & objPath);
};
