#pragma once

#include <string>
#include "Graphics/Model.hpp"

typedef std::vector<tinyobj::shape_t>		ShapeList;
typedef std::vector<tinyobj::material_t>	MaterialList;

class ModelManager
{
	static inline void	fillDataBuffer(GLfloat * buffer, const ShapeList & shapes, const MaterialList & materials);
	static inline void	loadBuffer(Model & model, const ShapeList & shapes, const MaterialList & materials);

public:
	static Model &	loadFromOBJ(const std::string & objPath);
};
