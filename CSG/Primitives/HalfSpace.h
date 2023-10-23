#ifndef HALFSPACE_H
#define HALFSPACE_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class hsType {UNDEFINED, CIRCLE, SPHERE, XPLANE, YPLANE, ZPLANE, XYZPLANE};

class HalfSpace {
public:
	hsType halfSpace; 
	glm::vec3 point;
	float distance;
	float x;
	float y;
	float z;
	bool positiveX;
	bool positiveY;
	bool positiveZ;


	HalfSpace();

	void setCircleSpace(glm::vec3 baseCenter, float radius);
	void setSphereSpace(glm::vec3 baseCenter, float radius);
	void setXPlaneSpace(float x, bool positiveOrientation);
	void setYPlaneSpace(float y, bool positiveOrientation);
	void setZPlaneSpace(float z, bool positiveOrientation);
	void setXYZPlaneSpace(float x, bool positiveOrientationX, float y, bool positiveOrientationY, float z, bool positiveOrientationZ);
};

#endif