#pragma once
#include "Node.h"
#include <stdio.h>
#include <iostream>
#include <string>
class RBtree
{
private:
	Node rootNode;
	int treeHeight;
	int blackHeight;

	void setRootNode(Node r);
	void setTreeHeight(int);
	int checkTreeHeight();
	int checkBlackHeight();
	void setBlackHeight(int x);
	void rotateLeft(Node *x);
	void rotateRight(Node *y);
	void fixViolattion();
	//retuns true if the 2 nodes are the same
	bool compNode(Node x, Node y);
	// sets node y's values to be the same as node x's values
	void setNode(Node x, Node y);
public:
	RBtree();
	RBtree(Node);

	void insert(int);
	void insert(int arr[], int size);
	//void insert(std::string);

	//void eraseNode(int);
	//void eraseNode(int[]);
	//void eraseNode(std::string);

	Node getRootNode();
	int getTreeHeight();
	int getBlackHeight();

	Node os_select(int);
	Node os_rank(Node*);

	std::string traverseTree();
	std::string PrintTree();

	~RBtree();
};

