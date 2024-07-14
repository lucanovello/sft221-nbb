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
int isValidDestination(const struct Map map, const struct Point destination);

/** 
 * Calculates the available weight and volume for a truck.
 * @param truck - the truck to check 
 * @param availableWeight - pointer to store the available weight
 * @param availableVolume - pointer to store the available volume 
 **/
void calculateAvailableSpace(const struct Truck truck, int* availableWeight, int* availableVolume);

/** 
 * Finds the shortest path from the truck's route to the destination considering buildings.
 * @param map - the map of the delivery area with buildings on it 
 * @param truckRoute[] - the route of thr truck 
 * @param numPoints - the number of points in the truck's route
 * @param destination - the destination Point to find the path to
 * @param path[] - the array to store the path points
 * @returns The length of the path if found, -1 if no path is found.
 **/
int findShortestPath(const struct Map map, const struct Point truckRoute[], const int numPoints, const struct Point destination, struct Point path[]);




#endif