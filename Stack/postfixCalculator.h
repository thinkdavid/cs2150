// David Becher (dab4au)
// 9.14.15
// postfixCalculator.h


#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "Stack.h"

using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  void pushNum(int x);
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  void pop();
  int getTopValue() const;
  bool empty() const;
 private:
  Stack *s;
};

#endif
