#pragma once
#include <vector>
#include "field.h"

class Tree {
	// possible rectreate later, I dont know how do exacly squares of our world will work
	Field* trunk; //first cell is X second - Y
	std::vector<Field* > roots; // possible rectreate later, I dont know how do exacly squares of our world will work
	std::vector<Field* > neighborFields; // possible rectreate later, I dont know how do exacly squares of our world will work
	int currentWater;
	int humidityUsage;
	// to add later: health,
public:
	Tree(Field* trunk);
	void treeLifeCycle(int currentWater); // this function will need ticks as argument later
	void treeGrow();
	void treeShrink();
	void assignNewNeighbor(Field* newNeighbor);
};