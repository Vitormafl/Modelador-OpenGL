#pragma once

#include "../Tables.h"

class Block {
public:
	glm::vec3 positiveEnd, negativeEnd;
	Tables blockTable;

	Block();
	~Block();
	Block(glm::vec3 pE, glm::vec3 ne);

private:
	void createTable();

};
