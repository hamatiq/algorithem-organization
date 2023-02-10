#include "RBtree.h"



bool RBtree::compNode(Node x, Node y)
{
	if (x.getValue() == y.getValue()
		&& x.getParent() == y.getParent()
		&& x.getLChild() == y.getLChild()
		&& x.getRChild() == y.getRChild())
		return true;
	else
		return false;
}

void RBtree::setNode(Node x, Node y)
{
	y.setValue(x.getValue());
	y.setLChild(x.getLChild());
	y.setRChild(x.getRChild());
	y.setParent(x.getParent());
}

RBtree::RBtree()
{
	rootNode = NULL;
	treeHeight = 0;
	blackHeight = 0;
}

RBtree::RBtree(Node r)
{
	rootNode = r;
	treeHeight = 1;
	blackHeight = 1;
}

void RBtree::insert(int val)
{
	Node z = Node(val);
	Node x = rootNode;
	Node y = Node();
	//compNode retuns true if 2 nodes have the same values exluding the color
	
	while (!compNode(x,Node())) {//while x is not nill (t.nil)
		setNode(x, y); // y = x //y holds the same value as x
		if (z.getValue() < x.getValue()) {// if z.key < x.key
			x = *(x.getLChild()); // x = x.left
		}
		else { // if z.key >= x.key
			x = *(x.getRChild()); // x = x.right
		}
	}
	z.setParent(&y); //z.p = y
	if (compNode(y, Node())) { // if y == T.nil
		setRootNode(z); // T.root = z
	}
	else if (z.getValue() < y.getValue()) {//z.key < y.key
		y.setLChild(&z);//y.left = z
	}
	else {
		y.setRChild(&z);//y.right = z
	}
	z.setLChild(&Node());//z.left = t.nil
	z.setRChild(&Node());//z.right = t.nill 
	z.setColor('R'); // z.color = red
	//fixViolattion();
}

void RBtree::rotateLeft(Node* x)
{
	Node* y;
	y = x->getRChild();
	x->setRChild(y->getLChild());
	if (y->getLChild() != &Node()) {
		y->getLChild()->setParent(x);
	}
	y->setParent(x->getParent());
	if (x->getParent() == &Node()) {
		rootNode = *y;
	}
	else if (x == x->getParent()->getLChild()) {
		x->getParent()->setLChild(y);
	}
	else {
		x->getParent()->setRChild(y);
	}
	y->setLChild(x);
	x->setParent(y);
}

void RBtree::rotateRight(Node* x)
{
	Node* y;
	y = x->getLChild();
	x->setLChild(y->getRChild());
	if (y->getRChild() != &Node()) {
		y->getRChild()->setParent(x);
	}
	y->setParent(x->getParent());
	if (x->getParent() == &Node()) {
		rootNode = *y;
	}
	else if (x == x->getParent()->getRChild()) {
		x->getParent()->setRChild(y);
	}
	else {
		x->getParent()->setLChild(y);
	}
	y->setRChild(x);
	x->setParent(y);
}



void RBtree::insert(int arr[], int size)
{
	int x = 0;
	for (int i = 0; i < size; i++) {
		x = arr[i];
		insert(x);
	}
}




void RBtree::setRootNode(Node r)
{
	rootNode = r;
}

void RBtree::setTreeHeight(int x)
{
	treeHeight = x;
}

int RBtree::checkBlackHeight()
{
	int bHeight = 0;
	Node x = rootNode;
	while (!compNode(x, Node())) {//while node != t.nill
		x = *(x.getLChild());
		if (x.getColor() == 'B') {
			bHeight++;
		}
	}
	return bHeight;
}

void RBtree::setBlackHeight(int x)
{
	blackHeight = x;
}




RBtree::~RBtree()
{
}

Node RBtree::getRootNode()
{
	return rootNode;
}

int RBtree::getTreeHeight()
{
	return treeHeight;
}

int RBtree::getBlackHeight()
{
	return blackHeight;
}
