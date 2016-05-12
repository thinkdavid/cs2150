// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <vector>
#include "heap.h"
#include "heapNode.h"
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    heap.push_back(new heapNode());
    distinctSymbols = 0;
    compressedBits = 0;
}


// the destructor doesn't need to do much
binary_heap::~binary_heap() {
	cleanTree(findMin());
	heap_size = 0;
}



void binary_heap::insert(heapNode* x) {
    // a vector push_back will resize as necessary
    // check if the character is already in the tree
    bool exist = false;
    for ( int i = 1; i <= heap_size; i++ ) { 
        if (x->getValue() == heap[i]->getValue()) {
            exist = true;
            heap[i]->incrementPriority();
        }

    }

    // If not, put it in the heap
    if (!exist) {
    heap.push_back(x);
    // move it up into the right position
    distinctSymbols++;
    percolateUp(++heap_size);
    }

}

void binary_heap::huffmanAdd(heapNode* x) {
    heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
    }


void binary_heap::reorder() {
    for ( int i = 1; i <= heap_size; i++ ) 
        percolateUp(i);
}


void binary_heap::encodePrefix(heapNode* ptr, string prefix) const {
  if (ptr!= NULL)  {
    encodePrefix(ptr->left, prefix + "0");
    encodePrefix(ptr->right, prefix + "1");
    if (ptr->left == NULL && ptr->right == NULL) {
	ptr->prefix = prefix;
	ptr->print();
  }
}
}

void binary_heap::find_and_print(heapNode* ptr, char c){
 
  if (ptr!= NULL)  {
    find_and_print(ptr->left, c);
    find_and_print(ptr->right, c);
    if(ptr->value == c) {
  	cout << ptr->prefix << " ";
  	int prefixLength = ptr->prefix.length();
  	compressedBits += prefixLength;
  }
}

}

void binary_heap::percolateUp(int hole) {
    // get the value just inserted
    heapNode * x = heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->getPriority() < heap[hole/2]->getPriority()); hole /= 2 ) {
        heap[hole] = heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
}

heapNode* binary_heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 ) {
        cout << "deleteMin() called on empty heap" << endl;
        throw "deleteMin() called on empty heap";
    }
    // save the value to be returned
    heapNode* ret = heap[1];
    // move the last inserted position into the root
    heap[1] = heap[heap_size--];
    // make sure the vector knows that there is one less element
    heap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
} 

void binary_heap::percolateDown(int hole) {
    // get the value to percolate down
    heapNode * x = heap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (heap[child+1]->getPriority() < heap[child]->getPriority()) )
            child++;
        // if the child is greater than the node...
        if ( x->getPriority() > heap[child]->getPriority() ) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heap[hole] = x;
} 

heapNode* binary_heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heap[1];
}


unsigned int binary_heap::size() {
    return heap_size;
}

void binary_heap::cleanTree(heapNode * ptr) {
if (ptr!= NULL)  {
    cleanTree(ptr->left);
    cleanTree(ptr->right);
    if(ptr->left == NULL && ptr->right == NULL) {
    	delete ptr;
    }
}
}

bool binary_heap::isEmpty() {
    return heap_size == 0;
}

unsigned int binary_heap::getDistinctSymbols() const{
	return distinctSymbols;
}

unsigned int binary_heap::getCompressedBits() const{
	return compressedBits;
}


void binary_heap::print() {
    cout << "(" << heap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        heap[i]->print();
        // next line from from http://tinyurl.com/mf9tbgm
       /* bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl; */
}
}

