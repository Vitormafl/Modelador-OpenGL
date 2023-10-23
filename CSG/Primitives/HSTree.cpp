#include "HSTree.h"


HSTree::HSTree(HSNode* leftChildNode, HSNode* rightChildNode, booleanOperation operation) {
	this->rootNode->leftChildNode = leftChildNode;
	this->rootNode->rightChildNode = rightChildNode;
	this->rootNode->operation = operation;
	this->rootNode->isHS = false;
	this->rootNode->halfSpace = nullptr;
};

HSTree::HSTree(HalfSpace* halfSpace) {
	this->rootNode->leftChildNode = nullptr;
	this->rootNode->rightChildNode = nullptr;
	this->rootNode->operation = booleanOperation::NONE;
	this->rootNode->isHS = true;
	this->rootNode->halfSpace = halfSpace;
};