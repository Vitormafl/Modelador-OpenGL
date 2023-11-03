#ifndef	CSGSPHERE_H
#define CSGSPHERE_H

#include "Primitive.h"

class CSGSphere : public Primitive{
public:

	glm::vec3 center;
	float radius;

	vector<EdgeHits> checkIntersection(Ray r);

	CSGSphere(glm::vec3 center, float radius);
};

#endif