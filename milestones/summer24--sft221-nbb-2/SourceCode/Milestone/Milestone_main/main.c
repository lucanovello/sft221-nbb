#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	printMap(&routeMap, 1, 1);

	// test code for distance()
	// test 1
	int result;

	struct Point t1p1 = {1, 1};
	struct Point t1p2 = {4, 4};

	result = distance(&t1p1, &t1p2);

	printf("The result after test 1 is %d\n", result);

	// test 2
	struct Point t2p1 = {-2, -16};
	struct Point t2p2 = {12, -5};

	result = distance(&t2p1, &t2p2);

	printf("The result after test 2 is %d\n", result);

	// test 3
	struct Point t3p1 = {1000, 1000};
	struct Point t3p2 = {2000, 2000};

	result = distance(&t3p1, &t3p2);

	printf("The result after test 3 is %d\n", result);

	// test 4
	struct Point t4p1 = {2, 2};
	struct Point t4p2 = {2, 2};

	result = distance(&t4p1, &t4p2);

	printf("The result after test 4 is %d\n", result);

	return 0;
}