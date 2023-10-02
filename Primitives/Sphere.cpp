#include "Sphere.h"

Sphere::Sphere() {
    this->radius = 1.0f;
    this->sphereCenter = glm::vec3(0.0f, 0.0f, 0.0f);

}

Sphere::Sphere(float radius, glm::vec3 sphereCenter) {
    this->radius = radius;
    this->sphereCenter = sphereCenter;

}

Sphere::~Sphere() {
};
