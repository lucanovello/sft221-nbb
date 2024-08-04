#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	printMap(&routeMap, 1, 1);

	// debug code
	struct Map map = populateMap();
	struct Point destPoint = { MAP_ROWS + 1, MAP_COLS + 1 };
	struct Point p1 = { 0, 0 };
	struct Point p2 = { 20, 20 };
	struct Route route = { { &destPoint }, 1, "B"};
	struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
	struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
	struct Truck trucks[] = { tr1, tr2 };
	struct Package package = { &destPoint, 1.0, 1.0 };
	printf("\n============================================================================================\n");
	printf("package row: %d\n", package.destination->row);
	printf("package row: %d\n", package.destination->col);
	printf("\n============================================================================================\n");

	return 0;
}