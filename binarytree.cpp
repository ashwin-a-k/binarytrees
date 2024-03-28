//======================================================
// binarytree.cpp
// methods for binarytree class
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#include "binarytree.h"

//========================================================
// default constructor
// Creates a Binary Tree
// Parameters: none
// returns nothing
//========================================================
template<class T>
BinaryTree<T>::BinaryTree(void) 
{
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    root->item = NULL;
}

//========================================================
// copy constructor
//========================================================
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &myBT) 
{
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    if (myBT.root == NULL) {
        return;
    } 
    root->item = myBT.root->item;
    
    Node * ptr = myBT.root;
    Node * qtr = root;
    
    PreWalkCopy(*this, myBT);
}

template<class T>
void BinaryTree<T>::PreWalkCopy(BinaryTree<T> &BT, const BinaryTree<T> &myBT) {
	Node* ptr = myBT->root;
    BT->item = myBT->item;
    BT->left = myBT->left;
    BT->right = myBT->right;

    PreWalkCopy(ptr->left)
    PreWalkCopy(ptr->right)
}

template<class T>
BinaryTree::~BinaryTree	(void) {

}

template<class T>
void BinaryTree<T>::PreWalkDelete(BinaryTree<T> &BT) {
	Node* ptr = BT->root;
    BT->left = myBT->left;
    BT->right = myBT->right;

    PreWalkDelete(ptr->left)
    PreWalkDelete(ptr->right)
}



