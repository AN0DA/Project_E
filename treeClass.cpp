#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "treeClass.h"

Tree::Tree(sprite_params* trunk) {
	std::cout << "Tree created" << std::endl;
	(*trunk).setRootStatus(true);
	this->trunk = trunk;
	this->neighborFields.push_back((*trunk).neighbors[0]);
	this->neighborFields.push_back((*trunk).neighbors[1]);
	this->neighborFields.push_back((*trunk).neighbors[2]);
	this->neighborFields.push_back((*trunk).neighbors[3]);
}

void Tree::assignNewNeighbor(sprite_params* newNeighbor) {
	// search if newNeighbor is neighbor already, if not then push_back it to the neighbors vector
	for (auto i = this->neighborFields.begin(); i != this->neighborFields.end(); i++) {
		if (*i == newNeighbor)
		{
			return;
		}
	}
	this->neighborFields.push_back(newNeighbor);
}
void Tree::treeGrow() {
	// tree will sprout new roots into neighbor field with highest humidity
	int* currentMaxHumidityId = new int(0);
	int* currentMaxHumidity = new int(-1);
	for (int i = 0; i != this->neighborFields.size(); i++) {
		if (this->neighborFields[i]->getHumidity() > * currentMaxHumidity && !this->neighborFields[i]->getRootStatus()) {
			*currentMaxHumidityId = i;
			*currentMaxHumidity = this->neighborFields[i]->getHumidity();
		}
	}
	// no growing if there are no free spaces
	if (*currentMaxHumidity == -1) {
		return;
	}
	// setting found field as new root and deleting it form neighbor
	this->neighborFields[*currentMaxHumidityId]->setRootStatus(true);
	this->roots.push_back((this->neighborFields[*currentMaxHumidityId]));
	this->neighborFields.erase(this->neighborFields.begin() + *currentMaxHumidityId);
	// adding new neighborFields if they are not neighbors already
	for (int i = 0; i < 4; i++) {
		this->assignNewNeighbor(this->neighborFields.back()->neighbors[i]);
	}
}
void Tree::drinkWater() {
	//drain every root
	for (int i = 0; i != this->roots.size(); i++) {

		this->roots[i]->setHumidity(this->roots[i]->getHumidity() - this->drainPerRoot);
		this->currentWater += this->drainPerRoot;
	}
}
/*
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
*/