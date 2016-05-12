#include "vertex.h"
#include <string>
#include <iostream>

using namespace std;

vertex::vertex() {
	indegree = 0;
	topologicalNum =0;
}

vertex::vertex(string n) {
	name = n;
	indegree = 0;
	topologicalNum =0;
}

vertex::~vertex() {
}
