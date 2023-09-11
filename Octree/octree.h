#ifndef OCTREE_H 
#define OCTREE_H

#include "no.h"

struct Ponto {
	double x;
	double y;
	double z;
};

class Octree {
public:

	Ponto Centro;
	double tamanho;
	No raiz;
};

#endif 
