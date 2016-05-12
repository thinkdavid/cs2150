// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
#include <string>

#ifndef HEAPNODEIN_H
#define HEAPNODEIN_H

using namespace std;

class heapNode {
public:
    heapNode();
    heapNode(char c);
    ~heapNode();

    char getValue();
    void setValue(char x);
    void print();  
    friend class binary_heap;

private:
    char value;
    heapNode * left, * right;
};

#endif
