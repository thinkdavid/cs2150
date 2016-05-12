// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <vector>
#include <string>
#include "heapIN.h"
#include "heapNodeIN.h"
using namespace std;

// default constructor
binary_heap::binary_heap() : heap_size(0) {
    distinctSymbols = 0;
    compressedBits = 0;
    root = new heapNode();
}


// the destructor doesn't need to do much
binary_heap::~binary_heap() {
	cleanTree(getRoot());
	heap_size = 0;
}

void binary_heap::insert(string str, char c, heapNode * ptr) {
    	// cout << "current substring: " << str << endl;
    	if (str.length() == 0) {
    		ptr->value = c;
    		// cout << c << " inserted!" << endl;
    	}

// cout << "substring is not length 0" << endl;
    	if (str[0] == '0') {
    		if (ptr->left == NULL) 
    			ptr->left = new heapNode();
    		// cout << "inserting " << c << ".....going left" << endl;
    		insert(str.substr(1), c, ptr->left);
    	}
    	if (str[0] == '1') {
    		if (ptr->right == NULL) 
    			ptr->right = new heapNode();
    		// cout << "inserting " << c << ".....going right" << endl;

    		insert(str.substr(1), c, ptr->right);
    	}
    
}


void binary_heap::find_and_print(string bits, heapNode* ptr){
// cout << "current bit substring: " << bits << endl;
// ptr->print();

// ptr == root node (which always has children)
if (ptr->left == NULL && ptr->right == NULL) {
	// cout << "found a leaf!" << endl;
	cout << ptr->value;
	ptr = root;
}

if (bits[0] == '0') {
	// cout << "traversing left" << endl;
	find_and_print(bits.substr(1), ptr->left);
}
if (bits[0] == '1') {
	// cout << "traversing right" << endl;
    find_and_print(bits.substr(1), ptr->right);

}
    	
}


heapNode* binary_heap::getRoot() {
    return root;
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
}


