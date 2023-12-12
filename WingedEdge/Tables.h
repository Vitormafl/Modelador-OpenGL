#pragma once

#include "WingedEdge.h"

#include <iostream>

class Tables {
public:

	std::vector<Vertex> vertexTable;
	std::vector<Face> faceTable;
	std::vector<WingedEdge> edgeTable;

	Tables();
	~Tables();
	
	//void addVertex(int incidentEdge, glm::vec3 coordinates);
	//void addFace(int incidentEdge);
	//void addEdge(int startVertexID, int endVertexID, int leftFaceID, int rightFaceID, int leftTraverseID, int rightTraverseID, int leftEdgeID, int rightEdgeID);

	void edgeVertexLoop(int faceID);
	void edgeLoopVertex(int vertexID);
};