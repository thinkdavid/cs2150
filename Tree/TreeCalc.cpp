// David Becher (dab4au)
// 10.11.15
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr!= NULL) {
    cleanTree(ptr->left);
    cleanTree(ptr->right);
    delete ptr;
   }  
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  if (val.length() > 1 || (isdigit(val.at(0)))) {     
  TreeNode *a = new TreeNode(val);
  mystack.push(a);
  } else {
    TreeNode *right = mystack.top();
    mystack.pop();
    TreeNode *left = mystack.top();
    mystack.pop();
    TreeNode *a = new TreeNode(val);
    mystack.push(a);
    mystack.top()->left = left;
    mystack.top()->right = right;
	}
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if (ptr != NULL) {  
    cout << ptr->value << " ";
    printPrefix(ptr->left);
    printPrefix(ptr->right);
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
   if (ptr!=NULL) {
    printInfix(ptr->left);
    cout << ptr->value << " ";
    printInfix(ptr->right);
  } 
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
  if (ptr!= NULL)  {
    printPostfix(ptr->left);
    printPostfix(ptr->right);
    cout << ptr->value << " ";
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
  if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(mystack.top());
        cout << endl;
   } else
        cout<< "Size is 0." << endl;
}


int TreeCalc::calculate(TreeNode* ptr) const {
int a,b;
int answer = 0;
string s;
stringstream out;

if (ptr!= NULL)  {
    calculate(ptr->left);
    calculate(ptr->right);
    if (ptr->value.length() == 1 && (!isdigit(ptr->value.at(0)))) {
		switch(ptr->value.at(0)) {
			case '+':
				  a = atoi(ptr->left->value.c_str());
  				b = atoi(ptr->right->value.c_str());
          out << a+b;
          ptr->value = out.str();
  				break;
  			case '-':
				  a = atoi(ptr->left->value.c_str());
  				b = atoi(ptr->right->value.c_str());
  				out << a-b;
          ptr->value = out.str();
  				break;
  			case '*':
				a = atoi(ptr->left->value.c_str());
  				b = atoi(ptr->right->value.c_str());
  				out << a*b;
          ptr->value = out.str();
  				break;
  			case '/':
				  a = atoi(ptr->left->value.c_str());
  				b = atoi(ptr->right->value.c_str());
  				out << a/b;
          ptr->value = out.str();
  				break;
      }
    }
answer = atoi(ptr->value.c_str());
}
return answer;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    
    // call private calculate method here
    int ans = calculate(mystack.top());  
    cleanTree(mystack.top());  
    return ans;
    
}

