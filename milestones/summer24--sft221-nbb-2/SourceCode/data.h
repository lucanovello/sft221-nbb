#ifndef DATA_H
#define DATA_H
#define GRID_SIZE 25  // Grid length and width
#define TRUCK_MAX_WEIGHT 2500  // max truck weight
#define TRUCK_MAX_VOLUME 100  // max truck volume

#include "mapping.h"

// Struct for each Cell in the grid, Map will be a 2d array of Cells and position will be indexes
struct Cell
{
    int isBuilding;		//  returns true if cell is a building
    int isPath; 		//  returns true if cell is a path
    char color;		// color of cell if on path ['B'='BLUE', 'Y'='YELLOW', 'G'='GREEN', 'N'='N/A']
};

// Struct for a Package or Shipment
struct Package
{
    double weight;	// weight of package
    double volume;	// volume of package

// I think below fixes the "It ie easier if the shipment destination can be of type Point in the data structure" feedback comment
    Point destination; //points on the map corresponding to package destination

// I think below fixes the "Data structure is missing delivery route info for the shipment/box" feedback comment
    int *route;			// an array holding a list of indexes for the route, might create struct for destination and make this an array of that struct
    int routeLength;		// The length of the route

};

// Struct for a Truck
struct Truck
{
    char routeColour;	// the color of the path taken by the truck ['B'=blue, 'Y'=yellow, 'G'=green]
    double currentWeight;	// the current weight of the truck
    int currentVolume;		// the current volume of the truck
    int *route;			// an array holding a list of indexes for the route, might create struct for destination and make this an array of that struct
    int routeLength;		// The length of the route
};

#endif
