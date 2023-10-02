#ifndef OCTREE_H 
#define OCTREE_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include <iostream>
#include <string>
#include <fstream>

#include "../Primitives/Cube.h"
#include "../Primitives/Sphere.h"

using namespace std;

	//Estrutura de dados do nó
	
struct Node {
	int nodeDepth;				//Profundidade do nó na Octree
	glm::vec3 nodeCenter;		//Posição do centro do nó
	bool isLeaf;				//Indicar se o nó é ou não uma Folha da Octree
	Node* parentNode;			//Ponteiro para o nó Pai
	Node* childNodes[8];		//Ponteiro para os 8 nós filhos 
	int objectIntersect;		// -1/0/1/2 nó fora do objeto/ nó parcialmente dentro do objeto/ nó totalmente dentro do objeto
};

struct renderData {
	std::vector<GLuint> lineIndices;
	std::vector<GLuint> triangleIndices;
	std::vector<GLfloat> vertices;
};

class Octree {
public:

	glm::vec3 center;			//Posição do centro da Octree
	float halfSize;				//Tamanho da Octree, 2 * halfSize = lado do cubo
	int maxDepth;				//Profundidade Máxima que um nó da Octree pode atingir
	Node* rootNode;				//Ponteiro para o Nó raiz da Octree
	renderData octreeData;      //Dados para a renderização da octree
	std::string input;
	int inputIt;
	Sphere octreeSphere;
	Cube octreeCube;

	Octree(glm::vec3 rootCenter, float halfSize, int maxDepth);
	Octree(std::string octreeInput);
	void createNodes(Node* parent);
	string save();

	//~Octree();
	void deleteNode(Node* node);
	void destroy();
	void addNodes(Node* parent);

	void setCubeOctree(Cube& cube);
	void paintCubeNodes(Node* node);

	void setSphereOctree(Sphere& sphere);
	void paintSphereNodes(Node* node);

	void nodeRenderData(Node* node);
	void setRenderData();

	void scaling(float w);
	float volume();


private:
	void scaling(Node* node, float w);
	float volume(Node* node);

	string save(Node* node);
};

#endif 
