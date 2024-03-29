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
    // beware of item
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
    BT->item = myBT->item;
    BT->left = myBT->left;
    BT->right = myBT->right;

    PreWalkDelete(ptr->left)
    PreWalkDelete(ptr->right)
}
template<class T> 
void BinaryTree<T>::insert(const T& item)
{
    Node* ptr = new Node;
    ptr->item = item;
    ptr->left = NULL;
    ptr->right = NULL;

    if (root == NULL)
    {
        root = ptr;
    }

    Node* qtr = root;
    while (qtr != NULL)
    {
        parent = qtr;

        // smaller than parent, smaller than both children
        if (item < qtr->item and item <= qtr->right->item and item <= qtr->left->item)
        {
            if (qtr->right->item > qtr->left->item)
            {
                qtr = qtr->right;
            }
            else
            {
                qtr = qtr->left
            }
        }
        else if (item < qtr->item)
        {
            if (item > qtr->right->item and item > qtr->left->item)
            {
                if (qtr->right > qtr->left)
                {
                    break;
                }
            }
        }
        
    }
}

