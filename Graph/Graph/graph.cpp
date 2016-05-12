#include <vector>

#include "vertex.h"
#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph() {
NUM_VERTICES = 0;
}

Graph::~Graph() {

}

void Graph::insertVertex(vertex* v1, vertex*v2) {
/* Potential Cases 
Case 1: vertex 1 is new, vertex 2 is new to the graph:
	updated v1->connected vertices to include v2
	increase the indegree of v2 += 1
	add both v1 and v2 to the graph
Case 2: vertex 1 is new, vertex 2 is already in the graph
	update v1->connected vertices to include v2
	increase the indegree of v2 +=1
	add v1 to the graph
Case 3: vertex 1 is already in the graph, vertex 2 is new
	update v1->connected vertices to include v2
	increase the indegree of v2 +=1
	add v2 to the graph
Case 4: both are already in the graph
	update v1->connected vertices to include v2
	increase the indegree of v2 +=1
*/

// cout << "Current number of vertices: " << NUM_VERTICES << endl;
// cout << "Current vertices" << endl;

	if (NUM_VERTICES != 0) {
	bool case1 = false;
	bool case2 = false;
	bool case3 = false;
	bool case4 = false;
	bool isV1new = true;
	bool isV2new = true;
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < NUM_VERTICES; i++) {
		// vertices[i]->print();

		// if v1 already is in the graph
		if (vertices[i]->name == v1->name) {
			isV1new = false;
			i1 = i;
		}
		if (vertices[i]->name == v2->name) {
			isV2new = false;
			i2 = i;
		}
	}

	if (!isV1new && !isV2new)
		case4 = true;
	else if(isV1new && !isV2new) 
		case2 = true;
	else if (isV2new && !isV1new)
		case3 = true;
	else
		case1= true;

if (case1) {
	// cout << "Case1" << endl;
	v2->indegree+=1;
	v1->connectedVertices.push_back(v2);
	vertices.push_back(v1);
	vertices.push_back(v2);
	NUM_VERTICES +=2;
} else if (case2) {
	// cout << "Case2" << endl;
	vertices[i2]->indegree+=1;
	v1->connectedVertices.push_back(vertices[i2]);
	vertices.push_back(v1);
	NUM_VERTICES += 1;
} else if (case3) {
	// cout << "Case3" << endl;
	v2->indegree+=1;
	vertices[i1]->connectedVertices.push_back(v2);
	vertices.push_back(v2);
	NUM_VERTICES +=1;
} else if (case4) {
	// cout << "Case 4" << endl;
	vertices[i2]->indegree += 1;
	vertices[i1]->connectedVertices.push_back(vertices[i2]);
}


} else {
	// this is only for the first insert
// cout << "First insert!" << endl;
v2->indegree += 1;
v1->connectedVertices.push_back(v2);
vertices.push_back(v1);
vertices.push_back(v2);
NUM_VERTICES += 2;
}



}

 /** This function performs and prints out the results of a topological sort
   *  
   *  @return the vertices in a topological order, printing their names in order separated by a space
   */
void Graph::topSort() {
	
	queue<vertex*> q;
 	int counter = 0;
 	vertex *v;

  for (int i = 0; i < NUM_VERTICES; i++) {
		if (vertices[i]->indegree == 0)
			q.push(vertices[i]);
	}
  while (!q.empty()) {
    v = q.front(); 
    q.pop();
    v->topologicalNum = ++counter;
    cout << v->name << " ";
    //for each w adjacent to v: // insert eligible verts
    for (int i = 0; i < v->connectedVertices.size(); i++) {
      if (--v->connectedVertices[i]->indegree == 0)
        q.push(v->connectedVertices[i]);
  }
  /*
  if (counter != NUM_VERTICES)
   throw CycleFound(); */
}
}
