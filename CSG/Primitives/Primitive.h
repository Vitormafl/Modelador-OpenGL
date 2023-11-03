#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "Ray.h"
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

struct EdgeHits {
	glm::vec3 HitPoint;
	bool isEntry;
};

class Primitive {
public:

	virtual vector<EdgeHits> checkIntersection(Ray r);
};

#endif