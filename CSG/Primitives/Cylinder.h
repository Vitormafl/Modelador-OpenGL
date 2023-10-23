#ifndef CYLINDER_h 
#define CYLINDER_h

#include "HSTree.h"

class Cylinder {
public: 

	glm::vec3 baseCenter;
	float height;
	float radius;

	HSTree* tree;

	Cylinder(glm::vec3 baseCenter, float height, float radius);
	void setHSTree();
};

#endif