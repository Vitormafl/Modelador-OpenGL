#ifndef SPHERE_H
#define SPHERE_H

//#include "../Octree/octree.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Sphere {
public:

    float radius;
    glm::vec3 sphereCenter;

    Sphere();
    Sphere(float radius, glm::vec3 sphereCenter);
    ~Sphere();
};

#endif