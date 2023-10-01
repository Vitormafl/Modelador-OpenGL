#include "octree.h"

Octree::Octree(glm::vec3 rootCenter, float halfSize, int maxDepth)
{
	this->center = rootCenter;
	this->halfSize = halfSize;
	this->maxDepth = maxDepth;
	this->octreeData = renderData();

	rootNode = new Node;

	rootNode->nodeDepth = 0;
	rootNode->nodeCenter = rootCenter;
	rootNode->isLeaf = true;
	rootNode->parentNode = nullptr;
	rootNode->objectIntersect = -1;

	for (int i = 0; i < 8; ++i) {
		rootNode->childNodes[i] = nullptr;
	}

	this->rootNode = rootNode;
}

Octree::~Octree() {
	if (rootNode != nullptr) {
		deleteNode(rootNode);
	}
}

void Octree::deleteNode(Node* node) {
	for (int i = 0; i < 8; ++i) {
		if (node->childNodes[i] != nullptr) {
			deleteNode(node->childNodes[i]);
		}
	}
	delete node;
}

void Octree::destroy() {
	if (rootNode != nullptr) {
		deleteNode(rootNode);
		rootNode = nullptr;
	}
}

void Octree::addNodes(Node* parent) {
	parent->isLeaf = false; 
	int newDepth = parent->nodeDepth + 1;

	double centerDislocation = this->halfSize / pow(2, newDepth);

	for (int i = 0; i < 8; i++) {
		parent->childNodes[i] = new Node;
	}

	parent->childNodes[0]->nodeDepth = newDepth;
	parent->childNodes[0]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[0]->isLeaf = true;
	parent->childNodes[0]->parentNode = parent;
	parent->childNodes[0]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[0]->childNodes[i] = nullptr;
	}

	parent->childNodes[1]->nodeDepth = newDepth;
	parent->childNodes[1]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[1]->isLeaf = true;
	parent->childNodes[1]->parentNode = parent;
	parent->childNodes[1]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[1]->childNodes[i] = nullptr;
	}

	parent->childNodes[2]->nodeDepth = newDepth;
	parent->childNodes[2]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[2]->isLeaf = true;
	parent->childNodes[2]->parentNode = parent;
	parent->childNodes[2]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[2]->childNodes[i] = nullptr;
	}

	parent->childNodes[3]->nodeDepth = newDepth;
	parent->childNodes[3]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[3]->isLeaf = true;
	parent->childNodes[3]->parentNode = parent;
	parent->childNodes[3]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[3]->childNodes[i] = nullptr;
	}

	parent->childNodes[4]->nodeDepth = newDepth;
	parent->childNodes[4]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[4]->isLeaf = true;
	parent->childNodes[4]->parentNode = parent;
	parent->childNodes[4]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[4]->childNodes[i] = nullptr;
	}

	parent->childNodes[5]->nodeDepth = newDepth;
	parent->childNodes[5]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[5]->isLeaf = true;
	parent->childNodes[5]->parentNode = parent;
	parent->childNodes[5]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[5]->childNodes[i] = nullptr;
	}

	parent->childNodes[6]->nodeDepth = newDepth;
	parent->childNodes[6]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[6]->isLeaf = true;
	parent->childNodes[6]->parentNode = parent;
	parent->childNodes[6]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[6]->childNodes[i] = nullptr;
	}

	parent->childNodes[7]->nodeDepth = newDepth;
	parent->childNodes[7]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[7]->isLeaf = true;
	parent->childNodes[7]->parentNode = parent;
	parent->childNodes[7]->objectIntersect = -1;
	for (int i = 0; i < 8; ++i) {
		parent->childNodes[7]->childNodes[i] = nullptr;
	}
}

void Octree::nodeRenderData(Node* node) {

	if (node->objectIntersect == 0) {
		return;
	}

	if (node->objectIntersect == 2) {
		
		float centerDislocation = this->halfSize / (float)pow(2, node->nodeDepth);

										/* VERTICES */
		this->octreeData.vertices.push_back(node->nodeCenter.x - centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y - centerDislocation);	// VERTEX 0
		this->octreeData.vertices.push_back(node->nodeCenter.z - centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x - centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y + centerDislocation);	// VERTEX 1
		this->octreeData.vertices.push_back(node->nodeCenter.z - centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x - centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y - centerDislocation);	// VERTEX 2
		this->octreeData.vertices.push_back(node->nodeCenter.z + centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x - centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y + centerDislocation);	// VERTEX 3
		this->octreeData.vertices.push_back(node->nodeCenter.z + centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x + centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y - centerDislocation);	// VERTEX 4
		this->octreeData.vertices.push_back(node->nodeCenter.z - centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x + centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y + centerDislocation);	// VERTEX 5
		this->octreeData.vertices.push_back(node->nodeCenter.z - centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x + centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y - centerDislocation);	// VERTEX 6
		this->octreeData.vertices.push_back(node->nodeCenter.z + centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

		this->octreeData.vertices.push_back(node->nodeCenter.x + centerDislocation);	//
		this->octreeData.vertices.push_back(node->nodeCenter.y + centerDislocation);	// VERTEX 7
		this->octreeData.vertices.push_back(node->nodeCenter.z + centerDislocation);	//
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);
		this->octreeData.vertices.push_back(1.0f);

											/* LINHAS */
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 3);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 3);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 3);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);

		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.lineIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);

										/* TRIANGULOS */
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 3);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 3);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 3);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 7);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 5);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 1);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 2);

		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 0);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 4);
		this->octreeData.triangleIndices.push_back((this->octreeData.vertices.size() / 6) - 8 + 6);
		
		return;
	}

	if (node->objectIntersect == 1) {
		for (int i = 0; i < 8; i++) {
			nodeRenderData(node->childNodes[i]);
		}

		return;
	}
};


void Octree::setRenderData() {
	if (this->rootNode->objectIntersect == -1) {
		std::cout << "Octree intersections not setted!" << std::endl;
		return;
	}

	if (this->octreeData.vertices.size() > 0) {
		std::vector<GLfloat> emptyGLfloatVector;
		std::vector<GLuint> emptyGLuintVector;

		this->octreeData.lineIndices = emptyGLuintVector;
		this->octreeData.triangleIndices = emptyGLuintVector;
		this->octreeData.vertices = emptyGLfloatVector;
	}

	nodeRenderData(this->rootNode);
};

void Octree::scaling(float w) {
	
	this->halfSize *= w;

	if (this->maxDepth > 0) {
		for (int i = 0; i < 8; i++) {
			scaling(this->rootNode->childNodes[i], w);
		}
	}

	return;
}

void Octree::scaling(Node* node, float w) {

	std::cout << node->parentNode->nodeDepth << std::endl;

	node->nodeCenter = glm::vec3(
		((node->nodeCenter.x - this->center.x) * w) + this->center.x,
		((node->nodeCenter.y - this->center.y) * w) + this->center.y,
		((node->nodeCenter.z - this->center.z) * w) + this->center.z);

	if (node->nodeDepth < this->maxDepth && node->objectIntersect == 1) {
		for (int i = 0; i < 8; i++) {
			scaling(node->childNodes[i], w);
		}
	}

	return;

}

float Octree::volume() {

	float sphereVolume = 0;

	for (int i = 0; i < 8; i++) {
		sphereVolume += volume(this->rootNode->childNodes[i]);
	}

	return sphereVolume;
}

float Octree::volume(Node* node) {
	float nodeVolume = 0;

	if (node->isLeaf and node->objectIntersect == 2) {
		nodeVolume += (pow((2 * this->halfSize), 3) / pow(8, node->nodeDepth));
	}

	else if (node->objectIntersect == 1) {
		for (int i = 0; i < 8; i++) {
			nodeVolume += volume(node->childNodes[i]);
		}
	}

	return nodeVolume;
}