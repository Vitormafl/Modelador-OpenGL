#ifndef CSGTREE_h
#define CSGTREE_h

#include "CSGSphere.h"

enum class booleanOperation {NONE, UNION, INTERSECTION, AMINUSB, BMINUSA};

class CSGTree {
public:
	CSGTree* leftChildTree;
	CSGTree* rightChildTree;
	booleanOperation operation;
	bool isPrimitive;
	Primitive *primitive;

	CSGTree(CSGTree* leftChildTree, CSGTree* rightChildTree, booleanOperation operation);
	CSGTree(Primitive* primitive);
};

#endif