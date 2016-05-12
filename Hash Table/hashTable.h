// David Becher (dab4au)
// 10.19.15
// hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <list>
 
using namespace std;

class HashTable {
public:

    HashTable();						//Constructor
    HashTable(int size);
    ~HashTable();						//Destructor

    void readInput(string dict);	
    bool search(string values);
    void insert(unsigned int key, string value);	
    unsigned int hash(string word);


private:
  unsigned int size;
  vector <list <string> > table; 

};

#endif
