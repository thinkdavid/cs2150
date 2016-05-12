// David Becher (dab4au)
// 10.19.15
// hashTable.cpp

#include <iostream>
#include "hashTable.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <list>

using namespace std;

HashTable::HashTable() {
	size = 2003; // hardwired
	table.resize(size);
}

HashTable::HashTable(int size) {
	table.resize(size);
}

HashTable::~HashTable() {

}

void HashTable::readInput(string dict) {
string word;
int n = 0;
int num_words = 0;

ifstream file(dict.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return;
while (file.good()) {
    getline (file, word); 
    n = word.size();
    if(n > 2) {
        num_words++;
        unsigned int hashKey = hash(word);
        insert(hashKey, word);
    }
}
}


unsigned int HashTable::hash(string word) {
	int firstLetter = ((int) word.at(0)) - 49;
    int secondLetter = ((int) word.at(1)) -49;
    int thirdLetter = ((int) word.at(2)) -49;
	int beforeMod = (firstLetter + secondLetter + thirdLetter) + (73*(word.size()-3));
	return beforeMod % table.size();
}

void HashTable::insert(unsigned int key, string value) {
	table[key].push_front(value);
}

bool HashTable::search(string values) {
	if (values.size() > 2) {
	unsigned int look = hash(values);
	for (list<string>::iterator it = table[look].begin(); it != table[look].end(); it++) {
		if (*it == values) {
			return true;
		}
	}
} 
	return false;
}