CS-271-01: Data Structures
Spring 2024
Professor Kretchmar

Project 5: Binary Tree Huffman Coding
Daniel Chu, Ashwin Krishnamurthy, Jianheng Guo

# Huffman Coding Project Documentation

## Overview

This project involves implementing Huffman Coding using a binary tree data structure in C++. The main objectives are to parse the novel "War and Peace" for letter frequency, construct a binary tree to represent this frequency, and then apply Huffman Coding for efficient data encoding and decoding.

## File Descriptions

- `WarPeace.txt`: The text file containing the novel "War and Peace" used for analyzing letter frequency.
- `binarytree.cpp` and `binarytree.h`: C++ source files defining the `BinaryTree` class used for constructing the binary tree and implementing Huffman Coding.
- `count.py`: Python script for counting letter frequencies in the text file. Outputs `frequency.txt`.
- `encode.py`: Python script that encodes a given text using the Huffman Coding scheme generated from `WarPeace.txt`.
- `decode.cpp`: C++ program that decodes the encoded text back to its original form using the Huffman Coding scheme.
- `huffman.cpp`: Main C++ program that reads the frequency data, constructs the Huffman tree, and generates the encoding scheme.

## Instructions

1. **Frequency Analysis**:
    - Run `count.py` on `WarPeace.txt` to generate `frequency.txt`, containing each letter's frequency.

2. **Building the Huffman Tree**:
    - Compile `huffman.cpp` and `binarytree.cpp` with `g++` or an equivalent C++ compiler.
    - Run the resulting executable, feeding it `frequency.txt`, to produce `code_table.txt`, which contains the Huffman Codes for each character.

3. **Encoding Text**:
    - Use `encode.py` to encode a text file using the Huffman Codes from `code_table.txt`. The output is a binary string representing the encoded text.

4. **Decoding Text**:
    - Compile `decode.cpp` and run the resulting executable to decode a binary string back into readable text using the Huffman tree.

## Compilation and Execution

- Compile the C++ programs using a command similar to `g++ -o huffman huffman.cpp binarytree.cpp`.
- Run the programs as follows:
    ```
    ./huffman < frequency.txt > code_table.txt
    python encode.py < input.txt > encoded.txt
    ./decode < encoded.txt > decoded.txt
    ```

## Dependencies

- C++ compiler (e.g., GCC, Clang)
- Python interpreter (for `count.py` and `encode.py`)

## Project Structure

- Source code: `binarytree.cpp`, `binarytree.h`, `huffman.cpp`, `decode.cpp`
- Scripts: `count.py`, `encode.py`
- Data files: `WarPeace.txt`, `frequency.txt`, `code_table.txt`
- Output: Encoded and decoded text files

## Additional Notes

- Thoroughly comment your code to explain the implementation of the binary tree and Huffman Coding.
- Ensure proper error handling in reading files and processing data.
- Optimize the binary tree and Huffman Coding implementation for efficiency and readability.
