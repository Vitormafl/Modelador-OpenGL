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

	//Estrutura de dados do n�
	
struct Node {
	int nodeDepth;				//Profundidade do n� na Octree
	glm::vec3 nodeCenter;		//Posi��o do centro do n�
	bool isLeaf;				//Indicar se o n� � ou n�o uma Folha da Octree
	Node* parentNode;			//Ponteiro para o n� Pai
	Node* childNodes[8];		//Ponteiro para os 8 n�s filhos 
	int objectIntersect;		// -1/0/1/2 n� fora do objeto/ n� parcialmente dentro do objeto/ n� totalmente dentro do objeto
};

struct renderData {
	std::vector<GLuint> lineIndices;
	std::vector<GLuint> triangleIndices;
	std::vector<GLfloat> vertices;
};

class Octree {
public:

	glm::vec3 center;			//Posi��o do centro da Octree
	float halfSize;				//Tamanho da Octree, 2 * halfSize = lado do cubo
	int maxDepth;				//Profundidade M�xima que um n� da Octree pode atingir
	Node* rootNode;				//Ponteiro para o N� raiz da Octree
	renderData octreeData;      //Dados para a renderiza��o da octree
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
