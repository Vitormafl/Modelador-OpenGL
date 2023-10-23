#include "HalfSpace.h"

HalfSpace::HalfSpace() {
	this->halfSpace = hsType::UNDEFINED;
};

void HalfSpace::setCircleSpace(glm::vec3 baseCenter, float radius) {
	this->point = baseCenter;
	this->distance = radius;
	this->halfSpace = hsType::CIRCLE;
};

void HalfSpace::setSphereSpace(glm::vec3 baseCenter, float radius) {
	this->point = baseCenter;
	this->distance = radius;
	this->halfSpace = hsType::SPHERE;
};

void HalfSpace::setXPlaneSpace(float x, bool positiveOrientation){
	this->x = x;
	this->positiveX = positiveOrientation;
	this->halfSpace = hsType::XPLANE;
};
void HalfSpace::setYPlaneSpace(float y, bool positiveOrientation){
	this->y = y;
	this->positiveY = positiveOrientation;
	this->halfSpace = hsType::YPLANE;
};
void HalfSpace::setZPlaneSpace(float z, bool positiveOrientation){
	this->z = z;
	this->positiveX = positiveOrientation;
	this->halfSpace = hsType::ZPLANE;
};


void HalfSpace::setXYZPlaneSpace(float x, bool positiveOrientationX, float y, bool positiveOrientationY, float z, bool positiveOrientationZ) {
	this->x = x;
	this->positiveX = positiveOrientationX;
	this->y = y;
	this->positiveY = positiveOrientationY;
	this->z = z;
	this->positiveZ = positiveOrientationZ;
	this->halfSpace = hsType::XYZPLANE;
};