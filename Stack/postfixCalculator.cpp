// David Becher (dab4au)
// 9.14.15
// postfixCalculator.cpp

#include "postfixCalculator.h"
#include <cstdlib>

using namespace std;

postfixCalculator::postfixCalculator() {
  s = new Stack;
}

void postfixCalculator::subtract() {
  
  int a = getTopValue();
  pop();
  int b = getTopValue();
  pop();
  pushNum(b-a);
}

void postfixCalculator::multiply() {
  int a = getTopValue();
  pop();
  int b = getTopValue();
  pop();
  pushNum(b*a);
}

void postfixCalculator::divide() {
  int a = getTopValue();
  pop();
  int b = getTopValue();
  pop();
  pushNum(b/a);
}

void postfixCalculator::add() {
  int a = getTopValue();
  pop();
  int b = getTopValue();
  pop();
  pushNum(b+a);
}

void postfixCalculator::negate() {
  int a = getTopValue();
  pushNum(-a);
}

void postfixCalculator::pushNum(int x) {
  s->push(x);
}

void postfixCalculator::pop(){
  s->pop();
  }

int postfixCalculator::getTopValue() const {
  return s->top();
  }

bool postfixCalculator::empty() const {
  return s->empty();
}
