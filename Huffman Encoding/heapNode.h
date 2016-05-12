// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
#include <string>

#ifndef HEAPNODE_H
#define HEAPNODE_H

using namespace std;

class heapNode {
public:
    heapNode();
    heapNode(char c, unsigned int i);
    heapNode(heapNode* h1, heapNode* h2);
    ~heapNode();

    unsigned int getPriority();
    char getValue();
    void setPriority(unsigned int i);
    void setValue(char x);
    void incrementPriority();
    void print();  
    string prefix;
    friend class binary_heap;

private:
    char value;
    heapNode * left, * right;
    unsigned int priority;
};

#endif
