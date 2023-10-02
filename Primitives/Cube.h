#ifndef CUBE_H
#define CUBE_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cube {
public:

	glm::vec3 minValues;
	glm::vec3 maxValues;

	Cube();
	Cube(glm::vec3 minValues, glm::vec3 maxValues);
	~Cube();
};

#endif