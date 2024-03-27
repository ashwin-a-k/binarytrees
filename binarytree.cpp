//======================================================
// binarytree.cpp
// methods for binarytree class
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#include "binarytree.h"

//========================================================
// default constructor
// Creates a heap with capacity 10
// Parameters: none
// returns nothing
//========================================================
template<class T>
Heap<T>::Heap(void) {
    cap = DEFAULT_LIST_SIZE;
    size = 0;
    arr_ptr = (T*)malloc(cap * sizeof(T));
}
