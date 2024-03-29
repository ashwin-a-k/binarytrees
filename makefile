CXX = g++
CXXFLAGS = -Wall -std=c++11

all: encode decode

encode: encode.o binarytree.o
    $(CXX) $(CXXFLAGS) -o encode encode.o binarytree.o

decode: decode.o binarytree.o
    $(CXX) $(CXXFLAGS) -o decode decode.o binarytree.o

encode.o: encode.cpp binarytree.h
    $(CXX) $(CXXFLAGS) -c encode.cpp

decode.o: decode.cpp binarytree.h
    $(CXX) $(CXXFLAGS) -c decode.cpp

binarytree.o: binarytree.cpp binarytree.h
    $(CXX) $(CXXFLAGS) -c binarytree.cpp

clean:
    rm -f encode decode *.o
