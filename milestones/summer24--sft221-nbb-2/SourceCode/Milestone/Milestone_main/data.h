#ifndef DATA_H
#define DATA_H
#include "mapping.h"

/**
 * Struct for a Package or Shipment
 * @param Point destination - points on the map corresponding to package destination
 * @param weight - weight of package
 * @param volume - volume of package
**/
struct Package {
    struct Point* destination;
    double weight;
    double volume;
};
/**
 * Struct for a Truck
 * @param Point currentPosition - the current position of the truck;
 * @param currentWeight - the current weight of the truck
 * @param currentVolume - the current volume of the truck
 * @param routeSymbol - the routeSymbol of the path taken by the truck ['B'=blue, 'Y'=yellow, 'G'=green]
 * @param Route route - an array holding a list of Packages for the route
 * @param routeLength - The length of the route
**/
struct Truck {
	struct Point* currentPosition;
    double currentWeight;
    double currentVolume;
    char routeSymbol;
    struct Route* route;
    int routeLength;
};

#endif
