#include "WingedEdge.h"

WingedEdge::WingedEdge(int id, int startVertex, int endVertex, int leftFace, int rightFace, int ncw, int pcw, int nccw, int pccw) {
	this->id = id;
	this->startVertex = startVertex;
	this->endVertex = endVertex;
	this->leftFace = leftFace;
	this->rightFace = rightFace;
	this->ncw = ncw;
	this->pcw = pcw;
	this->nccw = nccw;
	this->pccw = pccw;
}
