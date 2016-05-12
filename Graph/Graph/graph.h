#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "vertex.h"

using namespace std;

/** 
* a Graph class
* @author  David Becher (dab4au)
* 
* <b> Private Fields </b> <br>
* NUM_VERTICES -- an private integer that contains the number of vertices in the graph <br>
* vertices -- a privatevector of the vertices contained in the graph <br><br>
* <b> Description </b> <br>
* A class to hold all the computer science classes at UVA and their hierarchical format
*/
class Graph {
	public:

    /** 
    * A default constructor
    *
    * Sets the NUM_VERTICES variable to zero.
    */
  Graph(); 
  
  /**
  * A destructor
  */
  ~Graph();

  /** This function performs and prints out the results of a topological sort
   *  
   *  @return the vertices in a topological order, printing their names in order separated by a space
   */
  void topSort(); 

  /**
   * This function takes two vertices and adds them to the graph
   * This depends on which of four cases it falls in.
   *    -# Both the vertices are already in the graph
   *      - update the existing vertex in the graph matching v1's name's connected vertices to include the destination vertex already in the graph
   *      - increase the indegree of that destination vertex in the graph by 1
   *    -# Both the vertices aren't in the graph yet
   *      - update v1's connected vertices to include v2
   *      - increase the indegree of v2 += 1
   *      - add both v1 and v2 to the vertices vector
   *    -# v1 isn't in the graph, v2 is already in the graph
   *      - update v1->connected vertices to include the vertex in the graph matching v2's name
   *      - increase the indegree of the vertex in the graph matching v2's name by 1
   *      - add v1 to the vertices vector
   *    -# vertex 1 is already in the graph, vertex 2 isn't 
   *      - update the vertex in the graph matching v1's name->connected vertices to include v2
   *      - increase the indegree of the added v2 by 1
   *      - add v2 to the vertices vector
   *
   * @param v1 a pointer to the source vertex
   * @param v2 a pointer to the vertex connected to the source vertex
   */
  void insertVertex(vertex* v1, vertex *v2);

	private:

  /**   
   * a private vector of vertex pointers that holds pointers to all the vertices in the graph
   */
  vector<vertex*> vertices; 

/**
* a private int variable
* contains the number of vertices in the graph
*/
  int NUM_VERTICES; 
};

#endif
