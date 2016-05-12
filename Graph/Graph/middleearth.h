#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

/**
* a random 2-dimensional world. 
* @author  David Becher (dab4au)
*
* The "randomness" means that it will pick a given number of cities 
* (or places), and randomly place them in the "world". You can travel from any city to any other 
* city, for a given cost (the distance). The city names are all from the Lord of the Rings books and movies.
*/
class MiddleEarth {
private:
    int num_city_names; 
    int xsize;
    int ysize; 
    vector<float> xpos, ypos;
    vector<string> cities;
    float *distances;
    map<string, int> indices;

public:
    /**
    * A constructor
    *
    * Creates the world of Middle Earth using the x and y size to randomly position cities across the 2-d distance array
    * @param xsize this in combination with ysize is used to compute the 2d distance array
    * @param ysize same as above
    * @param numcities the number of cities in Middle Earth
    * @param seed sets up random number seed
    */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);

    /**
    * A destructor
    * 
    * Deletes the cities in middle Earth
    */
    ~MiddleEarth();

    /**
    * Prints out info on the created world
    * Prints the number of cities and their names
    */
    void print();

    /**
    * Prints a tab-separated table of the distances between cities that can be loaded into excel or a similar program
    */
    void printTable();

    /**
    * Returns the distance between two cities
    * @param city1 the name of the first city
    * @param city2 the name of the second city
    * @return a float of the distance between city1 and city 2
    */
    float getDistance (string city1, string city2);

    /**
    * Returns the list of cities to travel to
    * The list starts and ends at the first city in the list
    * @param length the number of cities (not including the start and end) to put in the itenerary
    * @return a vector of cities with size length to travel
    */
    vector<string> getItinerary(unsigned int length);
};

#endif
