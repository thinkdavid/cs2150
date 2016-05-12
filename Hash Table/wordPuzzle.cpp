// David Becher (dab4au)
// 10.19.15
// wordPuzzle.cpp

#include "hashTable.h"
#include "timer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char table[MAXROWS][MAXCOLS];

// Forward declarations
bool readInTable (string filename, int &rows, int &cols);
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols);
unsigned int wordsInTable(string filename);
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);


int main (int argc, char* argv[]) {
    // list<string> foundWords;
	string dictFile(argv[1]); 
	int size = getNextPrime((wordsInTable(dictFile))*20);
	HashTable myTable(size);
	myTable.readInput(dictFile);
	timer t;
	list <string> foundWords;

	int rows, cols, maxWordLength, numWords;
	numWords = 0;
    // attempt to read in the file
    bool result = readInTable (string(argv[2]), rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
   
    // cout << endl;

    if(rows > 22 || cols > 22)
    	maxWordLength = 22;
    else if (rows > cols)
    	maxWordLength = rows;
    else 
    	maxWordLength = cols;

   	for ( int startRow = 0; startRow < rows; startRow ++) {
	 	for ( int startCol = 0; startCol < cols; startCol++) {
			for ( int direction = 0; direction < 8; direction++ ) {
				for ( int wordLength = 3; wordLength <= maxWordLength; wordLength++) {	
    				t.start();
        			if(myTable.search(string(getWordInTable(startRow,startCol,direction,wordLength,rows,cols)))) {
                         switch (direction) { // assumes table[0][0] is in the upper-left
           					case 0:
                                foundWords.push_front("N (" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
	               				// cout << "N " << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                				break; // north
            				case 1:
                				//cout << "NE" << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                                foundWords.push_front("NE(" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // north-east
            				case 2:
                				//cout << "E " << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                            foundWords.push_front("E (" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // east
            				case 3:
                				// cout << "SE" << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                            foundWords.push_front("SE(" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // south-east
            				case 4:
                				// cout << "S " << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                            foundWords.push_front("S (" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // south
            				case 5:
                				// cout << "SW" << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                            foundWords.push_front("SW (" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // south-west
            				case 6:
                				// cout << "W " << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                            foundWords.push_front("W (" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // west
            				case 7:
                				// cout << "NW" << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;
                            foundWords.push_front("NW(" + SSTR(startRow) + ", " + SSTR(startCol) + "):\t" + ((string) getWordInTable(startRow,startCol,direction,wordLength,rows,cols)));
                				break; // north-west
        				}
        				// cout << "("  << startRow << ", " << startCol <<  "):\t" << getWordInTable(startRow,startCol,direction,wordLength,rows,cols) << endl;

        				 numWords++;
        			}
        		} 	
		}
	}
}


	t.stop();

    for (list<string>::iterator it = foundWords.begin(); it != foundWords.end(); it++) {
        cout << *it << endl;
        }

	cout << numWords << " words found" << endl;
	cout << "Found all words in " << t.getTime() << " seconds" << endl;
	int totalTime = t.getTime()*1000;
	cout << totalTime << endl;
    // All done!
	return 0;
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global table[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */

bool readInTable (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // table[][] array.  In the process, we'll print the table to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            table[r][c] = line[pos++];
            // cout << table[r][c];
        }
        // cout << endl;
    }
    // return success!
    return true;
}


/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char table[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The length of the string to return (assuming the edge of
 *            the grid is not reached).
 * @param numRows The number of rows in the global char table[][]
 *                array .
 * @param numCols The number of columns in the global char table[][]
 *                array.
 */

char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) ) {
            output[pos++] = '~'; // to stop program from outputting same word, with multiple word lengths
            break; }
        // set the next character in the output array to the next letter
        // in the table
        output[pos++] = table[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

unsigned int wordsInTable(string dict) {
	string word;
	int n = 0;
	unsigned int num_words = 0;

    ifstream file(dict.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return 0;
    while (file.good()) {
        getline (file, word); 
        n = word.size();
        if(n > 2) {
            num_words++;
    }
}

    return num_words;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
