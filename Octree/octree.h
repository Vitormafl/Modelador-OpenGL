#ifndef OCTREE_H 
#define OCTREE_H

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

	//Estrutura ded dados do n�
	
struct Node {
	int nodeDepth;				//Profundidade do n� na Octree
	glm::vec3 nodeCenter;		//Posi��o do centro do n�
	bool isLeaf;				//Indicar se o n� � ou n�o uma Folha da Octree
	Node* parentNode;			//Ponteiro para o n� Pai
	Node* childNodes[8];		//Ponteiro para os 8 n�s filhos 
};

class Octree {
public:
	//Atributos b�sicos da Octree

	glm::vec3 center;			//Posi��o do centro da Octree 
	float halfSize;				//Tamanho da Octree, 2 * halfSize = lado do cubo	
	int maxDepth;				//Profundidade M�xima que um n� da Octree pode atingir
	Node* rootNode;				//Ponteiro para o N� raiz da Octree

	Octree(glm::vec3 rootCenter, float halfSize, int maxDepth);
	~Octree();
	void deleteNode(Node* node);
	void destroy();

	void addNodes(Node* parent);
};

#endif 
