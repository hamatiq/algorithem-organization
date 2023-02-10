#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Node
{
public:
	int key;
	Node* parent;
	Node* rchild;
	Node* lchild;
	char color;

	Node();
	Node(int value);
	Node(int value, Node* parent, Node* rchild, Node* lchild);

	void printNode();

	~Node();
};

