#ifndef OCTREECONSTRUCTOR_H
#define OCTREECONSTRUCTOR_H

#include <iostream>
#include "../Octree/octree.h"

using namespace std;

void testeOctreeCreation() {
	Octree octree = Octree(glm::vec3(0.0f, 0.0f, 0.0f), 0.5f, 8);

	cout << "Octree centro x:" << octree.center.x << endl;
	cout << "Octree centro y:" << octree.center.y << endl;
	cout << "Octree centro z:" << octree.center.z << endl;

	cout << "Octree halfsize:" << octree.halfSize << endl;

	cout << "Octree profundidade máxima:" << octree.maxDepth << endl;

	cout << "Octree raiz centro x:" << octree.rootNode->nodeCenter.x << endl;
	cout << "Octree raiz centro y:" << octree.rootNode->nodeCenter.y << endl;
	cout << "Octree raiz centro z:" << octree.rootNode->nodeCenter.z << endl;

	cout << "Octree raiz profundidade:" << octree.rootNode->nodeCenter.z << endl;

	cout << "Octree raiz eh folha:" << octree.rootNode->isLeaf << endl;

	cout << "Octree raiz noh pai:" << octree.rootNode->parentNode << endl;

	cout << "Octree raiz filho 0:" << (octree.rootNode->childNodes[0] == nullptr) << endl;
	cout << "Octree raiz filho 1:" << (octree.rootNode->childNodes[1] == nullptr) << endl;
	cout << "Octree raiz filho 2:" << (octree.rootNode->childNodes[2] == nullptr) << endl;
	cout << "Octree raiz filho 3:" << (octree.rootNode->childNodes[3] == nullptr) << endl;
	cout << "Octree raiz filho 4:" << (octree.rootNode->childNodes[4] == nullptr) << endl;
	cout << "Octree raiz filho 5:" << (octree.rootNode->childNodes[5] == nullptr) << endl;
	cout << "Octree raiz filho 6:" << (octree.rootNode->childNodes[6] == nullptr) << endl;
	cout << "Octree raiz filho 7:" << (octree.rootNode->childNodes[7] == nullptr) << endl;

	octree.addNodes(octree.rootNode);

	cout << "Octree raiz filho 0:" << octree.rootNode->childNodes[0]->nodeCenter.x << " " << octree.rootNode->childNodes[0]->nodeCenter.y << " " << octree.rootNode->childNodes[0]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 1:" << octree.rootNode->childNodes[1]->nodeCenter.x << " " << octree.rootNode->childNodes[1]->nodeCenter.y << " " << octree.rootNode->childNodes[1]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 2:" << octree.rootNode->childNodes[2]->nodeCenter.x << " " << octree.rootNode->childNodes[2]->nodeCenter.y << " " << octree.rootNode->childNodes[2]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 3:" << octree.rootNode->childNodes[3]->nodeCenter.x << " " << octree.rootNode->childNodes[3]->nodeCenter.y << " " << octree.rootNode->childNodes[3]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 4:" << octree.rootNode->childNodes[4]->nodeCenter.x << " " << octree.rootNode->childNodes[4]->nodeCenter.y << " " << octree.rootNode->childNodes[4]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 5:" << octree.rootNode->childNodes[5]->nodeCenter.x << " " << octree.rootNode->childNodes[5]->nodeCenter.y << " " << octree.rootNode->childNodes[5]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 6:" << octree.rootNode->childNodes[6]->nodeCenter.x << " " << octree.rootNode->childNodes[6]->nodeCenter.y << " " << octree.rootNode->childNodes[6]->nodeCenter.z << " " << endl;
	cout << "Octree raiz filho 7:" << octree.rootNode->childNodes[7]->nodeCenter.x << " " << octree.rootNode->childNodes[7]->nodeCenter.y << " " << octree.rootNode->childNodes[7]->nodeCenter.z << " " << endl;
};

#endif 
