# Makefile for CS 2150 pre-lab 8
# This Makefile shows how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX	= clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g 

# All of the .o files for our program
OFILES = heapNode.o heap.o huffmanenc.o heapNodeIN.o heapIN.o inlab-skeleton.o

OFILESE	= heapNode.o heap.o huffmanenc.o

OFILESD = heapNodeIN.o heapIN.o inlab-skeleton.o

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp


main:	$(OFILES)
	$(CXX) $(CXXFLAGS) -o decoder $(OFILESD) ;$(CXX) $(CXXFLAGS) -o encoder $(OFILESE)


	
	
#mathfun.o: mathfun.cpp
#sss	$(CXX) $(CXXFLAGS) -c mathfun.cpp
	
#mathlib.o: mathlib.s
#	$(AS) $(ASFLAGS) mathlib.s



# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program
