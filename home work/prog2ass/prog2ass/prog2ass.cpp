#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "redblacktree.h"
#include "Node.h"
using namespace std;

//inspired by https://proprogramming.org/red-black-treerb-tree-implementation-in-c/

/*struct bst {
	int data;
	struct bst* right, * left;
};
typedef struct bst node;

node* insert(node* tree, int val) {
	if (!(tree)) {
		tree = (node*)malloc(sizeof(node));
		tree->left = NULL;
		tree->right = NULL;
		tree->data = val;
		return tree;
	}
	if(val < (tree)->data) {
		tree->left = insert((tree)->left, val);
	}
	else if (val > (tree)->data) {
		tree->right = insert((tree)->right, val);
	}
	return tree;
}
void print_tree(node* tree) {
	if (tree) {
		print_tree(tree->left);
		printf("tree node = %d\n", tree->data);
		print_tree(tree->right);
	}
}
int height_tree(node* tree, int level, int height) {
	if (tree) {
		if (level > height)height = level;
		height = height_tree(tree->left, level + 1, height); 
		height = height_tree(tree->right, level + 1, height); 
	}
	return height;
}*/
int main() {
	
	redblacktree tree = redblacktree();
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	tree.insert(60);
	tree.display(tree.root);
	system("puase");
	//cout << tree.root->key << endl;
	/*
	node* root;
	root = NULL;
	int val;
	while (1) {
		printf("type a number to insert\n");
		if (scanf("%d", &val)) {
			root = insert(root, val);
		}
		else {
			break;
		}
	}
	printf("In Order Tree Display\n");
	print_tree(root);
	int height = 0;
	int level = 0;
	height = height_tree(root, level, height);
	printf("height is %d\n", height);*/
}