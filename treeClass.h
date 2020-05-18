#pragma once
#include <vector>
#include "Core.h"

class Tree {
	// possible rectreate later, I dont know how do exacly squares of our world will work
	sprite_params* trunk; //first cell is X second - Y
	std::vector<sprite_params* > roots; // possible rectreate later, I dont know how do exacly squares of our world will work
	std::vector<sprite_params* > neighborFields; // possible rectreate later, I dont know how do exacly squares of our world will work
	int currentWater;
	int drainPerRoot;
	int humidityUsage;
	int waterToGrowth;

	// to add later: health,
public:
	Tree(sprite_params* trunk);
	void treeLifeCycle(int interval); // this function will need ticks as argument later
	void treeGrow();
	void drinkWater();
	void treeShrink();
	void assignNewNeighbor(sprite_params* newNeighbor);
};