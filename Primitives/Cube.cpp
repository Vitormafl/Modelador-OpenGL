#include "Cube.h"

Cube::Cube() {
	this->maxValues = glm::vec3(0.5f);
	this->minValues = glm::vec3(-0.5f);
};

Cube::Cube(glm::vec3 minValues, glm::vec3 maxValues) {
	this->minValues = minValues;
	this->maxValues = maxValues;
};

Cube::~Cube() {};