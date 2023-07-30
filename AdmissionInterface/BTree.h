#pragma once
#include "Student.h"

class BTreeNode;
struct Element{
	BTreeNode *pNode;
	int idx;
};
// A BTree node
class BTreeNode {
	CStudent	*students;	// An array of keys
	int			t;			// Minimum degree (defines the range for number of keys)
	BTreeNode	**C;		// An array of child pointers
	int			n;			// Current number of keys
	bool		leaf;		// Is true when node is leaf. Otherwise false

public:
	BTreeNode(int temp, bool bool_leaf); // Constructor
	~BTreeNode(void);

	CStudent getItem(int idx)
	{
		return students[idx];
	}
	void insertNonFull(CStudent k);
	void splitChild(int i, BTreeNode *y);

	// A function to traverse all nodes in a subtree rooted with this node
	void traverse();

// 	int compare(CString key1, CString key2)
// 	{
// 		//		return key1.Compare(key2);
// 		return 0;
// 	}

	int compare(CStudent key1, CStudent key2)
	{
		//		return key1.Compare(key2);
		return key1.GetName().Compare(key2.GetName());
	}

	// A function to search a key in the subtree rooted with this node.    
	BTreeNode *search(CStudent k);
	BTreeNode *search(CStudent k, int &outIdx);
	void remove(CStudent k);
	void removeFromLeaf (int idx);
	void removeFromNonLeaf(int idx);
	int findKey(CStudent k);
	CStudent getPred(int idx);
	CStudent getSucc(int idx);
	void fill(int idx);
	void borrowFromPrev(int idx);
	void borrowFromNext(int idx);
	void merge(int idx);

	friend class BTree;
};


// A BTree
class BTree {
	BTreeNode *root; // Pointer to root node
	int t;			// Minimum degree

public:
	// Constructor (Initializes tree as empty)
	BTree(int temp) {
		root = NULL;
		t = temp;
	}

	// function to traverse the tree
	void traverse() {
		if (root != NULL)
			root->traverse();
	}

	// function to search a key in this tree
	BTreeNode *search(CStudent k, int &outIdx) {
		return (root == NULL) ? NULL : root->search(k, outIdx);
	}

	// The main function that inserts a new key in this B-Tree
	void insert(CStudent k);

	void remove(CStudent k);
};

// int main() {
// 	BTree t(3);
// 	t.insert(8);
// 	t.insert(9);
// 	t.insert(10);
// 	t.insert(11);
// 	t.insert(15);
// 	t.insert(16);
// 	t.insert(17);
// 	t.insert(18);
// 	t.insert(20);
// 	t.insert(23);
// 
// 	cout << "The B-tree is: ";
// 	t.traverse();
// 
// 	int k = 10;
// 	(t.search(k) != NULL) ? cout << endl
// 		<< k << " is found"
// 		: cout << endl
// 		<< k << " is not Found";
// 
// 	k = 2;
// 	(t.search(k) != NULL) ? cout << endl
// 		<< k << " is found"
// 		: cout << endl
// 		<< k << " is not Found\n";
// }

extern BTree g_BTree;

