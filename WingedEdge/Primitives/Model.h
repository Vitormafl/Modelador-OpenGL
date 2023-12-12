#pragma once

#include "Block.h"

class Model {
public:
	std::vector<Tables> solids;

	Model();
	~Model();
	Model(std::string objPath);

	void msvf(glm::vec3 vertexCoordinates);
	void mev(int solidID, int face1ID, int face2ID, int existingVertexID, int ncwID, int pccwID, glm::vec3 newVertexCoordinates);
	void mef(int solidID, int existingFaceID, int startVertexID, int endVertexID, int ncwID, int pcwID, int nccwID, int pccwID);

};
