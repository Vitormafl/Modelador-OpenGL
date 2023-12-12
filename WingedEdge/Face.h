#pragma once

#include <vector>

#include "Edge.h"


class Face {
public:
	int id;
	int incidentEdge;

	Face();
	~Face();

	Face(int id, int incidentEdge);
};