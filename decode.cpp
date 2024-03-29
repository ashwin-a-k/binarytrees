//======================================================
// decode.cpp
// decodes the song and put back in plain text (w/o 
// punctutation)
// Name: Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo
// March 2024
//======================================================

#include "binarytree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Name of Code Vector file:" << endl;
    string fname = "";
    cin >> fname;

    ifstream file(fname);
    string line;
    BinaryTree tree;

    while (getline(file, line)) {
        pair<int, char> data(0, (char)line[0]);
        tree.PathInsert(data, line.substr(2));
    }

    cout << "Name of Encoded file:" << endl;
    string fname_encoded = "";
    cin >> fname_encoded;

    ifstream file_encoded(fname_encoded);
    string line2;

    while (getline(file_encoded, line2))
        cout << tree.Decoder(line2) << endl;

    return 0;
}