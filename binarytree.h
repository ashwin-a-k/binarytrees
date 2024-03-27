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
	BinaryTree(void);
	~BinaryTree(void);
	void insert(const T& item);
	void remove (const T& item);
	void search (const T& item) const;
	void inOrderTreeWalk (const T& item);

private:
	struct Node {
		T item;
		Node* left;
		Node* right;
	};
