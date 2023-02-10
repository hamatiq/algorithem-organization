#include "redblacktree.h"


redblacktree::redblacktree()
{
	root = NULL;
	tnill = NULL;
	height = NULL;
	blackHeight = NULL;
}

void redblacktree::insert(int val)
{
	
	Node* p, * q;
	Node* t = new Node;
	t->key = val;
	t->lchild = NULL;
	t->rchild = NULL;
	t->color = 'R';
	p = root;
	q = NULL;
	if (root == NULL)
	{
		root = t;
		t->parent = NULL;
	}
	else
	{
		while (p != NULL)
		{
			q = p;
			if (p->key < t->key)
				p = p->rchild;
			else
				p = p->lchild;
		}
		t->parent = q;
		if (q->key < t->key)
			q->rchild = t;
		else
			q->lchild = t;
	}
	fixviolation(t);

	//root = insert(root, val);
}
Node* redblacktree::insert(Node* tree, int val){

	if (!(tree)) {
		tree = (Node*)malloc(sizeof(Node));
		tree->lchild = NULL;
		tree->rchild = NULL;
		tree->parent = NULL;
		tree->key = val;
		tree->color = 'R';
		fixviolation(tree);
		return tree;
	}
	else {
		if (val < (tree)->key) {
			if (tree->lchild) {
				tree->lchild = insert((tree)->lchild, val);
			}
			else {
				tree->lchild = (Node*)malloc(sizeof(Node));
				tree->lchild->lchild = NULL;
				tree->lchild->rchild = NULL;
				tree->lchild->parent = tree;
				tree->lchild->color = 'R';
				tree->lchild->key = val;
				fixviolation(tree->lchild);
				return tree;
			}
		}
		else if (val > (tree)->key) {
			if (tree->rchild) {
				tree->rchild = insert((tree)->rchild, val);
			}
			else {
				tree->rchild = (Node*)malloc(sizeof(Node));
				tree->rchild->lchild = NULL;
				tree->rchild->rchild = NULL;
				tree->rchild->parent = tree;
				tree->rchild->color = 'R';
				tree->rchild->key = val;
				fixviolation(tree->rchild);
				return tree;
			}
		}
		return tree;
	}
}


void redblacktree::fixviolation(Node* t)
{
	Node* u;
	if (root == t)
	{
		t->color = 'B';
		return;
	}
	while (t->parent != NULL && t->parent->color == 'R')
	{
		Node* g = t->parent->parent;
		if (g->lchild == t->parent)
		{
			if (g->rchild != NULL)
			{
				u = g->rchild;
				if (u->color == 'R')
				{
					t->parent->color = 'B';
					u->color = 'B';
					g->color = 'R';
					t = g;
				}
			}
			else
			{
				if (t->parent->rchild == t)
				{
					t = t->parent;
					leftRotate(t);
				}
				t->parent->color = 'B';
				g->color = 'R';
				rightRotate(g);
			}
		}
		else
		{
			if (g->lchild != NULL)
			{
				u = g->lchild;
				if (u->color == 'R')
				{
					t->parent->color = 'B';
					u->color = 'B';
					g->color = 'R';
					t = g;
				}
			}
			else
			{
				if (t->parent->lchild == t)
				{
					t = t->parent;
					rightRotate(t);
				}
				t->parent->color = 'B';
				g->color = 'R';
				leftRotate(g);
			}
		}
		root->color = 'B';
	}



/*	if (z->parent && z->parent->parent) {
		//determin uncle or 
		Node* uncle = NULL;

		if (z->parent == z->parent->parent->rchild)
			uncle = z->parent->parent->lchild;
		else
			uncle = z->parent->parent->rchild;

		// check for case 1
		if (z->parent->color == 'R' && z->color == 'R') {
			case1(z, uncle);
		}
		else if (uncle->color == 'B' && z == z->parent->rchild) {
			case2(z, uncle);
		}
		else if (uncle->color == 'B' && z == z->parent->lchild) {
			case3(z, uncle);
		}
		else {}
	}
	if (!z->parent) {
		z->color = 'B';
	}*/
}
void redblacktree::case1(Node* z, Node* uncle)
{
	z->parent->color = 'B';
	if (uncle)
		uncle->color = 'B';
	z->parent->parent->color = 'R';
	fixviolation(z->parent->parent);
}
void redblacktree::case2(Node* z, Node* uncle)
{
	leftRotate(z->parent);
	case3(z, uncle);
}
void redblacktree::case3(Node* z, Node* uncle)
{
	z->parent->color = 'B';
	z->parent->parent->color = 'R';
	rightRotate(z->parent->parent);
}

void redblacktree::leftRotate(Node* p){
	if (p->rchild == NULL)
		return;
	else
	{
		Node* y = p->rchild;
		if (y->lchild != NULL)
		{
			p->rchild = y->lchild;
			y->lchild->parent = p;
		}
		else
			p->rchild = NULL;
		if (p->parent != NULL)
			y->parent = p->parent;
		if (p->parent == NULL)
			root = y;
		else
		{
			if (p == p->parent->lchild)
				p->parent->lchild = y;
			else
				p->parent->rchild = y;
		}
		y->lchild = p;
		p->parent = y;
	}
}
void redblacktree::rightRotate(Node* p){
	if (p->lchild== NULL)
		return;
	else
	{
		Node* y = p->lchild;
		if (y->rchild != NULL)
		{
			p->lchild = y->rchild;
			y->rchild->parent = p;
		}
		else
			p->lchild = NULL;
		if (p->parent != NULL)
			y->parent = p->parent;
		if (p->parent == NULL)
			root = y;
		else
		{
			if (p == p->parent->lchild)
				p->parent->lchild = y;
			else
				p->parent->lchild = y;
		}
		y->rchild = p;
		p->parent = y;
	}
}

void redblacktree::display(Node* p)
{
	if (root == NULL)
	{
		cout << "\nEmpty Tree.";
		return;
	}
	if (p != NULL)
	{
		cout << "\n Key: " << p->key;
		cout << "\n color: ";
		if (p->color == 'B') {
			cout << "Black";
		}
		else {
			cout << "Red";
		}
		if (p->parent != NULL) {
			cout << "\n Parent: " << p->parent->key;
		}
		if (p->rchild != NULL) {
			cout << "\n Right Child: " << p->rchild->key;
		}
		if (p->lchild != NULL){
			cout << "\n Left Child: " << p->lchild->key;
		}
		if (p->lchild){
			cout << "\n\nLeft:\n"; display(p->lchild);
		}
		if (p->rchild){
			 cout << "\n\nRight:\n"; display(p->rchild);
		 }
	}
}

void redblacktree::secondLElement(){
	Node* x = root;
	// go all the way to the left
	while (x->rchild) {
		x = x->rchild;
	}
	cout << "the second largest element: ";
	x->parent->printNode();
}

void redblacktree::setHeight()
{

	Node* x = root;
	// go all the way to the left
	while (x) {
		if (x->color == 'B') {
			blackHeight++;
		}
		x = x->lchild;
	}
}

/*void redblacktree::leftRotate(Node* x) {
	Node* y = x->rchild;
	x->rchild = y->lchild;
	if (y->lchild != tnill)
		y->lchild->parent = x;
	y->parent = x->parent;
	if (x->parent == tnill)
		root = y;
	else if (x == x->parent->lchild)
		x->parent->lchild = y;
	else
		x->parent->rchild = y;
	y->lchild = x;
	x->parent = y;
}

void redblacktree::rightRotate(Node* x)
{
	Node* y = x->lchild;
	x->lchild = y->rchild;
	if (y->rchild != tnill)
		y->rchild->parent = x;
	y->parent = x->parent;
	if (x->parent == tnill)
		root = y;
	else if (x == x->parent->rchild)
		x->parent->rchild = y;
	else
		x->parent->lchild = y;
	y->rchild = x;
	x->parent = y;
}
*/

redblacktree::~redblacktree()
{
}
