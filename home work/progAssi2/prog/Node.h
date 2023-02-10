#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
class Node
{
private:
	int value;
	Node* parent;
	Node* rChild;
	Node* lChild;
	char color;
public:
	Node();
	Node(int value);
	Node(int value, Node* parent, Node* rChild, Node* lChild, char color);

	void changeColor();

	void setParent(Node* p);
	void setRChild(Node* rc);
	void setLChild(Node* lc);
	void setColor(char c);
	void setValue(int v);

	Node* getParent();
	Node* getRChild();
	Node* getLChild();
	char getColor();
	int getValue();
	
	std::string prrintNode();
	
	~Node();
};

