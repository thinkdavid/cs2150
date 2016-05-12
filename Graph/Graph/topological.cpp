// This program shows how C-based file I/O works.  It will open a
// file, read in the first two strings, and print them to the screen.

// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "vertex.h"
#include "graph.h"
using namespace std;

Graph g;

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

	string s1, s2;
 	file >> s1;
    file >> s2;
    while (s1 != "0" && s2 != "0") {
    // cout << s1 << " connects to " << s2 << endl;

    // insert into graph //
    vertex * v1 = new vertex(s1);
    vertex * v2 = new vertex(s2);

    g.insertVertex(v1, v2);
    // cout << "---------------------------------\n";
    file >> s1;
    file >> s2;
}

	g.topSort();

    // close the file before exiting
    file.close();

    cout <<" \n";
}

