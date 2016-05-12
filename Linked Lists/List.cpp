// David Becher (dab4au)
// 9.7.15
// List.cpp

#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

List::List():count(0) {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
}

List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if (count == 0){
    return true;
  }
  else return false;
}

void List::makeEmpty(){
  ListItr l = first();
  while (count !=0) {
     l.current->previous->next = l.current->next;
     l.current->next->previous = l.current->previous;
      delete l.current;
      count--;
      l = first();
}
  
}


ListItr List::first(){
  ListItr *l = new ListItr();
  l->current = head->next;
  return *l;
}

ListItr List::last(){
  ListItr *l = new ListItr();
  l->current = tail->previous;
  return *l;
}

void List::insertAfter(int x, ListItr position) {
 if (!position.isPastEnd()){
  ListNode *l = new ListNode();
  l->value = x;
  l->previous = position.current;
  l->next = position.current->next;
  position.current->next = l;
  l->next->previous =l;
  count++;
 } else cout << "The List Iterator is past the end!" << endl;

}

void List::insertBefore(int x, ListItr position){
  if (!position.isPastBeginning()){
  ListNode *l = new ListNode();
  l->value = x;
  l->next = position.current;
  l->previous = position.current->previous;
  position.current->previous = l;
  l->previous->next = l;
  count++;
  } else {
    cout << "The List Iterator is past the beginning" << endl;
  }}

void List::insertAtTail(int x) {

  ListNode *l = new ListNode();
  l->value = x;
  l->next = tail;
  l->previous = tail->previous;
  l->previous->next = l;
  tail->previous = l;
  count++; 
  
}

void List::remove (int x) {
  ListItr l = first();
  for (int i=0; i <= count; i++) {
    if (l.current->value == x) {
      //remove the item
      l.current->previous->next = l.current->next;
      l.current->next->previous = l.current->previous;
      delete l.current;
      l.current = tail;
	count--;
    } else 
    l.moveForward();
}
  return;
}

ListItr List::find(int x) {
  ListItr *l = new ListItr();
  l->current = head->next;
  for (int i=1; i <= count; i++) {
    if (l->current->value == x) {
      cout << "Found it at position" << i << endl;
      return *l;
    } else l->moveForward();
}
  // cout << "Could not find" << endl;
  l->current = tail;
  return *l;
}

int List::size() const {
  return count;
}



void printList(List& source, bool direction) {
  ListItr *l = new ListItr();
  int i = 1;
  int p = source.size();
  if (direction) {
    *l = source.first();
    while(!l->isPastEnd()) {
      cout << "In position " << i << ": " << l->retrieve() << endl;
      l->moveForward();
      i++;
    }} else {
    *l = source.last();
    while(!l->isPastBeginning()){
      cout << "In position " << p << ": " << l->retrieve() << endl;
      l->moveBackward();
      p--;
}
    }
}
