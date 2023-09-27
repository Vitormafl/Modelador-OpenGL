#ifndef OCTREE_H 
#define OCTREE_H

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
};

class Octree {
public:
	//Atributos básicos da Octree

	glm::vec3 center;			//Posição do centro da Octree 
	float halfSize;				//Tamanho da Octree, 2 * halfSize = lado do cubo	
	int maxDepth;				//Profundidade Máxima que um nó da Octree pode atingir
	Node* rootNode;				//Ponteiro para o Nó raiz da Octree

	Octree(glm::vec3 rootCenter, float halfSize, int maxDepth);
	~Octree();
	void deleteNode(Node* node);
	void destroy();

	void addNodes(Node* parent);
};

#endif 
