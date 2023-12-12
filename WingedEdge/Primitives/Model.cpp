#include "Model.h"

Model::Model() {}

Model::~Model() {}

Model::Model(std::string objPath) {} // Aplicar leitor de obj

void Model::msvf(glm::vec3 vertexCoordinates){
	
	Tables table = Tables();
	this->solids.push_back(table);

	Vertex vertex = Vertex(0, -1, vertexCoordinates);
	Face face = Face(0, -1);

	this->solids[this->solids.size() - 1].vertexTable.push_back(vertex);
	this->solids[this->solids.size() - 1].faceTable.push_back(face);
}


void Model::mev(int solidID, int face1ID, int face2ID, int existingVertexID, int ncwID, int pccwID, glm::vec3 newVertexCoordinates){

	if (solidID == -1) {
		std::cout << "A operação MEV precisa de um sólido selecionado, não há nenhum no momento" << std::endl;

		return;
	}

	if (existingVertexID == 0 and this->solids[solidID].vertexTable[existingVertexID].incidentEdge == -1) {

		this->solids[solidID].vertexTable[0].incidentEdge = 0;
		this->solids[solidID].faceTable[face1ID].incidentEdge = 0;
		this->solids[solidID].faceTable[face2ID].incidentEdge = 0;

		Vertex newVertex = Vertex(this->solids[solidID].vertexTable.size(), 0, newVertexCoordinates);
		this->solids[solidID].vertexTable.push_back(newVertex);

		WingedEdge newEdge = WingedEdge(0, 0, 1, face1ID, face2ID, -1, -1, -1, -1);
		this->solids[solidID].edgeTable.push_back(newEdge);
	}

	else {
		Vertex newVertex = Vertex(this->solids[solidID].vertexTable.size(), this->solids[solidID].edgeTable.size(), newVertexCoordinates);
		this->solids[solidID].vertexTable.push_back(newVertex);

		WingedEdge newEdge = WingedEdge(this->solids[solidID].edgeTable.size(), existingVertexID, newVertex.id, face1ID, face2ID, ncwID, -1, -1, pccwID);
		this->solids[solidID].edgeTable.push_back(newEdge);

		if (ncwID != -1){
			if(existingVertexID == this->solids[solidID].edgeTable[ncwID].endVertex){
				this->solids[solidID].edgeTable[ncwID].pcw = newEdge.id;
			}
			else {
				this->solids[solidID].edgeTable[ncwID].pccw = newEdge.id;
			}
		}

		if (pccwID != -1) {
			if (existingVertexID == this->solids[solidID].edgeTable[pccwID].endVertex) {
				this->solids[solidID].edgeTable[pccwID].nccw = newEdge.id;
			}
			else {
				this->solids[solidID].edgeTable[pccwID].ncw = newEdge.id;
			}
		}
	}
}

void Model::mef(int solidID, int existingFaceID, int startVertexID, int endVertexID, int ncwID, int pcwID, int nccwID, int pccwID) {
	if (solidID == -1) {
		std::cout << "A operação MEF precisa de um sólido selecionado, não há nenhum no momento" << std::endl;

		return;
	}

	Face newFace = Face(this->solids[solidID].faceTable.size(), this->solids[solidID].edgeTable.size());
	this->solids[solidID].faceTable.push_back(newFace);

	WingedEdge newEdge = WingedEdge(this->solids[solidID].edgeTable.size(), startVertexID, endVertexID, newFace.id, existingFaceID, ncwID, pcwID, nccwID, pccwID);
	this->solids[solidID].edgeTable.push_back(newEdge);

	if (ncwID != -1) {
		if (startVertexID == this->solids[solidID].edgeTable[ncwID].endVertex) {
			this->solids[solidID].edgeTable[ncwID].pcw = newEdge.id;
		}
		else {
			this->solids[solidID].edgeTable[ncwID].pccw = newEdge.id;
		}
	}

	if (pccwID != -1) {
		if (startVertexID == this->solids[solidID].edgeTable[pccwID].endVertex) {
			this->solids[solidID].edgeTable[pccwID].nccw = newEdge.id;
		}
		else {
			this->solids[solidID].edgeTable[pccwID].ncw = newEdge.id;
		}
	}

	if (pcwID != -1) {
		if (endVertexID == this->solids[solidID].edgeTable[pcwID].endVertex) {
			this->solids[solidID].edgeTable[pcwID].nccw = newEdge.id;
		}
		else {
			this->solids[solidID].edgeTable[pcwID].ncw = newEdge.id;
		}
	}

	if (nccwID != -1) {
		if (endVertexID == this->solids[solidID].edgeTable[nccwID].endVertex) {
			this->solids[solidID].edgeTable[nccwID].pcw = newEdge.id;
		}
		else 
			this->solids[solidID].edgeTable[nccwID].pccw = newEdge.id;
		
	}

	for (int i = 0; i < this->solids[solidID].edgeTable.size(); i++) {
		if (this->solids[solidID].edgeTable[i].leftFace == existingFaceID)
			this->solids[solidID].edgeTable[i].leftFace = newFace.id;
		if (this->solids[solidID].edgeTable[i].rightFace == existingFaceID)
			this->solids[solidID].edgeTable[i].rightFace = newFace.id;
	}
	
	int vertexID = this->solids[solidID].edgeTable[newEdge.id].startVertex;
	int nextEdge = this->solids[solidID].edgeTable[newEdge.id].ncw;
	int tempEdge = -1;
	
	this->solids[solidID].edgeTable[newEdge.id].rightFace = existingFaceID;
	
	while (nextEdge != newEdge.id) {
	
		tempEdge = nextEdge;
	
		if (this->solids[solidID].edgeTable[tempEdge].startVertex == vertexID) {
			this->solids[solidID].edgeTable[nextEdge].leftFace = existingFaceID;
			vertexID = this->solids[solidID].edgeTable[tempEdge].endVertex;
			nextEdge = this->solids[solidID].edgeTable[tempEdge].nccw;
		}
	
		else if (this->solids[solidID].edgeTable[tempEdge].endVertex == vertexID) {
			this->solids[solidID].edgeTable[nextEdge].rightFace = existingFaceID;
			vertexID = this->solids[solidID].edgeTable[tempEdge].startVertex;
			nextEdge = this->solids[solidID].edgeTable[tempEdge].ncw;
		}
	}
	

}