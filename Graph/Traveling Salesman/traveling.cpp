#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests, float distance);


/**
* Calculates the fastest route between a number of cities in Middle Earth
*
* Takes 5 commmand line parameters
* -# width -- width of the created 2D world. we used 20 in lab
* -# height -- height of the created 2D world. we used 20 in lab
* -# num_cities -- number of cities to put in the world (out of 40)
* -# rand_seed -- each seed would create a different random world, but the same seed would create the same world each time
* 		- enter -1 to create a different world each time
* -# cities_to_visit -- the number of cities to put into the itinerary
* @see computeDistance(MiddleEarth &me, string start, vector<string> dests)
* @see printRoute (string start, vector<string> dests, float distance)
*/
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE
    cout << "itinerary: " << endl; 
    string start = dests[0];
    cout << "start city: " << start <<endl;
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());

    float minDist = numeric_limits<float>::max();
	for (int i =0; i < dests.size(); i++) 
		cout << i << ". " << dests[i] << endl;

	// cout << "The " << cities_to_visit <<"! possible permuations with " << cities_to_visit << " cities" << endl;
	vector<string> route;

	do {
		// printRoute(start, dests);
		if (computeDistance(me, start, dests) < minDist) {
			minDist = computeDistance(me, start, dests);
			route = dests;
		} 
	} while (next_permutation(dests.begin(), dests.end()));

	cout << "----------------------------------------" << endl;
	cout << "The route : " << endl;
	printRoute(start, route, minDist);

    return 0;

}


/**
* This method will compute the full distance of the cycle that starts
* at the 'start' parameter, goes to each of the cities in the dests
* vector IN ORDER, and ends back at the 'start' parameter.
*
* @param &me a reference to the created world in the main method
* @param start the name of the start city, which is where the route starts and ends
* @param dests a vector of city names that are travelled through, in order
* @return a float of the total distance traveled by going through the cycle in the order provided
* @see MiddleEarth
* @see getDistance() method in Middle Earth
*/
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
float distance = me.getDistance(start, dests[0]);

for (int i = 0; i < dests.size()-1; i++) 
    	distance += me.getDistance(dests[i], dests[i+1]);

distance += me.getDistance(dests[dests.size()-1], start);

    return distance;
}

/**
* This method will print the entire route, starting and ending at the
* 'start' parameter.  The output should be of the form:
*
* @param start the name of the start city, which is where the route starts and ends
* @param dests a vector of city names that are travelled through, in order
* @param distance the distance of the total path
* @return outputs the path in order and the distance travelled
* @see computeDistance(MiddleEarth &me, string start, vector<string> dests) 
*/
void printRoute (string start, vector<string> dests, float distance) {
    // YOUR CODE HERE
    cout << "Your journey will take you along the path ";
    cout << start;
    for (int i =0; i < dests.size(); i++) 
    	cout << "-> " << dests[i];
    cout << "-> " << start << " and will have length " << distance << endl;
}
