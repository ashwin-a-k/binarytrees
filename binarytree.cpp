//======================================================
// binarytree.cpp
// methods for binarytree class
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#include "binarytree.h"
#include <iostream>
using namespace std;

//========================================================
// default constructor
// Creates a Binary Tree
// Parameters: none
// returns nothing
//========================================================
BinaryTree::BinaryTree(void) : root(nullptr) {}

//========================================================
// destructor
// Deletes root of binary tree
// Parameters: none
// returns nothing
//========================================================
BinaryTree::~BinaryTree(void) {
    Clear(root);
}

//========================================================
// Clear
// Clears tree of values
// Parameters: Node* del_root
// returns nothing
//========================================================
void BinaryTree::Clear(Node* del_root) {
    if (del_root == nullptr)
        return;

    Clear(del_root->left);
    Clear(del_root->right);

    delete del_root;
}

//========================================================
// copy constructor
// copies one tree to another
// Parameters: const BinaryTree &newBT
// returns Binary Tree
//========================================================
BinaryTree::BinaryTree(const BinaryTree &newBT) : root(nullptr) {
    if (newBT.root)
        root = Copy(newBT.root);
}

//========================================================
// copy function
// copies all values of a tree to another tree
// Parameters: Node* newBT
// returns nothing
//========================================================
BinaryTree::Node* BinaryTree::Copy(Node* newBT) {
    if (!newBT)
        return nullptr;

    Node* new_node = new Node(newBT->count_char);
    new_node->left = Copy(newBT->left);
    new_node->right = Copy(newBT->right);

    return new_node;
}

//========================================================
// assignment operator
// basic assignment with binary trees
// Parameters: binarytree
// returns *this
//========================================================
BinaryTree& BinaryTree::operator=(const BinaryTree &newBT) {
    if (this != &newBT) {
        Clear(root);
        root = Copy(newBT.root);
    }
    return *this;
}

//========================================================
// Combine
// combines two trees together
// Parameters: otherBT
// returns new Binary tree
//========================================================
BinaryTree BinaryTree::Combine(const BinaryTree &otherBT) {
    if (!this->root)
        return otherBT;
    if (!otherBT.root)
        return *this;

    pair<int, char> count_sum(this->root->count_char.first + otherBT.root->count_char.first, char(0));
    Node* new_node = new Node(count_sum);

    if (this->root->count_char.first >= otherBT.root->count_char.first) {
        new_node->left = Copy(this->root);
        new_node->right = Copy(otherBT.root);
    } else {
        new_node->left = Copy(otherBT.root);
        new_node->right = Copy(this->root);
    }
    BinaryTree output;
    output.root = new_node;

    return output;
}

//========================================================
// Insert
// Inserts pair item in list
// Parameters: pair item
// returns nothing
//========================================================
void BinaryTree::Insert(const pair<int, char>& item) {
    root = Insert_aux(root, item);
}

//========================================================
// Insert_aux
// Inserts specific pair in left or right node
// Parameters: Node* myNode pair item
// returns myNode
//========================================================
BinaryTree::Node* BinaryTree::Insert_aux(Node* myNode, const pair<int, char>& item) {
    if (!myNode)
        return new Node(item);
    
    if (item.first >= myNode->count_char.first)
        myNode->left = Insert_aux(myNode->left, item);
    else
        myNode->right = Insert_aux(myNode->right, item);

    return myNode;
}

//========================================================
// GetCharCount
// returns number of chars
// Parameters: none
// returns number of chars
//========================================================
pair<int, char> BinaryTree::GetCountChar(void) {
    return root->count_char;
}

//========================================================
// constructor with pair parameter
// Parameters: none
// returns new binary tree
//========================================================
BinaryTree::BinaryTree(const pair<int, char>& item) : root(nullptr) {
    this->Insert(item);
}

//========================================================
// Search
// Searches through Binary tree for letter
// Parameters: char letter
// returns searched item
//========================================================
string BinaryTree::Search(const char letter) {
    vector<string> path;
    string output = "";

    if (Search_aux(root, letter, path)) {
        for (string step : path)
            output += step;
    } else
        cout << "Not Found" << endl;
    
    return output;
}

//========================================================
// Search_aux
// Returns true or false whether searched item is found
// Parameters: Node* curr_node, char target, vector<string>& path
// returns boolean value true or false
//========================================================
bool BinaryTree::Search_aux(Node* curr_node, char target, vector<string>& path) {
    if (!curr_node)
        return false;
    if (curr_node->count_char.second == target)
        return true;

    path.push_back("0");
    if (Search_aux(curr_node->left, target, path))
        return true;
    path.pop_back();

    path.push_back("1");
    if (Search_aux(curr_node->right, target, path))
        return true;
    path.pop_back();

    return false;
}
