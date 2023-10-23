#ifndef HSTREE_h
#define HSTREE_h

#include "HalfSpace.h"

enum class booleanOperation {NONE, UNION, INTERSECTION, AMINUSB, BMINUSA};

struct HSNode {
	HSNode* leftChildNode;
	HSNode* rightChildNode;
	booleanOperation operation;
	bool isHS;
	HalfSpace* halfSpace;
};

class HSTree {
public:
	HSNode* rootNode;

	HSTree(HSNode* leftChildNode, HSNode* rightChildNode, booleanOperation operation);
	HSTree(HalfSpace* halfSpace);
};

#endif