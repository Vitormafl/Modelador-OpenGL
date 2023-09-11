#ifndef NO_H
#define NO_H 

struct Cor {
	int r;
	int g;
	int b;
	int a;
};

class No {
public:
	bool ehFolha;
	No* filhos[8];
	Cor cor;
};

#endif