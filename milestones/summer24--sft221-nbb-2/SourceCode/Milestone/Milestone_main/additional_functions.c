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

int isValidDestination(const struct Map map, const struct Point destination) {
	int result;
	if (map.squares[destination.row][destination.col] == 1) {
		printf("Invalid destination!\n");
		result = 0;
	}else{
		result = 1;
	}
	return result;	
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
