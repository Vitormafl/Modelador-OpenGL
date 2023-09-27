#include "octree.h"

Octree::Octree(glm::vec3 rootCenter, float halfSize, int maxDepth)
{
	this->center = rootCenter;
	this->halfSize = halfSize;
	this->maxDepth = maxDepth;

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

void Octree::setSphere(glm::vec3 sphereCenter, float sphereRadius) {

};