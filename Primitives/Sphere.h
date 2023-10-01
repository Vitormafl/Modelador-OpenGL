#ifndef SPHERE_H
#define SPHERE_H

#include "../Octree/octree.h"

class Sphere {
public:

    float radius;
    glm::vec3 sphereCenter;
    Octree* sphereOctree;

    Sphere();
    Sphere(float radius, glm::vec3 sphereCenter);
    ~Sphere();

    void setSphereOctree(int maxDepth);
    void paintNodes(Node* node);
};

#endif