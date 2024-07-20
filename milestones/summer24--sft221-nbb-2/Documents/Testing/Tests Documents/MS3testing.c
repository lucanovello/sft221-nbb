#include <assert.h>
#include <stdio.h>
#include "mapping.h"
#include "additional_functions.h"

// Mock data for testing
struct Point truckRoute[] = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
struct Point destination = { 3, 3 };

// Map with an obstacle (1 represents a building)
struct Map map = {
    .grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    }
};

struct Point path[25]; // Array to store the path

void test_findShortestPath() {
    int pathLength = findShortestPath(map, truckRoute, 4, destination, path);
    assert(pathLength > 0);  // Ensure a path is found

    // Print the path for verification
    printf("Path length: %d\n", pathLength);
    for (int i = 0; i < pathLength; ++i) {
        printf("(%d, %d) -> ", path[i].x, path[i].y);
    }
    printf("Destination\n");
}

int main() {
    test_findShortestPath();
    printf("Test passed.\n");
    return 0;
}
