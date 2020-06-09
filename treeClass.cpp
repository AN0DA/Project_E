#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "treeClass.h"

void root::addChild(root* child) {
	this->childRoots.push_back(child);
}
void root::removeChild(root* child) {
	this->childRoots.erase(std::remove(this->childRoots.begin(), this->childRoots.end(), child), this->childRoots.end());
}
root* root::getParent() {
	return this->parentRoot;
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
Tree::Tree(sprite_params* trunk, int drainPerRoot, int humidityUsage, int waterToGrowth, int x, int y) {
	std::cout << "Tree created" << std::endl;
	(*trunk).setRootStatus(true);
	this->trunk = trunk;
	this->roots.push_back(new root(this->trunk, nullptr));
	this->currentWater = 10;
	this->drainPerRoot = drainPerRoot;
	this->humidityUsage = humidityUsage;
	this->waterToGrowth = waterToGrowth;
	this->treeLevel = 1;
	this->x = x;
	this->y = y;
	this->needToDraw = true;
}

sprite_params* Tree::getTrunk() {
	return this->trunk;
}
int Tree::getPositionX() {
	return this->x;
}
int Tree::getPositionY() {
	return this->y;
}
bool Tree::getNeedToDraw() {
	return this->needToDraw;
}
int Tree::getLevel() {
	return this->treeLevel;
}
void Tree::treeGrow() {
	// tree will sprout new roots into neighbor field with highest humidity
	double* currentMaxHumidity = new double(-1);
	root* maxParent = nullptr;
	sprite_params* maxPointer = nullptr;
	for (int i = 0; i != this->roots.size(); i++) {
		for (int j = 0; j != this->roots[i]->getSpriteRef()->neighbour_count; j++) {
			if (this->roots[i]->getSpriteRef()->neighbours[j]->getRootStatus() && this->roots[i]->getSpriteRef()->neighbours[j]->getHumidity() > * currentMaxHumidity && this->roots[i]->getSpriteRef()->neighbours[j] != nullptr) {
				maxParent = this->roots[i];
				maxPointer = this->roots[i]->getSpriteRef()->neighbours[j];
				*currentMaxHumidity = this->roots[i]->getSpriteRef()->neighbours[j]->getHumidity();
			}
		}
	}
	if (*currentMaxHumidity != -1) {
		(*maxPointer).setRootStatus(true);
		this->roots.push_back(new root(maxPointer, maxParent));
	}
	//delete currentMaxHumidity;
	//delete maxParent;
	//delete maxPointer;
	std::cout << "Tree just grew" << std::endl;
}
void Tree::drinkWater() {
	//drain every root
	for (int i = 0; i != this->roots.size(); i++) {
		if (this->roots[i]->getSpriteRef()->getHumidity() - this->drainPerRoot <= 0) {
			this->currentWater += this->roots[i]->getSpriteRef()->getHumidity();
			this->roots[i]->getSpriteRef()->setHumidity(0);
		}
		else {
			this->roots[i]->getSpriteRef()->setHumidity(this->roots[i]->getSpriteRef()->getHumidity() - this->drainPerRoot);
			this->currentWater += this->drainPerRoot;
void Tree::treeShrink() {
	double* currentMinHumidity = new double(9007199254740991);
	int* minIndex = new int(this->roots.size()+1);
	for (int i = 0; i != this->roots.size(); i++) {
		if (this->roots[i]->getSpriteRef()->getHumidity() < *currentMinHumidity && !this->roots[i]->checkChildRoots()) {
			*currentMinHumidity = this->roots[i]->getSpriteRef()->getHumidity();
			*minIndex = i;
		}
	}
	if (*minIndex != this->roots.size() + 1) {
		this->roots[*minIndex]->getSpriteRef()->setRootStatus(false);
		if (this->roots[*minIndex]->getParent() != nullptr) {
			this->roots[*minIndex]->getParent()->removeChild(this->roots[*minIndex]);
		}
		this->roots.erase(this->roots.begin() + *minIndex);
		if (this->roots.size() == 0) {
			trunk = nullptr;
		}
	}
	//delete currentMinHumidity;
	//delete minIndex;
	std::cout << "Tree just shrunk" << std::endl;
}

void Tree::handleLevel() {
	if (this->trunk == nullptr) {
		this->treeLevel = 0;
		this->needToDraw = true;
		std::cout << "Tree just leveled up and is now on: " << this->getLevel() << " level" << std::endl;
	}
	else if (this->roots.size() == 1) {
		this->treeLevel = 1;
		this->needToDraw = true;
		std::cout << "Tree just leveled up and is now on: " << this->getLevel() << " level" << std::endl;
	} else if(this->roots.size() == 4) {
		this->treeLevel = 2;
		this->needToDraw = true;
		std::cout << "Tree just leveled up and is now on: " << this->getLevel() << " level" << std::endl;
	}
	else if (this->roots.size() == 8) {
		this->treeLevel = 3;
		this->needToDraw = true;
		std::cout << "Tree just leveled up and is now on: " << this->getLevel() << " level" << std::endl;
	}
	else if (this->roots.size() == 16) {
		this->treeLevel = 4;
		this->needToDraw = true;
		std::cout << "Tree just leveled up and is now on: " << this->getLevel() << " level" << std::endl;
	}
}
// tell tree to drink, chceck if it has enought of it to grow or shrink
void Tree::treeLifeCycle() {
	this->drinkWater();
	this->currentWater -= this->humidityUsage * int(this->roots.size());
	std::cout << "Tree current water: " << this->currentWater << std::endl;
	if (this->currentWater > this->waterToGrowth) {
		this->treeGrow();
		this->waterToGrowth += this->waterToGrowth;
		this->handleLevel();
	}
	else if (this->currentWater <= 0) {
		this->treeShrink();
		this->handleLevel();
	}
	else {
		this->needToDraw = false;
	}
}
void TreeDaemon::removeTree(int elementInVector) {
	this->existingTrees.erase(this->existingTrees.begin() + elementInVector);
	std::cout << "Tree just died" << std::endl;
}
void TreeDaemon::addTree(Tree treeToAdd) {
	this->existingTrees.push_back(treeToAdd);
}
void TreeDaemon::treeControl() {
	for (int i = 0; i < this->existingTrees.size(); i++) {
		if (this->existingTrees[i].getTrunk() == nullptr) {
			this->removeTree(i);
		}
		else {
			this->existingTrees[i].treeLifeCycle();
		}
	}
	if (this->existingTrees.size() <= 0) {
		std::cout << "There are no trees" << std::endl;
	}
}
bool TreeDaemon::checkChange() {
	for (int i = 0; i < this->existingTrees.size(); i++) {
		if (this->existingTrees[i].getNeedToDraw()) {
			return true;
		}
	}
	return false;
}
void TreeDaemon::Change(sf::RenderWindow* window) {
	sf::Texture none;
	if (!none.loadFromFile("textures/none.png"))
	{
		std::cout << "Error isnt loaded!" << std::endl;
	}
	sf::Texture tree1;
	if (!tree1.loadFromFile("textures/tree1.png"))
	{
		std::cout << "Error isnt loaded!" << std::endl;
	}
	sf::Texture tree2;
	if (!tree2.loadFromFile("textures/tree2.png"))
	{
		std::cout << "Error isnt loaded!" << std::endl;
	}
	sf::Texture tree3;
	if (!tree3.loadFromFile("textures/tree3.png"))
	{
		std::cout << "Error isnt loaded!" << std::endl;
	}
	sf::Texture tree4;
	if (!tree4.loadFromFile("textures/tree4.png"))
	{
		std::cout << "Error isnt loaded!" << std::endl;
	}
	for (int i = 0; i < this->existingTrees.size(); i++) {
		if (this->existingTrees[i].getNeedToDraw()) {
			if (this->existingTrees[i].getLevel() == 0) {
				this->existingTrees[i].treeSprite.setTexture(none);
			}
			else if (this->existingTrees[i].getLevel() == 1) {
				this->existingTrees[i].treeSprite.setTexture(tree1);
			}
			else if (this->existingTrees[i].getLevel() == 2) {
				this->existingTrees[i].treeSprite.setTexture(tree2);
			}
			else if (this->existingTrees[i].getLevel() == 3) {
				this->existingTrees[i].treeSprite.setTexture(tree3);
			}
			else if (this->existingTrees[i].getLevel() == 4) {
				this->existingTrees[i].treeSprite.setTexture(tree4);
			}
			this->existingTrees[i].treeSprite.setPosition(sf::Vector2f(this->existingTrees[i].getPositionX(), this->existingTrees[i].getPositionY()));
			(*window).draw(this->existingTrees[i].treeSprite);
		}
	}
}
