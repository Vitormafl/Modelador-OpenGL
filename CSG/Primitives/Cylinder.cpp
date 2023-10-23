#include "Cylinder.h"

Cylinder::Cylinder(glm::vec3 baseCenter, float height, float radius){
	this->baseCenter = baseCenter;
	this->height = height;
	this->radius = radius;
	this->tree = nullptr;
	setHSTree();
};

void Cylinder::setHSTree() {
	
	HalfSpace infinityCylinder = HalfSpace();
	infinityCylinder.setCircleSpace(baseCenter, radius);

	HalfSpace minimumY = HalfSpace();
	HalfSpace maximumY = HalfSpace();

	minimumY.setYPlaneSpace(baseCenter.y, true);
	maximumY.setYPlaneSpace(baseCenter.y + height, false);

	HSTree hs1 = HSTree(&infinityCylinder);
	HSTree hs2 = HSTree(&minimumY);
	HSTree hs3 = HSTree(&maximumY);

	HSTree interception1 = HSTree(hs1.rootNode, hs2.rootNode, booleanOperation::INTERSECTION);
	HSTree cylinder = HSTree(interception1.rootNode, hs3.rootNode, booleanOperation::INTERSECTION);

	this->tree = &cylinder;
};