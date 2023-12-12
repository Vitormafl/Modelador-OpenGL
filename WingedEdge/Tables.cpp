#include "Tables.h"

Tables::Tables() {}

Tables::~Tables() {}

void Tables::edgeVertexLoop(int faceID) {
	int nextEdge{};

	int startEdge = this->faceTable[faceID].incidentEdge;
	int vertexID{};

	if (this->edgeTable[startEdge].leftFace == faceID) { 
		vertexID = this->edgeTable[startEdge].endVertex;
		nextEdge = this->edgeTable[startEdge].nccw;
	}

	if (this->edgeTable[startEdge].rightFace == faceID) {
		vertexID = this->edgeTable[startEdge].startVertex;
		nextEdge = this->edgeTable[startEdge].ncw;
	}

	int tempEdge{};

	std::cout << nextEdge << std::endl;


	while (nextEdge != startEdge) {
		tempEdge = nextEdge;

		if (this->edgeTable[tempEdge].startVertex == vertexID) {
			vertexID = this->edgeTable[tempEdge].endVertex;
			nextEdge = this->edgeTable[tempEdge].nccw;
		}

		else if (this->edgeTable[tempEdge].endVertex == vertexID) {
			vertexID = this->edgeTable[tempEdge].startVertex;
			nextEdge = this->edgeTable[tempEdge].ncw;
		}

		//ESPAÇO PARA FAZER ALTERAÇÕES NA MALHA
		std::cout << nextEdge << std::endl;

	}
}

void Tables::edgeLoopVertex(int vertex) {
	int edge;
	int nextEdge = -1;
	int startEdge;
	int face;

	edge = this->vertexTable[vertex].incidentEdge;
	startEdge = edge;

	while (nextEdge != startEdge) {
		if (this->edgeTable[edge].startVertex == vertex) {
			face = this->edgeTable[edge].rightFace;
			nextEdge = this->edgeTable[edge].ncw;
		}

		else if (this->edgeTable[edge].endVertex == vertex) {
			face = this->edgeTable[edge].leftFace;
			nextEdge = this->edgeTable[edge].nccw;
		}
		edge = nextEdge;

		//ESPAÇO PARA FAZER ALTERAÇÕES NA MALHA
		std::cout << edge << std::endl;
	}
}