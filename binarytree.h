//======================================================
// binarytree.h
// header file for binarytree.cpp
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#include <utility>
#include <vector>
#include <string>
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
	private:
		struct Node {
			pair<int, char> count_char;
			Node* left;
			Node* right;

			Node(pair<int, char> data): count_char(data), left(nullptr), right(nullptr) {}
		};

		Node* root;

		//AUX Functions
		Node* 		Copy 	(Node* newBT);
		void		Clear 	(Node* root);
		Node*		Insert_aux	(Node* myNode, const pair<int, char>& item);
		bool		Search_aux	(Node* curr_node, char target, vector<string>& path);

	public:
				BinaryTree	(void);
				~BinaryTree	(void);
				BinaryTree	(const BinaryTree &newBT);
				BinaryTree	(const pair<int, char>& item);
		BinaryTree& operator=	(const BinaryTree &newBT);
		BinaryTree 	Combine		(const BinaryTree &otherBT);
		void 		Insert 	(const pair<int, char>& item);
		string 		Search 	(const char letter);

		pair<int, char> GetCountChar (void);
};

class Compare {
	public:
		bool operator() (BinaryTree &BT1, BinaryTree &BT2) {
			if (BT1.GetCountChar().first > BT2.GetCountChar().first)
				return true;
			return false;
		}
};

#include "binarytree.cpp"

#endif