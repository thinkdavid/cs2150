//David Becher (dab4au)
//9.16.15
//Stack.h


#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackNode.h"
using namespace std;

class Stack {
public:
    Stack();		       
    bool empty() const;		
    void pop();	
    void push(int x);  
    int top() const;		
    int size() const;
private:
    StackNode *head, *tail;     
    int count;		
    friend class postfixCalculator;	
};

#endif
