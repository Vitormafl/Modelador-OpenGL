#include "Vertex.h"

bool Vertex::operator == (const Vertex& b) {
	return this->id == b.id;
}

Vertex::Vertex() {
	this->id = -1;
	this->incidentEdge = -1;
	this->coordinates = glm::vec3();
};

Vertex::~Vertex() {};

Vertex::Vertex(int id,int incidentEdge, glm::vec3 coordinates) {
	this->id = id;
	this->incidentEdge = incidentEdge;
	this->coordinates = coordinates;
}