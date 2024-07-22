#include "additional_functions.h"
#include <float.h>

// added for ms4
int findTruckForShipment(const struct Map map, const struct Truck trucks[], const int numTrucks, const struct Package package)
{
	int bestTruckIndex = -1;
	double shortestDistance = DBL_MAX;

	for (int i = 0; i < numTrucks; ++i) {
		const struct Truck* truck = &trucks[i];

		// Check if the truck can accommodate the weight and volume of the package
		if (truck->currentWeight + package.weight <= TRUCK_MAX_WEIGHT &&
			truck->currentVolume + package.volume <= TRUCK_MAX_VOLUME) {

			// Calculate the distance from the truck's current position to the package's destination
			double dist = distance(truck->currentPosition, package.destination);

			// If this truck is closer than the previously found best truck, select this truck
			if (dist < shortestDistance) {
				shortestDistance = dist;
				bestTruckIndex = i;
			}
		}
	}
}

int isValidDestination(const struct Map* map, const struct Point destination) {
	// Check if the map is not NULL
	if (map == NULL) {
		return 0;  // Invalid map
	}

	// Check if destination is within map bounds
	if (destination.row < 0 || destination.row >= MAP_ROWS ||
		destination.col < 0 || destination.col >= MAP_COLS) {
		return 0;  // Out of bounds
	}

	// Check if the destination is valid (not a building)
	if (map->squares[destination.row][destination.col] == 1) {
		return 0;  // Invalid destination (building present)
	}

	return 1;  // Valid destination
}

void calculateAvailableSpace(const struct Truck truck, int* availableWeight, int* availableVolume) {
	double availWeight;
	int availVolume;
	if (truck.currentWeight == TRUCK_MAX_WEIGHT) {
		printf("The truck has reached weight capacity!\n");
	}
	else if(truck.currentVolume == TRUCK_MAX_VOLUME) {
		printf("The truck has reached volume capacity!\n");
	}
	else if (truck.currentVolume < TRUCK_MAX_VOLUME && truck.currentWeight < TRUCK_MAX_WEIGHT) {
		availVolume = TRUCK_MAX_VOLUME - truck.currentVolume;
		availWeight = TRUCK_MAX_WEIGHT - truck.currentWeight;
		printf("There is %dkg available.\n", availVolume);
		printf("There is %fkg available.\n", availWeight);
	}
}

int isValidPoint(struct Point* point) {
	if (point == NULL) {
		return 0; // Handle null pointer
	}

	if (point->row >= 0 && point->row < MAP_ROWS && point->col >= 0 && point->col < MAP_COLS) {
		return 1;
	}

	return 0;
}
