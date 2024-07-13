#ifndef ADDITIONAL_FUNCTIONS_H_
#define ADDITIONAL_FUNCTIONS_H_

#include "mapping.h"
#include "data.h"

/**
 * Finds the best truck for a shipment. If there is no truck that can deliver the shipment, it returns -1.
 * @param map - the map of the delivery area with buildings on it
 * @param trucks[] - an array of trucks including the route for each of the trucks
 * @param numTrucks - the number of trucks in the array of trucks
 * @param package - a data structure containing the size and weight of the shipment
 * @returns An integer representing the index of the truck in the trucks array on which the shipment should be placed. If no truck can take the shipment, then -1 is returned.
 */
int findTruckForShipment(const struct Map map, const struct Truck trucks[], const int numTrucks, const struct Package package);



#endif