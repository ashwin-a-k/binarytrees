//======================================================
// binarytree.h
// header file for binarytree.cpp
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
public:
			BinaryTree	(void);
			~BinaryTree	(void);
			BinaryTree	(const BinaryTree<T> &myBT);
	BinaryTree<T> 	operator=	(const BinaryTree<T> &myBT);
	void 		insert		(const T& item);
	void 		remove 	(const T& item);
	void 		search 	(const T& item) const;
	void 		PreWalkCopy (BinaryTree<T> &BT, const BinaryTree<T> &myBT);

private:
	struct Node {
		T item;
		Node* left;
		Node* right;
		Node* parent; // might be using
	};
	Node* root;
