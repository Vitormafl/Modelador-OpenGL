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