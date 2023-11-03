#ifndef RAY_H 
#define RAY_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Ray {
public:
	glm::vec3 p0;
	glm::vec3 dr;

	Ray();
	Ray(glm::vec3 p0, glm::vec3 dr);
};

#endif