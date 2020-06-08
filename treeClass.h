#pragma once
#include <vector>
#include "Core.h"

class root {
	sprite_params* spriteRef; // In which sprite this root lies in
	root* parentRoot;
	std::vector<root* > childRoots;
public:
	root(sprite_params* _spriteReference, root* _parentRoot);
	sprite_params* getSpriteRef();
	void addChild(root* child);
	bool checkChildRoots();
};

class Tree {
	// possible rectreate later, I dont know how do exacly squares of our world will work
	sprite_params* trunk; // center of a tree
	std::vector<root* > roots; // possible rectreate later, I dont know how do exacly squares of our world will work
	int currentWater;
	int drainPerRoot;
	int humidityUsage;
	int waterToGrowth;
public:
	Tree(sprite_params* trunk, int interval);
	void treeLifeCycle(int interval); // this function will need ticks as argument later
	void treeGrow();
	void drinkWater();
	void treeShrink();
	void treeDie();
};