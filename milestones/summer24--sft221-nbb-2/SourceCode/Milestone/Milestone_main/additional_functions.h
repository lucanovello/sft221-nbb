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
 **/
int findTruckForShipment(const struct Map map, const struct Truck trucks[], const int numTrucks, const struct Package package);

/**
 * Check if the given destination is valid based on the map.
 * @param map - the map of the delivery area with buildings on it
 * @param destination -  the destination point to check
 * @returns 1 if the destination is valid, 0 otherwise.
 **/
int isValidDestination(const struct Map* map, const struct Point destination);

/** 
 * Calculates the available weight and volume for a truck and if a package will fit in it.
 * @param truck - the truck to check if the package will fit
 * @param package - the package to check 
 * @returns 1 if the package will fit in the truck, 0 otherwise.
 **/
int calculateAvailableSpace(const struct Truck truck, const struct Package package);

/** 
 * evaluates a point to see if it fits the map criteria in this project.
 * @param point - the point to check
 * @returns 1 if the point is valid, 0 if otherwise.
 **/
int isValidPoint(struct Point* point);

#endif