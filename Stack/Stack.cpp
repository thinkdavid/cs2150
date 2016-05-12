//David Becher (dab4au)
//9.16.15
//Stack.cpp

#include "StackNode.h"
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack():count(0) {
  head = new StackNode;
  tail = new StackNode;
  head->next = tail;
  tail->previous = head;
}

int Stack::size() const {
  return count;
}

void Stack::push(int x) {
  StackNode *s = new StackNode();
  s->value = x;
  s->next = tail;
  s->previous = tail->previous;
  tail->previous = s;
  s->previous->next = s;
  count++;
}

void Stack::pop() {
  if (!empty()){
    delete tail->previous->previous->next;
    tail->previous->previous->next = tail;
    tail->previous = tail->previous->previous;
    count--;  
  } 

}

int Stack::top() const {
  if (!empty()) return tail->previous->value;
  return 0;
}

bool Stack::empty() const {
  if (count==0) return true;
  return false;
}
