/// \headerfile
/// \brief Header file for treeClass
/// \details Header file for treeClass. Currently contains class for roots, tree and tree daemon which is used to control all of the exisiting tree's life cycles.
/// \author Bruno Murek
/// \version 0.10

#pragma once
#include <vector>
#include "Core.h"
class root {
	/// \class root treeClass.h
	/// \brief Root class contains information about root position, root from which it grew and its children.
	/// spirteRef contains info in which sprite this root lies in
	sprite_params* spriteRef;
	/// parentRoot is a pointer pointing on this root's parent
	root* parentRoot;
	/// childRoots is a vector of root pointers containing references to children
	std::vector<root* > childRoots;
public:
	/// root constructor, if parent root is nullptr then root has no parent and its probably the very first root in a tree
	root(sprite_params* _spriteReference, root* _parentRoot);
	/// getSpriteRef returns pointer on spriteRef to use its getters and setters in tree specyfic methods
	sprite_params* getSpriteRef();
	/// addChild adds a tree new child
	void addChild(root* child);
	/// checkChildRoots is a method that returns a bool, false if root contains no children, true if opposite
	bool checkChildRoots();
	/// removeChild method seeks if root contains specfic child and removes it from the children vector
	void removeChild(root* child);
	/// get parent returns a pointer to parrent to use its methods in tree methods
	root* getParent();
};

class Tree {
	/// \class tree treeClass.h
	/// \brief Tree class contains all information about one tree and methods required by it to grow, drink and shrink
	/// trunk is a sprite_param in wchich tree starts
	sprite_params* trunk;
	/// roots contains all of tree's roots
	std::vector<root* > roots;
	/// current water stored by tree
	int currentWater;
	/// amount of water that is drained from each root in each tree cycle
	int drainPerRoot;
	/// humidityUsage is amout of water that is consumed in each tree life cycle
	int humidityUsage;
	/// waterToGrowth is amount of stored water requred to create a new root
	int waterToGrowth;
	/// treeLevel is determined in 0-4, it is used to tell what spirte should be used by trunk
	int treeLevel;
	/// x contains x position of trunk
	int x;
	/// y contains y position of trunk
	int y;
	/// bool containg information if tree has leveled up and needs to update its sprite
	bool needToDraw;
	
public:
	/// simple construcotr, that also sets trunk as first root with no parent and currentWater to default value of 10
	Tree(sprite_params* trunk, int drainPerRoot, int humidityUsage, int waterToGrowth, int x, int y);
	/// treeLifeCycle is a method executed by treeDeamon that tells tree to drink water from roots, checks if tree has enought water to grow, executes grow or if tree has negative amount of water, shrinks it
	void treeLifeCycle();
	/// treeGrow is a method that seeks the best suitable nieghbour sprite_param to make it one of tree's roots
	void treeGrow();
	/// drinkWatern is a method that drains water from every of tree's roots, if root has not enough water, it drinks all of its water (not full drainPerRoot)
	void drinkWater();
	/// treeShrink is a method that finds the dryest root which is not a parent of any root and erases it from the roots vector also removing it form child vector of it's parent
	void treeShrink();
	// handleLevel checks if tree has enough roots to change it's sprite
	void handleLevel();
	/// getTrunk is a siple getter that returns a pointer pointing at tree's trunk
	sprite_params* getTrunk();
	/// simple x getter
	int getPositionX();
	/// simple y getter
	int getPositionY();
	/// simple needToDraw getter
	bool getNeedToDraw();
	/// simple level getter
	int getLevel();
	sf::Sprite treeSprite;
};
class TreeDaemon {
	/// \class TreeDaemon treeClass.h
	/// \brief TreeDaemon is a class used to manage all of the existing trees, lauched by ticks, tells trees when to use their treeLifeCycle method and handles their death
	/// existingTrees is a vector containg all of the existing trees
	std::vector<Tree> existingTrees;
public:
	/// addTree is a method that simply adds a tree to existingTrees vector 
	void addTree(Tree treeToAdd);
	/// treeControl is a method launched by ticks, it iterates through all elements in exisingTrees vector and evokes their treeLifeCycles it also checks if tree has any roots and trunk if noot it evokes its removal
	void treeControl();
	/// removeTree is a method evoked to remove element witch specyfic id from the exisitingTrees vector
	void removeTree(int elementInVector);
	///
	bool checkChange();
	///
	void Change(sf::RenderWindow* window, double scale_width, double scale_height);
};