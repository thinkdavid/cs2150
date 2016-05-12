// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "heapNode.h"
#include <string>

using namespace std;

class binary_heap {
public:
    binary_heap();
    ~binary_heap();

    void encodePrefix(heapNode* ptr, string prefix) const;
    void find_and_print(heapNode* ptr, char c);
    void insert(heapNode * x);
    void huffmanAdd(heapNode * x);
    heapNode* findMin();
    void reorder();
    heapNode* deleteMin();
    unsigned int size();
    void cleanTree(heapNode *ptr);
    bool isEmpty();
    void print();
    unsigned int getDistinctSymbols() const;
    unsigned int getCompressedBits() const;

private:
    vector<heapNode*> heap;
    unsigned int heap_size;
    unsigned int distinctSymbols;
    unsigned int compressedBits;
    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
