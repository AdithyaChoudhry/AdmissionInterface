#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree g_BinaryTree;


BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy_tree();
}

void BinaryTree::destroy_tree(BinaryNode *leaf)
{
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinaryTree::destroy_tree()
{
	destroy_tree(root);
}
// all leaf of newNode insert in dstLeaf and newNode is deleted
void BinaryTree::insert(BinaryNode *newNode, BinaryNode *dstLeaf)
{
	if (newNode == NULL) return;
	insert(newNode->value,dstLeaf);
	insert(newNode->left, dstLeaf);
	insert(newNode->right, dstLeaf);
	delete newNode;
}

// key insert in dstLeaf 
void BinaryTree::insert(CStudent key, BinaryNode *leaf)
{
	if(Compare(key, leaf->value)< 0){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new BinaryNode;
			leaf->left->parent = leaf;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if(Compare(key, leaf->value) >= 0)
	{
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new BinaryNode;
			leaf->right->parent = leaf;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

void BinaryTree::insert(CStudent key)
{
	if(root != NULL){
		insert(key, root);
	}else{
		root = new BinaryNode;
		root->parent = NULL;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

BinaryNode * BinaryTree::search(CStudent key, BinaryNode *leaf)
{
	if(leaf != NULL){
		if(Compare(key, leaf->value) == 0 ){
			return leaf;
		}
		if(Compare(key, leaf->value)  <  0){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

BinaryNode * BinaryTree::search(CStudent key)
{
	return search(key, root);
}

void BinaryTree::inorder_print(CString *pStr)
{
	*pStr += _T("inorder\r\n");
	inorder_print(root,pStr);
	*pStr += _T("\r\n");
}

void BinaryTree::inorder_print(BinaryNode *leaf, CString *pStr)
{
	if(leaf != NULL){
		inorder_print(leaf->left, pStr);
		*pStr += leaf->value.GetName() + _T(", ");
		inorder_print(leaf->right, pStr);
	}
}

void BinaryTree::postorder_print(CString *pStr)
{
	*pStr += _T("postorder\r\n");
	postorder_print(root, pStr);
	*pStr += _T("\r\n");
}

void BinaryTree::postorder_print(BinaryNode *leaf, CString *pStr)
{
	if(leaf != NULL){
		inorder_print(leaf->left, pStr);
		inorder_print(leaf->right, pStr);
		*pStr += leaf->value.GetName() + _T(", ");
	}
}

void BinaryTree::preorder_print(CString *pStr)
{
	*pStr += _T("preorder\r\n");
	preorder_print(root, pStr);
	*pStr += _T("\r\n");
}

void BinaryTree::preorder_print(BinaryNode *leaf, CString *pStr)
{
	if(leaf != NULL){
		*pStr += leaf->value.GetName() + _T(", ");
		inorder_print(leaf->left, pStr);
		inorder_print(leaf->right, pStr);
	}
}

int BinaryTree::remove(CStudent key)
{
	// Node to be deleted
	BinaryNode *pNode = search(key);

	if(!pNode) return FALSE;

	// parent of new Node
	BinaryNode* parent = pNode->parent;

	// new Node to replace
	BinaryNode* pNextNode; 

	if(pNode->left != NULL)
	{
		pNextNode = pNode->left;
		insert(pNode->right,pNextNode);

	}
	else if(pNode->right != NULL)
	{
		pNextNode = pNode->right;

	}
	else // both left and right is NULL
	{
		pNextNode = NULL;
	}
	

	if( pNextNode )
		pNextNode->parent = parent;

	if(!parent)
		root = pNextNode;
	else if(parent->left == pNode)
		parent->left = pNextNode;
	else
		parent->right = pNextNode;

	delete pNode;
	return TRUE;
}
