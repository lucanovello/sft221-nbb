#ifndef DATA_H
#define DATA_H

#define GRID_SIZE 25
#define TRUCK_MAX_WEIGHT 2500
#define TRUCK_MAX_VOLUME 100

// Struct for each Cell in the grid
struct Cell
{
    int isBuilding;
    int isPath;
    char color;	// color of cell if on path ['B'='BLUE', 'Y'='YELLOW', 'G'='GREEN', 'N'='N/A']
};

// Struct for a Package
struct Package
{
    double weight;
    double size;
	int destinationRow;
    char destinationCol;	// will need to get converted to a array index later in function (through ASCII).
};

// Struct for a Truck
struct Truck
{
    char routeColour;     // the path taken by the truck ['B'='BLUE', 'Y'='YELLOW', 'G'='GREEN']
    double current_weight;
    int current_volume;
    int *route;
    int routeLength;
};


#endif