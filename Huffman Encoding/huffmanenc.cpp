// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "heap.h"
#include "heapNode.h"

binary_heap theHeap;

int main( int argc, char *argv[] ) {
   int symbols =0;

  if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
// cout << "----------------------------------------" << endl;
// cout << "Counting Frequencies: " << endl;
    char g;
    // cout << "Original Text: ";
    while ( (g = fgetc(fp)) != EOF ) {
        if ((int)g >= 32 && (int)g <= 126) {
    theHeap.insert(new heapNode(g, 1));
    symbols++;
}
}

    theHeap.reorder();
    // theHeap.print();

// cout << "----------------------------------------" << endl;
// cout << "Creating Huffman Tree:" << endl;
int sz = theHeap.size(); 
for ( int i = 1; i < sz; i++) {
	// cout << "Minimum 1: ";
// theHeap.findMin()->print();
heapNode *h1 = theHeap.deleteMin();
	// cout << "Minimum 2: ";
// theHeap.findMin()->print();
heapNode *h2 = theHeap.deleteMin();
heapNode *h3 = new heapNode(h1, h2);
theHeap.huffmanAdd(h3);
	// cout << "Updated Tree: " ;
// theHeap.print();
}
// cout << "Finished Huffman Tree: " << endl;
// theHeap.print();

// cout << "----------------------------------------" << endl;
// cout << "Encoding Prefix Codes:" << endl;

// This is where the key for the prefix codes is printed
theHeap.encodePrefix(theHeap.findMin(), "");

cout << "----------------------------------------" << endl;
// cout << "Encoding the Message: " << endl;
rewind(fp);
    // read the file again, and print to the screen

// This is where the Encoded Text is Printed
int total_original_bits = 0;
int total_compressed_bits = 0;
    while ( (g = fgetc(fp)) != EOF ) {
        theHeap.find_and_print(theHeap.findMin(), g);
    }
    fclose(fp);

    total_original_bits = symbols * 8;
    total_compressed_bits = theHeap.getCompressedBits();
    int distinctSymbols = theHeap.getDistinctSymbols();
    double compressionRatio = (double) total_original_bits / (double) total_compressed_bits;
    double costTree = (double) total_compressed_bits / (double) symbols ;

cout << "\n----------------------------------------" << endl;
cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
cout << "There are " << distinctSymbols << " distinct symbols used." << endl;
cout << "There were "  << total_original_bits << " in the original file." << endl;
cout << "There were "  << total_compressed_bits << " in the compressed file." << endl;
cout << "This gives a compression ratio of " << compressionRatio << "." << endl;
cout << "The cost of the Huffman tree is " << costTree << " bits per character." << endl;

}


