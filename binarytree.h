//======================================================
// binarytree.h
// header file for binarytree.cpp
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#ifndef COUNTCHARACTER_H
#define COUNTCHARACTER_H

class CountChar {
	public:
		CountChar(void);
		~CountChar(void);
		CountChar& operator=(const CountChar&myCountChar);
		bool operator==(const CountChar&myCountChar);
		bool operator>(const CountChar&myCountChar);
		bool operator<(const CountChar&myCountChar);
		bool operator>=(const CountChar&myCountChar);
		bool operator<=(const CountChar&myCountChar);
		bool operator!=(const CountChar&myCountChar);
	private:
		int count;
		char character;
}

CountChar::CountChar(void)
{
	count = 0;
	character = '';
}

CountChar::~CountChar(void)
{
	count = 0;
	character = '';
}

CountChar& CountChar::operator=(const CountChar&myCountChar)
{
	count = myCountChar.count;
	character = myCountChar.character;
}

CountChar& CountChar::operator==(const CountChar&myCountChar)
{
	if (count == myCountChar.count and character == myCountChar.character) // might not need character
		return true;
	return false;
}

CountChar& CountChar::operator>(const CountChar&myCountChar)
{
	if (count > myCountChar.count)
		return true;
	return false;
}

CountChar& CountChar::operator<(const CountChar&myCountChar)
{
	if (count < myCountChar.count)
		return true;
	return false;
}

CountChar& CountChar::operator>=(const CountChar&myCountChar)
{
	if (count >= myCountChar.count)
		return true;
	return false;
}

CountChar& CountChar::operator<=(const CountChar&myCountChar)
{
	if (count <= myCountChar.count)
		return true;
	return false;
}

CountChar& CountChar::operator>=(const CountChar&myCountChar)
{
	if (count >= myCountChar.count)
		return true;
	return false;
}

CountChar& CountChar::operator!=(const CountChar&myCountChar)
{
	if (count != myCountChar.count)
		return true;
	return false;
}



#endif

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
		CountChar item;
		Node* left;
		Node* right;
		Node* parent;
	};
	Node* root;
}

#include "binarytree.cpp"
#endif
