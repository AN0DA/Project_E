#include <iostream>
#include <algorithm>
#include "treeClass.h"

Tree::Tree(Field* trunk) {
	std::cout << "Tree created" << std::endl;
	(*trunk).isRooted = true;
	this->trunk = trunk;
	this->neighborFields.push_back((*trunk).neighbors[1]);
	this->neighborFields.push_back((*trunk).neighbors[2]);
	this->neighborFields.push_back((*trunk).neighbors[3]);
}
void Tree::assignNewNeighbor(Field* newNeighbor) {
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
		if (this->neighborFields[i]->humidity > * currentMaxHumidity && !this->neighborFields[i]->isRooted) {
			*currentMaxHumidityId = i;
			*currentMaxHumidity = this->neighborFields[i]->humidity;
		}
	}
	// no growing if there are no free spaces
	if (*currentMaxHumidity == -1) {
		return;
	}
	// setting found field as new root and deleting it form neighbor
	this->neighborFields[*currentMaxHumidityId]->isRooted = true;
	this->roots.push_back((this->neighborFields[*currentMaxHumidityId]));
	this->neighborFields.erase(this->neighborFields.begin() + *currentMaxHumidityId);
	// adding new neighborFields if they are not neighbors already
	for (int i = 0; i < 4; i++) {
		this->assignNewNeighbor(this->neighborFields.back()->neighbors[i]);
	}
}