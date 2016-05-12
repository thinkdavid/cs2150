# Makefile for CS 2150 pre-lab 11
# This Makefile shows how to link doxygen with C/C++

# Defines the C++ compiler we'll be using
CXX	= clang++ 

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g 

DOXYGEN	= doxygen

# All of the .o files for our program
TOLKEIN	= middleearth.cpp traveling.cpp

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).

topSort:	$(TOLKEIN)
	$(CXX) $(CXXFLAGS) $(TOLKEIN); $(DOXYGEN)
	

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program
