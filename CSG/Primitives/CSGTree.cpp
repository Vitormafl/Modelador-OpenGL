#include "CSGTree.h"


CSGTree::CSGTree(CSGTree* leftChildTree, CSGTree* rightChildTree, booleanOperation operation) {
	this->leftChildTree = leftChildTree;
	this->rightChildTree = rightChildTree;
	this->operation = operation;
	this->isPrimitive = false;
	this->primitive = nullptr;
};

CSGTree::CSGTree(Primitive* primitive) {
	this->leftChildTree = nullptr;
	this->rightChildTree = nullptr;
	this->operation = booleanOperation::NONE;
	this->isPrimitive = true;
	this->primitive = primitive;
};