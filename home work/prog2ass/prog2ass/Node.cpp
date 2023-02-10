#include "Node.h"



Node::Node()
{
	key = INT16_MIN;
	parent = nullptr;
	rchild = nullptr;
	lchild = nullptr;
	color = 'R';
}

Node::Node(int value)
{
	key = value;
	parent = nullptr;
	rchild = nullptr;
	lchild = nullptr;
	color = 'R';
}

Node::Node(int value, Node* parent, Node* rchild, Node* lchild)
{
	key = value;
	this->parent = parent;
	this->rchild = rchild;
	this->lchild = lchild;
	color = 'R';
}

void Node::printNode()
{
	cout<< "key: " <<key<<"- Color: "<<color<< endl;
}

Node::~Node()
{
}
