CS-271-01: Data Structures
Spring 2024
Professor Kretchmar

Project 5: Binary Tree Huffman Coding
Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo

1. Count Frequency

`count.py` parses in `WarPeace.txt` and outputs a letter frequency table file - `frequency.txt`.

2. Binary Tree Class

`binarytree.h` and `binarytree.cpp` contain the implementation of the Binary Tree class and do most the tree manipulations under the hood for other components. We use std::pair of STL as the basis of the data node type.

3. Priority Queue

`huffman.cpp` implements the Huffman coding by using STL priority queue class with our Binary Tree class. It expects a letter frequency table file to be passed in and write to a new file `code_table.txt` with the encoding table.

4. Encode

`encode.py` asks for the code vector file and text to be encoded names then parses them and writes the results to a new file `encoded.txt`.

5. Decode

`decode.cpp` also asks for the code vector file but rather it recreates the binary tree structure to then decode any message read from a file.

6. Song 

`song.txt` is our chosen song.