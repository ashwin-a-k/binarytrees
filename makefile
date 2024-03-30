CC = g++
CFLAGS = -Wall -g

DECODE_SRC = binarytree.cpp decode.cpp
HUFFMAN_SRC = binarytree.cpp huffman.cpp

DECODE_OBJ = $(DECODE_SRC:.cpp=.o)
HUFFMAN_OBJ = $(HUFFMAN_SRC:.cpp=.o)

DECODE_EXEC = decode
HUFFMAN_EXEC = huffman

all: $(DECODE_EXEC) $(HUFFMAN_EXEC)

$(DECODE_EXEC): $(DECODE_OBJ)
	$(CC) $(CFLAGS) -o $(DECODE_EXEC) $(DECODE_OBJ)

$(HUFFMAN_EXEC): $(HUFFMAN_OBJ)
	$(CC) $(CFLAGS) -o $(HUFFMAN_EXEC) $(HUFFMAN_OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(DECODE_OBJ) $(HUFFMAN_OBJ) $(DECODE_EXEC) $(HUFFMAN_EXEC)

.PHONY: clean
