#pragma once
#include "Node.h"
class redblacktree
{
private:
	void fixviolation( Node* node);
	void leftRotate(Node* p);
	void rightRotate(Node* p);

	void case1(Node* z, Node* uncle);
	void case2(Node* z , Node* uncle);
	void case3(Node* z, Node* uncle);

	void setHeight();

public:
	Node* root;
	Node* tnill;
	int blackHeight;
	int height;

	redblacktree();

	void insert(int val);
	Node* insert(Node* tree, int val);
	void secondLElement();
	void display(Node* p);
	void preTraversal();


	~redblacktree();
};

