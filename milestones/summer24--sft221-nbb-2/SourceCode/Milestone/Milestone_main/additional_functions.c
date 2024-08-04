#include "additional_functions.h"
#include <float.h>

int isValidPoint(struct Point* point) {
	int result = 0;
	if (point == NULL) {
		result = 0; // Handle null pointer
	}
	else if (point->row >= 0 && point->row < MAP_ROWS && point->col >= 0 && point->col < MAP_COLS) {
		result = 1;
	}

	return result;
}
int isValidDestination(const struct Map* map, const struct Point* destination) {
	// Check if the map is not NULL
	if (map == NULL) {
		return 0;  // Invalid map
	}

	// Check if destination is within map bounds
	if (destination->row < 0 || destination->row >= MAP_ROWS ||
		destination->col < 0 || destination->col >= MAP_COLS) {
		return 0;  // Out of bounds
	}

	// Check if the destination is valid (not a building)
	if (map->squares[destination->row][destination->col] == 1) {
		return 0;  // Invalid destination (building present)
	}

	return 1;  // Valid destination
}
int calculateAvailableSpace(const struct Truck* truck, const struct Package* package) {
	int result = 0;
	double availWeight = TRUCK_MAX_WEIGHT - truck->currentWeight;
	int availVolume = TRUCK_MAX_VOLUME - truck->currentVolume;

	if (availWeight <= 0) {
		printf("The truck has reached weight capacity!\n");
	}
	else if (availVolume <= 0) {
		printf("The truck has reached volume capacity!\n");
	}
	else {
		printf("There is %d units of volume available.\n", availVolume);
		printf("There is %f kg available.\n", availWeight);
		if (package->volume <= availVolume && package->weight <= availWeight) {
			result = 1;
		}
	}
	return result;
}
int findTruckForShipment(const struct Map* map, const struct Truck trucks[], const int numTrucks, const struct Package* package) {
	// Check if the map is invalid or empty, or if Trucks array is empty, or package has valid destination
	if (map == NULL || map->numRows <= 0 || map->numCols <= 0 || trucks == NULL || !isValidDestination(map, package->destination)) {
		return -1;
	}


	int bestTruckIndex = -1;
	double shortestDistance = DBL_MAX;

	for (int i = 0; i < numTrucks; ++i) {
		const struct Truck* truck = &trucks[i];
		// Check if the truck can accommodate the weight and volume of the package
		if (calculateAvailableSpace(truck, package) == 1) {
			// Calculate the distance from the truck's current position to the package's destination
			double dist = distance(truck->currentPosition, package->destination);

			// If this truck is closer than the previously found best truck, select this truck
			if (dist < shortestDistance) {
				shortestDistance = dist;
				bestTruckIndex = i;
			}
		}
	}
	return bestTruckIndex;
}







