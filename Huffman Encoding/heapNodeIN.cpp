// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heapNodeIN.h"
using namespace std;

// default constructor
heapNode::heapNode() {
    value = '~';
    left = NULL;
    right = NULL;
}

heapNode::heapNode(char c) {
    value = c;
    left = NULL;
    right = NULL;
}



// the destructor doesn't need to do much
heapNode::~heapNode() {
}


void heapNode::setValue(char x) {
   value = x;
}


char heapNode::getValue() {
   return value;
}

void heapNode::print() {
    cout << "Value: " << value << endl;
    if (left != NULL && right !=NULL) {
    	cout << "Left: " << left->value << endl;
    	cout << "Right: " << right->value << endl;
    } else 
    cout << "Is a Leaf" << endl;
}
