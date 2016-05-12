// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAPIN_H
#define HEAPIN_H

#include <vector>
#include "heapNodeIN.h"
#include <string>

using namespace std;

class binary_heap {
public:
    binary_heap();
    ~binary_heap();

    void find_and_print(string bits, heapNode *ptr);
    void insert(string str, char c, heapNode* h);
    heapNode* getRoot();
    unsigned int size();
    void cleanTree(heapNode *ptr);
    bool isEmpty();
    void print();
    unsigned int getDistinctSymbols() const;
    unsigned int getCompressedBits() const;

private:
    heapNode* root;
    unsigned int heap_size;
    unsigned int distinctSymbols;
    unsigned int compressedBits;
};

#endif
