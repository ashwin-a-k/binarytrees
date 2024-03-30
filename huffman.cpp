#include "binarytree.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int	main( int argc, char *argv[] ) {
    priority_queue<BinaryTree, vector<BinaryTree>, Compare> PQ;

    string line;
    while (getline(cin, line)) {
        pair<int, char> data(stoi(line.substr(2)), (char)line[0]);
        BinaryTree new_tree(data);
        PQ.push(new_tree);
    }

    while (PQ.size() > 1) {
        BinaryTree a = PQ.top();
        PQ.pop();
        BinaryTree b = PQ.top();
        PQ.pop();
        BinaryTree c = a.Combine(b);
        PQ.push(c);
    }

    ofstream outFile("code_table.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    BinaryTree last = PQ.top();

    for (int i=0; i < 26; i++) {
        outFile << char(97+i) << " " << last.Search(char(97+i)) << std::endl;
    }
   
    return 0;
}