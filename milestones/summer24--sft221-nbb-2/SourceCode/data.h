#ifndef DATA_H
#define DATA_H

#define TRUCK_MAX_WEIGHT_CAPACITY 2500
#define TRUCK_MAX_BOX_SIZE_CAPACITY 100

// Define the struct for a package
struct Package
{
    double weight;
    double size;
    char destination[100][100]; //not sure if routes should be formatted like this?
};

// Define the struct for a truck
struct Truck
{
    char routeColour[10];     // the path taken by the truck (e.g., 'BLUE', 'YELLOW', 'GREEN')
    float max_weight_capacity;
    int max_volume_capacity;
    float current_weight;
    int current_volume;
};

#endif