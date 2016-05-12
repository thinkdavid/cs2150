#include <string>
#include <vector>

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

/** 
 * A vertex class
 * @author	David Becher (dab4au)
 *
 * <b> Private Fields </b><br>
 *  indegree -- a private integer variable that contains the number of verticles that connect to this vertex via a directed edge<br>
 *  topologicalNum -- defaults to zero and is modified by Graph topSort() method; stores the order of this vertex in the graph's topological Sort<br>
 *  connectedVertices -- a vector that contains the vertices that this vertex connects to via directed edge<br>
 *  name -- a string that contains the name of this vertex<br><br>
 *<b> Description </b> <br>
 * Holds the name of the vertex, its indegree, a field for it's topological number when sorted
 * and a vector of vertices it is connected to by directed edges
*/
class vertex {
	public:

		/**
		 * A default constructor
		 */
		vertex();

		/** 
		* A constructor that takes in a string parameter
		* Takes a string parameter and creates a new vertex with name variable = n
		* @param n a string variable to be stored in the name field of the new vertex
		*/
		vertex(string n);
		/**
		* A destructor
		*/
		~vertex();

		/**
		* So the Graph class can modify the fields of the vertices it holds
		*/
		friend class Graph;

	private:
		/**
		* a private integer variable
		* contains the number of vertices that connect to this vertex via directed edge
		*/
		int indegree;

		/**
		* a private integer variable
		* defaults to zero, modified by Graph's topSort() method
		* @see topSort()
		* order of this vertex in the graph's topological sort
		*/
		int topologicalNum;

		/**
		* a private vector
		* contains the vertices that this vertex connects to via directed edge
		*/
		vector<vertex*> connectedVertices;

		/**
		* The name of this vertex
		*/
		string name;
};

#endif