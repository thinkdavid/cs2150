// David Becher (dab4au)
// 9.14.15
// testPostfixCalc.cpp

#include "postfixCalculator.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    postfixCalculator p;

   while (true) {
        string s;
        cin >> s;
	if(s=="") break;
        if (s.length() > 1) {
	  p.pushNum(atoi(s.c_str()));	  
	} else if (isdigit(s.at(0))) {
	  p.pushNum(atoi(s.c_str()));
	} else {
	  switch (s.at(0)) {
	  case '-':
	    p.subtract();
	    break;
	  case '+':
	    p.add();
	    break;
	  case '/':
	    p.divide();
	    break;
	  case '~':
	    p.negate();
	    break;
	  case '*':
	    p.multiply();
	    break;
	  default:
	    cout <<"Not valid operator!" << endl;
	  }
	}
   }

   cout << "The final answer: " << p.getTopValue() << endl;
    return 0;
}
