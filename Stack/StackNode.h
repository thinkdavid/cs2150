//David Becher (dab4au)
//9.16.15
//StackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class StackNode {
public:
    StackNode();                 // Constructor

private:
    int value;
    StackNode *next, *previous;	// for doubly linked lists

    friend class Stack;
    friend class postfixCalculator;

};

#endif
