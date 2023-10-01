#include "Sphere.h"

Sphere::Sphere() {
    this->radius = 1.0f;
    this->sphereCenter = glm::vec3(0.0f, 0.0f, 0.0f);

    this->sphereOctree = nullptr;
}

Sphere::Sphere(float radius, glm::vec3 sphereCenter) {
    this->radius = radius;
    this->sphereCenter = sphereCenter;

    this->sphereOctree = nullptr;
}

Sphere::~Sphere() {
};

void Sphere::setSphereOctree(int maxDepth) {

    this->sphereOctree = new Octree(this->sphereCenter, this->radius, maxDepth);
    paintNodes(this->sphereOctree->rootNode);
};

void Sphere::paintNodes(Node* node) {

    float centerDislocation = this->sphereOctree->halfSize / pow(2, node->nodeDepth);

    glm::vec3 vertices[8];

    vertices[0] = glm::vec3(node->nodeCenter.x - centerDislocation,
        node->nodeCenter.y - centerDislocation,
        node->nodeCenter.z - centerDislocation);

    vertices[1] = glm::vec3(node->nodeCenter.x - centerDislocation,
        node->nodeCenter.y + centerDislocation,
        node->nodeCenter.z - centerDislocation);

    vertices[2] = glm::vec3(node->nodeCenter.x - centerDislocation,
        node->nodeCenter.y - centerDislocation,
        node->nodeCenter.z + centerDislocation);

    vertices[3] = glm::vec3(node->nodeCenter.x - centerDislocation,
        node->nodeCenter.y + centerDislocation,
        node->nodeCenter.z + centerDislocation);

    vertices[4] = glm::vec3(node->nodeCenter.x + centerDislocation,
        node->nodeCenter.y - centerDislocation,
        node->nodeCenter.z - centerDislocation);

    vertices[5] = glm::vec3(node->nodeCenter.x + centerDislocation,
        node->nodeCenter.y + centerDislocation,
        node->nodeCenter.z - centerDislocation);

    vertices[6] = glm::vec3(node->nodeCenter.x + centerDislocation,
        node->nodeCenter.y - centerDislocation,
        node->nodeCenter.z + centerDislocation);

    vertices[7] = glm::vec3(node->nodeCenter.x + centerDislocation,
        node->nodeCenter.y + centerDislocation,
        node->nodeCenter.z + centerDislocation);

    int vertexCount = 0;

    for (int i = 0; i < 8; i++) {
        if (pow((vertices[i].x - this->sphereCenter.x), 2) + pow((vertices[i].y - this->sphereCenter.y), 2) + pow((vertices[i].z - this->sphereCenter.z), 2) <= pow(this->radius, 2)) {
            vertexCount += 1;
        }
    }

    if (node->nodeDepth == 0) {
        vertexCount = 1;
    }

    if (vertexCount == 8) {
        node->objectIntersect = 2;
    }

    else if (vertexCount == 0) {
        node->objectIntersect = 0;
    }

    else {
        node->objectIntersect = 1;

        if (node->nodeDepth < this->sphereOctree->maxDepth) {
            this->sphereOctree->addNodes(node);

            for (int i = 0; i < 8; i++) {
                this->paintNodes(node->childNodes[i]);
            }
        }

        else {
            node->objectIntersect = 2;
        }
    }

}


