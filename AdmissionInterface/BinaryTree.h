#pragma once
#include "Student.h"
#include <iostream>

using namespace std;


struct BinaryNode{
	CStudent value;
	BinaryNode *parent;
	BinaryNode *left;
	BinaryNode *right;
};

class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();

	void insert(CStudent key);
	BinaryNode *search(CStudent key);
	int remove(CStudent key);
	void destroy_tree();

	void inorder_print(CString *pStr);
	void postorder_print(CString *pStr);
	void preorder_print(CString *pStr);

private:
	void destroy_tree(BinaryNode *leaf);
	void insert(CStudent key, BinaryNode *leaf);
	void insert(BinaryNode *newNode, BinaryNode *dstLeaf);

	BinaryNode *search(CStudent key, BinaryNode *leaf);

	void inorder_print(BinaryNode *leaf, CString *pStr);
	void postorder_print(BinaryNode *leaf, CString *pStr);
	void preorder_print(BinaryNode *leaf, CString *pStr);

public:
	BinaryNode *root;
};

extern BinaryTree g_BinaryTree;




// int main(){

	//btree tree;
// 	btree *tree = new btree();

// 	tree->insert(10);
// 	tree->insert(6);
// 	tree->insert(14);
// 	tree->insert(5);
// 	tree->insert(8);
// 	tree->insert(11);
// 	tree->insert(18);
// 
// 	tree->preorder_print();
// 	tree->inorder_print();
// 	tree->postorder_print();
// 
// 	delete tree;

//}