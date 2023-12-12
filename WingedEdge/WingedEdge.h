#pragma once

#include "Vertex.h"
#include "Face.h"

class WingedEdge {
public:
	int id;
	int startVertex, endVertex;
	int leftFace, rightFace;
	int ncw, pcw;
	int nccw, pccw;

	WingedEdge(int id, int startVertex, int endVertex, int leftFace, int rightFace, int ncw, int pcw, int nccw, int pccw);
};