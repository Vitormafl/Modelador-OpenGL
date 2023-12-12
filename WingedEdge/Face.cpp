#include "Face.h"

Face::Face(int id, int incidentEdge) {
	this->id = id;
	this->incidentEdge = incidentEdge;
}

Face::Face() {
	this->id = -1;
	this->incidentEdge = -1;
};

Face::~Face() {};