#ifndef OCTREE_H 
#define OCTREE_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>

#include <iostream>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

	//Estrutura ded dados do nó
	
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

	Octree(glm::vec3 rootCenter, float halfSize, int maxDepth);
	~Octree();
	void deleteNode(Node* node);
	void destroy();
	void addNodes(Node* parent);

	void nodeRenderData(Node* node);
	void setRenderData();
};

#endif 
