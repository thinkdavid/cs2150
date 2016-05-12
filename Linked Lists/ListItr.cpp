// David Becher (dab4au)
// ListItr.cpp
// 9.7.15

#include "ListItr.h"
#include "List.h"
#include "ListNode.h"

#include <iostream>

using namespace std;

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}


// Need a way to identify when it's at the end.

bool ListItr::isPastEnd() const {
  if (current->next == NULL) {
    return true;
  } else return false;
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) {
    return true;
  } else return false;
}

void ListItr::moveForward() {
  if (!isPastEnd()) {
    current = current->next;
    return;
  }
  else return;
}

void ListItr::moveBackward() {
  if (!isPastBeginning()) {
    current = current->previous;
    return;
  }
  else return;
}

int ListItr::retrieve() const {
  return current->value;
}
