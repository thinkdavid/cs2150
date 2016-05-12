// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heapNode.h"
using namespace std;

// default constructor
heapNode::heapNode() {
    value = '0';
    priority = 0;
    left = NULL;
    right = NULL;
    prefix = "";
}

heapNode::heapNode(char c, unsigned int i) {
    value = c;
    priority = i;
    left = NULL;
    right = NULL;
    prefix = "";
}

heapNode::heapNode(heapNode* h1, heapNode* h2) {
 value = '-';
 priority= h1->getPriority() + h2->getPriority();
 left = h1;
 right = h2;
}


// the destructor doesn't need to do much
heapNode::~heapNode() {
}


void heapNode::setValue(char x) {
   value = x;
}


unsigned int heapNode::getPriority() {
   return priority;
}

void heapNode::setPriority(unsigned int i) {
    priority = i;
}

void heapNode::incrementPriority() {
    priority++;
}

char heapNode::getValue() {
   return value;
}

void heapNode::print() {
   /* cout << "Value: " << value << "," << " Priority: " << priority << ", Prefix Code: " << prefix << endl;
    if (left != NULL && right !=NULL) {
    	cout << "Left: " << left->value << endl;
    	cout << "Right: " << right->value << endl;
    } */
    	if ((int) value != 32) 
    	cout << value << " " << prefix << endl;
    	else 
    	cout << "space" << " " << prefix << endl;
}
