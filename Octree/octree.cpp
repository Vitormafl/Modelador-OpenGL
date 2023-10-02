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

Octree::Octree(std::string octreeInput) {
	this->center = glm::vec3(0.0f, 0.0f, 0.0f);
	this->halfSize = 0.5f;
	this->input = octreeInput;
	this->inputIt = 1;
	if (octreeInput[0] == 'B') {
		rootNode = new Node;

		rootNode->nodeDepth = 0;
		rootNode->nodeCenter = this->center;
		rootNode->isLeaf = true;
		rootNode->parentNode = nullptr;
		rootNode->objectIntersect = 2;

		for (int i = 0; i < 8; ++i) {
			rootNode->childNodes[i] = nullptr;
		}
	}

	else if (octreeInput[0] == '(') {
		rootNode = new Node;

		rootNode->nodeDepth = 0;
		rootNode->nodeCenter = this->center;
		rootNode->isLeaf = true;
		rootNode->parentNode = nullptr;
		rootNode->objectIntersect = 1;

		createNodes(rootNode);
	}

}

//Octree::~Octree() {
//	if (rootNode != nullptr) {
//		deleteNode(rootNode);
//	}
//}

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

void Octree::setCubeOctree(Cube& cube) {
	this->octreeCube = cube;
	paintCubeNodes(this->rootNode);
};
void Octree::paintCubeNodes(Node* node) {
	float centerDislocation = this->halfSize / pow(2, node->nodeDepth);

	glm::vec3 vertices[8];

	vertices[0] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[1] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[2] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z + centerDislocation);

	vertices[3] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z + centerDislocation);

	vertices[4] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[5] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[6] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z + centerDislocation);

	vertices[7] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z + centerDislocation);

	int vertexCount = 0;

	for (int i = 0; i < 8; i++) {
		if (vertices[i].x <= this->octreeCube.maxValues.x && vertices[i].y <= this->octreeCube.maxValues.y && vertices[i].z <= this->octreeCube.maxValues.z && 
			vertices[i].x >= this->octreeCube.minValues.x && vertices[i].y >= this->octreeCube.minValues.y && vertices[i].z >= this->octreeCube.minValues.z) {
			vertexCount += 1;
		}
	}

	if (node->nodeDepth == 0) {
		vertexCount = 1;
	}

	//if (vertexCount == 0 && ) {
	//	node->objectIntersect = 0;
	//}

	if (vertexCount == 8) {
		node->objectIntersect = 2;
	}

	else if (vertexCount == 0) {
		node->objectIntersect = 0;
	}

	else {
		node->objectIntersect = 1;

		if (node->nodeDepth < this->maxDepth) {
			this->addNodes(node);

			for (int i = 0; i < 8; i++) {
				this->paintCubeNodes(node->childNodes[i]);
			}
		}

		else {
			node->objectIntersect = 2;
		}
	}

};

// AJUSTAR PARA VERIFICAR CASO DE A OCTREE JÁ ESTAR SETADA PARA OUTRO OBJETO
void Octree::setSphereOctree(Sphere& sphere) {
	this->octreeSphere = sphere;
	paintSphereNodes(this->rootNode);
};

void Octree::paintSphereNodes(Node* node) {

	float centerDislocation = this->halfSize / pow(2, node->nodeDepth);

	glm::vec3 vertices[8];

	vertices[0] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[1] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[2] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z + centerDislocation);

	vertices[3] = glm::vec3(node->nodeCenter.x - centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z + centerDislocation);

	vertices[4] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[5] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z - centerDislocation);

	vertices[6] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y - centerDislocation,
		node->nodeCenter.z + centerDislocation);

	vertices[7] = glm::vec3(node->nodeCenter.x + centerDislocation,
		node->nodeCenter.y + centerDislocation,
		node->nodeCenter.z + centerDislocation);

	int vertexCount = 0;

	for (int i = 0; i < 8; i++) {
		if (pow((vertices[i].x - this->octreeSphere.sphereCenter.x), 2) + pow((vertices[i].y - this->octreeSphere.sphereCenter.y), 2) + pow((vertices[i].z - this->octreeSphere.sphereCenter.z), 2) <= pow(this->octreeSphere.radius, 2)) {
			vertexCount += 1;
		}
	}

	if (node->nodeDepth == 0) {
		vertexCount = 1;
	}

	if (vertexCount == 8) {
		node->objectIntersect = 2;
	}

	else if (vertexCount == 0) {
		node->objectIntersect = 0;
	}

	else {
		node->objectIntersect = 1;

		if (node->nodeDepth < this->maxDepth) {
			this->addNodes(node);

			for (int i = 0; i < 8; i++) {
				this->paintSphereNodes(node->childNodes[i]);
			}
		}

		else {
			node->objectIntersect = 2;
		}
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

void Octree::createNodes(Node* parent) {
	//std::cout << "i: " << inputIt << '\n';
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
	if (this->input[inputIt] == 'B') {
		parent->childNodes[0]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[0]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[0]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[0]->objectIntersect == 1) {
		createNodes(parent->childNodes[0]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[0]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[1]->nodeDepth = newDepth;
	parent->childNodes[1]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[1]->isLeaf = true;
	parent->childNodes[1]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[1]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[1]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[1]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[1]->objectIntersect == 1) {
		createNodes(parent->childNodes[1]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[1]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[2]->nodeDepth = newDepth;
	parent->childNodes[2]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[2]->isLeaf = true;
	parent->childNodes[2]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[2]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[2]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[2]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[2]->objectIntersect == 1) {
		createNodes(parent->childNodes[2]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[2]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[3]->nodeDepth = newDepth;
	parent->childNodes[3]->nodeCenter = glm::vec3(
		parent->nodeCenter.x - centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[3]->isLeaf = true;
	parent->childNodes[3]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[3]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[3]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[3]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[3]->objectIntersect == 1) {
		createNodes(parent->childNodes[3]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[3]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[4]->nodeDepth = newDepth;
	parent->childNodes[4]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[4]->isLeaf = true;
	parent->childNodes[4]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[4]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[4]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[4]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[4]->objectIntersect == 1) {
		createNodes(parent->childNodes[4]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[4]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[5]->nodeDepth = newDepth;
	parent->childNodes[5]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z - centerDislocation);
	parent->childNodes[5]->isLeaf = true;
	parent->childNodes[5]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[5]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[5]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[5]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[5]->objectIntersect == 1) {
		createNodes(parent->childNodes[5]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[5]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[6]->nodeDepth = newDepth;
	parent->childNodes[6]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y - centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[6]->isLeaf = true;
	parent->childNodes[6]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[6]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[6]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[6]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[6]->objectIntersect == 1) {
		createNodes(parent->childNodes[6]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[6]->childNodes[j] = nullptr;
		}
	}

	parent->childNodes[7]->nodeDepth = newDepth;
	parent->childNodes[7]->nodeCenter = glm::vec3(
		parent->nodeCenter.x + centerDislocation,
		parent->nodeCenter.y + centerDislocation,
		parent->nodeCenter.z + centerDislocation);
	parent->childNodes[7]->isLeaf = true;
	parent->childNodes[7]->parentNode = parent;
	if (this->input[inputIt] == 'B') {
		parent->childNodes[7]->objectIntersect = 2;
		//cout << "B";
	}
	if (this->input[inputIt] == '(') {
		parent->childNodes[7]->objectIntersect = 1;
		//cout << "(";
	}
	if (this->input[inputIt] == 'W') {
		parent->childNodes[7]->objectIntersect = 0;
		//cout << "W";
	}
	inputIt += 1;

	if (parent->childNodes[7]->objectIntersect == 1) {
		createNodes(parent->childNodes[7]);
	}
	else {
		for (int j = 0; j < 8; ++j) {
			parent->childNodes[7]->childNodes[j] = nullptr;
		}
	}

}

std::string Octree::save() {
	Node* node = this->rootNode;
	std::string octreeString = save(node);
	ofstream MyFile("octreeString.txt");
	MyFile << octreeString;
	MyFile.close();
	return octreeString;
}

std::string Octree::save(Node* node) {
	//std::cout << "a\n";
	if (node->objectIntersect == 2) {
		return "B";
	}

	else if (node->objectIntersect == 0) {
		return "W";
	}

	else {
		std::string split = "(";

		for (int i = 0; i < 8; i++) {
			split += save(node->childNodes[i]);
		}

		return split;
	}
}