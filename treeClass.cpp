#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "treeClass.h"

void root::addChild(root* child) {
	this->childRoots.push_back(child);
}

root::root(sprite_params* _spriteReference, root* _parentRoot) {
	this->spriteRef = _spriteReference;
	this->spriteRef->setRootStatus(true);
	this->parentRoot = _parentRoot;
	if (this->parentRoot != nullptr) {
		this->parentRoot->addChild(this);
	}
}

bool root::checkChildRoots() {
	if (this->childRoots.size()) {
		return true;
	}
	else {
		return false;
	}
}

sprite_params* root::getSpriteRef() {
	return this->spriteRef;
}

Tree::Tree(sprite_params* trunk, int interval) {
	std::cout << "Tree created" << std::endl;
	(*trunk).setRootStatus(true);
	this->trunk = trunk;
	this->roots.push_back(new root(this->trunk, nullptr));
	this->treeLifeCycle(interval);
}

void Tree::treeGrow() {
	// tree will sprout new roots into neighbor field with highest humidity
	double* currentMaxHumidity = new double(-1);
	root* maxParent = nullptr;
	sprite_params* maxPointer = nullptr;
	for (int i = 0; i != this->roots.size(); i++) {
		for (int j = 0; j != 4; j++) {
			if (this->roots[i]->getSpriteRef()->neighbors[j]->getRootStatus() && this->roots[i]->getSpriteRef()->neighbors[j]->getHumidity() > * currentMaxHumidity) {
				maxParent = this->roots[i];
				maxPointer = this->roots[i]->getSpriteRef()->neighbors[j];
				*currentMaxHumidity = this->roots[i]->getSpriteRef()->neighbors[j]->getHumidity();
			}
		}
	}
	if (*currentMaxHumidity != -1) {
		this->roots.push_back(new root(maxPointer, maxParent));
	}
	delete currentMaxHumidity;
	delete maxParent;
	delete maxPointer;
}
void Tree::drinkWater() {
	//drain every root
	for (int i = 0; i != this->roots.size(); i++) {

		this->roots[i]->getSpriteRef()->setHumidity(this->roots[i]->getSpriteRef()->getHumidity() - this->drainPerRoot);
		this->currentWater += this->drainPerRoot;
	}
}
void Tree::treeShrink() {
	double* currentMinHumidity = new double(9007199254740991);
	int* minIndex = nullptr;
	for (int i = 0; i != this->roots.size(); i++) {
		if (this->roots[i]->getSpriteRef()->getHumidity() < *currentMinHumidity && !this->roots[i]->checkChildRoots()) {
			*currentMinHumidity = this->roots[i]->getSpriteRef()->getHumidity();
		}
	}
	this->roots.erase(this->roots.begin() + *minIndex);
	if (!roots.size()) {
		//this->treeDie();
	}
	delete currentMinHumidity;
	delete minIndex;
}
void Tree::treeLifeCycle(int interval) {
	this->drinkWater();
	this->currentWater -= this->humidityUsage * int(this->roots.size());
	if (this->currentWater > this->waterToGrowth) {
		this->treeGrow();
	}
	else if (this->currentWater <= 0) {
		this->treeShrink();
	}
}