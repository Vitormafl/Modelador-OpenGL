#include "CSGSphere.h"

CSGSphere::CSGSphere(glm::vec3 center, float radius) {
	this->center = center;
	this->radius = radius;
}

vector<EdgeHits> CSGSphere::checkIntersection(Ray r) {
	
	vector<EdgeHits> hitsVector;
	EdgeHits edgeHits;
	
	glm::vec3 w(r.p0.x - this->center.x, r.p0.y - this->center.y, r.p0.z - this->center.z);

	float delta, t1, t2, tAux;
	float a = glm::dot(r.dr, r.dr);
	float b = 2 * glm::dot(w, r.dr);
	float c = glm::dot(w, w) - (this->radius * this->radius);

	delta = (b * b) - 4 * a * c;

	if (delta < 0) {
		return hitsVector;
	}

	if (delta > 0) {
		glm::vec3 hit1, hit2;

		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);

		if (t1 > t2) {
			tAux = t1;
			t1 = t2;
			t2 = tAux;
		}

		glm::vec3 drNormalized = glm::normalize(r.dr);
		glm::vec3 distance1 = drNormalized * t1;
		glm::vec3 distance2 = drNormalized * t2;

		glm::vec3 colisionPoint1(r.p0.x + distance1.x, r.p0.y + distance1.y, r.p0.z + distance1.z);
		glm::vec3 colisionPoint2(r.p0.x + distance2.x, r.p0.y + distance2.y, r.p0.z + distance2.z);
		
	}

	return EdgeHits{};
}