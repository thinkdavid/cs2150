# Makefile for CS 2150 in-lab 5

# Defines the C++ compiler we'll be using
CXX	= clang++ -O2

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -lrt 

# All of the .o files for our program
OFILES	= hashTable.o wordPuzzle.o timer.o 

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).
main:	$(OFILES)
	$(CXX) $(OFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# The following lines define the dependencies for this lab.  For
# example, if avltree.h is modified, then make knows to re-compile
# avltree.o and tree_test.o (and the final executable).  These lines
# are generated through the command 'clang++ -MM *.cpp', and that output
# is pasted below.
hashTable.o: hashTable.h hashTable.cpp 
wordPuzzle.o: hashTable.h hashTable.cpp 
timer.o: timer.h timer.cpp

