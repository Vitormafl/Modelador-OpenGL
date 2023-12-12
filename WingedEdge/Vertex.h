#pragma once

#include "Edge.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Vertex {
public:
	int id;
	int incidentEdge;
	glm::vec3 coordinates;

	bool operator == (const Vertex& b);

	Vertex();
	~Vertex();

	Vertex(int id, int incidentEdge, glm::vec3 coordinates);
};