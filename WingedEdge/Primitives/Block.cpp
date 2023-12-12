#include "Block.h"

Block::Block() {
	this->negativeEnd = glm::vec3(-1.0f, -1.0f, -1.0f);
	this->positiveEnd = glm::vec3(1.0f, 1.0f, 1.0f);

	this->createTable();
}

Block::~Block(){
}

Block::Block(glm::vec3 nE, glm::vec3 pE){
	this->negativeEnd = nE;
	this->positiveEnd = pE;

	this->createTable();
}

void Block::createTable() {
	this->blockTable = Tables();

	this->blockTable.vertexTable.push_back(Vertex(0, 0, glm::vec3(this->negativeEnd.x, this->negativeEnd.y, this->negativeEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(1, 1,glm::vec3(this->negativeEnd.x, this->negativeEnd.y, this->positiveEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(2, 2,glm::vec3(this->negativeEnd.x, this->positiveEnd.y, this->negativeEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(3, 3,glm::vec3(this->negativeEnd.x, this->positiveEnd.y, this->positiveEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(4, 4,glm::vec3(this->positiveEnd.x, this->negativeEnd.y, this->negativeEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(5, 5,glm::vec3(this->positiveEnd.x, this->negativeEnd.y, this->positiveEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(6, 6,glm::vec3(this->positiveEnd.x, this->positiveEnd.y, this->negativeEnd.z)));
	this->blockTable.vertexTable.push_back(Vertex(7, 7,glm::vec3(this->positiveEnd.x, this->positiveEnd.y, this->positiveEnd.z)));

	this->blockTable.faceTable.push_back(Face(0, 0));
	this->blockTable.faceTable.push_back(Face(1, 1));
	this->blockTable.faceTable.push_back(Face(2, 2));
	this->blockTable.faceTable.push_back(Face(3, 3));
	this->blockTable.faceTable.push_back(Face(4, 4));
	this->blockTable.faceTable.push_back(Face(5, 5));

	//WingedEdge(int id, int startVertex, int endVertex, int leftFace, int rightFace, int ncw, int pcw, int nccw, int pccw)
	this->blockTable.edgeTable.push_back(WingedEdge(0, 0, 1, 2, 0, 4, 11, 1, 9));
	this->blockTable.edgeTable.push_back(WingedEdge(1, 1, 3, 2, 1, 11, 3, 2, 0));
	this->blockTable.edgeTable.push_back(WingedEdge(2, 2, 3, 3, 2, 9, 1, 3, 8));
	this->blockTable.edgeTable.push_back(WingedEdge(3, 3, 7, 3, 1, 1, 10, 7, 2));
	this->blockTable.edgeTable.push_back(WingedEdge(4, 0, 4, 0, 4, 9, 6, 5, 0));
	this->blockTable.edgeTable.push_back(WingedEdge(5, 4, 5, 0, 5, 6, 10, 11, 4));
	this->blockTable.edgeTable.push_back(WingedEdge(6, 4, 6, 5, 4, 4, 8, 7, 5));
	this->blockTable.edgeTable.push_back(WingedEdge(7, 6, 7, 2, 5, 8, 3, 10, 6));
	this->blockTable.edgeTable.push_back(WingedEdge(8, 2, 6, 4, 3, 2, 7, 6, 9));
	this->blockTable.edgeTable.push_back(WingedEdge(9, 0, 2, 4, 2, 0, 2, 8, 4));
	this->blockTable.edgeTable.push_back(WingedEdge(10, 5, 7, 1, 5, 5, 7, 3, 11));
	this->blockTable.edgeTable.push_back(WingedEdge(11, 1, 5, 1, 0, 0, 5, 10, 1));
}