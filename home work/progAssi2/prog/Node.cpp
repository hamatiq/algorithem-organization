#include "Node.h"


using namespace std;
Node::Node()
{
	value = NULL;
	parent = NULL;
	rChild = NULL;
	lChild = NULL;
	color = 'R';
}

Node::Node(int v)
{
	value = v;
	parent = NULL;
	rChild = NULL;
	lChild = NULL;
	color = 'R';
}

Node::Node(int v, Node * p, Node * rC, Node * lC, char c)
{
	value = v;
	parent = p;
	rChild = rC;
	lChild = lC;
	if (c == 'R' || c == 'B')
		color = c;
	else
		color = 'B';
}

void Node::changeColor()
{
	if (color == 'B') {
		color = 'R';
	}
	else if (color == 'R') {
		color = 'B';
	}
}

void Node::setParent(Node* p)
{
	parent = p;
}

void Node::setRChild(Node *rc)
{
	rChild = rc;
}

void Node::setLChild(Node *lc)
{
	lChild = lc;
}

void Node::setColor(char c)
{
	color = c;
}

void Node::setValue(int v)
{
	value = v;
}


Node * Node::getParent()
{
	return parent;
}

Node * Node::getRChild()
{
	return rChild;
}

Node * Node::getLChild()
{
	return lChild;
}

char Node::getColor()
{
	return color;
}

int Node::getValue()
{
	return value;
}

std::string Node::prrintNode()
{
	string str = to_string(value) + '-' + color;
	return str;
}


Node::~Node()
{
}
