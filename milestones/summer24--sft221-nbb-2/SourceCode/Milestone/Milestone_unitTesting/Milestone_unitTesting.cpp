#include "pch.h"
#include "CppUnitTest.h"
#include "Milestone_unitTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MilestoneunitTesting
{
	TEST_CLASS(isValidDestinationTesting)
	{
	public:

		TEST_METHOD(FDV01)
		{
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 1,3 };
			d = isValidDestination(&map, p1);
			Assert::AreEqual(1, d, 0.01);

		}
		TEST_METHOD(FDV02)
		{
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 2,2 };
			d = isValidDestination(&map, p1);
			Assert::AreEqual(0, d, 0.01);

		}
		TEST_METHOD(FDV03)
		{
			int d;
			struct Map map = populateMap();
			struct Point p1 = { -2,5 };
			d = isValidDestination(&map, p1);
			Assert::AreEqual(0, d, 0.01);

		}
		TEST_METHOD(FDV04)
		{
			int d;
			struct Point p1 = { 2,2 };
			d = isValidDestination(NULL, p1);
			Assert::AreEqual(0, d, 0.01);
		};

	};
	TEST_CLASS(availableSpaceTesting)
	{
	public:

		TEST_METHOD(FS001)
		{
			int d;
			struct Truck truck = { nullptr, 500, 50, 'B', {}, 0 };
			struct Package package = { nullptr, 500, 2 };
			d = calculateAvailableSpace(truck, package);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(FS002)
		{
			int d;
			struct Truck truck = { nullptr, 2400, 20, 'B', {}, 0 };
			struct Package package = { nullptr, 332, 29 };
			d = calculateAvailableSpace(truck, package);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(FS003)
		{
			int d;
			struct Truck truck = { nullptr, 2000, 89, 'B', {}, 0 };
			struct Package package = { nullptr, 332, 29 };
			d = calculateAvailableSpace(truck, package);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(FS004)
		{
			int d;
			struct Truck truck = { nullptr, 0, 0, 'B', {}, 0 };
			struct Package package = { nullptr, 2500, 100 };
			d = calculateAvailableSpace(truck, package);
			Assert::AreEqual(1, d, 0.01);
		};
	};
	TEST_CLASS(validPointsTesting)
	{
	public:

		TEST_METHOD(FP001)
		{
			int d;
			struct Point p1 = { 12,5 };
			d = isValidPoint(&p1);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(FP002)
		{
			int d;
			struct Point p1 = { -2,5 };
			d = isValidPoint(&p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(FP003)
		{
			int d;
			d = isValidPoint(nullptr);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(FP004)
		{
			int d;
			struct Point p1 = { 24,24 };
			d = isValidPoint(&p1);
			Assert::AreEqual(1, d, 0.01);
		};
	};
	TEST_CLASS(DistanceTesting)
	{
	public:

		TEST_METHOD(FD001)
		{
			double d;
			struct Point p1 = { 1,1 };
			struct Point p2 = { 4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(4.24264, d, 0.01);

		}
		TEST_METHOD(FD002)
		{
			double d;
			struct Point p1 = { -2,-16 };
			struct Point p2 = { 12,-54 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(FD003)
		{
			double d;
			struct Point p1 = { 1000,1000 };
			struct Point p2 = { 2000,2000 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(FD004)
		{
			double d;
			struct Point p1 = { 2,2 };
			struct Point p2 = { 2,2 };
			d = distance(&p1, &p2);
			Assert::AreEqual(0, d, 0.01);

		}
	};
	TEST_CLASS(findTruckForShipmentTesting)
	{
	public:



		TEST_METHOD(FT001)
		{
			int result;
			struct Map map = populateMap(); // Assuming this function populates a valid map
			struct Point truckPosition = { 1, 1 };
			struct Truck trucks[1] = { { &truckPosition, 500, 50, 'B', nullptr, 0 } }; // Single truck that can handle the package
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 100, 10 }; // Package within the capacity of the truck
			int numTrucks = 1;

			result = findTruckForShipment(map, trucks, numTrucks, package);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(FT002)
		{
			int result;
			struct Map map = populateMap(); // Assuming this function populates a valid map
			struct Point truckPositions[3] = { { 1, 1 }, { 2, 2 }, { 4, 4 } };
			struct Truck trucks[3] = {
				{ &truckPositions[0], 500, 50, 'B', nullptr, 0 }, // First truck cannot handle the package
				{ &truckPositions[1], 300, 30, 'B', nullptr, 0 }, // Second truck can handle the package
				{ &truckPositions[2], 700, 70, 'B', nullptr, 0 }  // Third truck can handle the package but is farther
			};
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 100, 10 }; // Package fits into the second truck
			int numTrucks = 3;

			result = findTruckForShipment(map, trucks, numTrucks, package);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(FT003)
		{
			int result;
			struct Map map = populateMap(); // Assuming this function populates a valid map
			struct Point truckPositions[2] = { { 1, 1 }, { 2, 2 } };
			struct Truck trucks[2] = {
				{ &truckPositions[0], 2000, 50, 'B', nullptr, 0 }, // First truck cannot handle the package
				{ &truckPositions[1], 2000, 30, 'B', nullptr, 0 }  // Second truck cannot handle the package
			};
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 600, 60 }; // Package too large or heavy for all trucks
			int numTrucks = 2;

			result = findTruckForShipment(map, trucks, numTrucks, package);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(FT004)
		{
			int result;
			struct Map invalidMap = { NULL }; // Assuming this is an invalid map
			struct Point truckPositions[2] = { { 1, 1 }, { 2, 2 } };
			struct Truck trucks[2] = {
				{ &truckPositions[0], 500, 50, 'B', nullptr, 0 }, // Valid truck
				{ &truckPositions[1], 300, 30, 'B', nullptr, 0 }  // Valid truck
			};
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 100, 10 }; // Any valid package
			int numTrucks = 2;

			result = findTruckForShipment(invalidMap, trucks, numTrucks, package);
			Assert::AreEqual(-1, result); // or check for an error message
		}
	};

	TEST_CLASS(shortestPathTesting)
	{
	public:

		TEST_METHOD(FP001)
		{
			int test;
			struct Route returnedRoute;
			struct Route correctRoute;
			struct Map map = populateMap();
			struct Point start = { 0,0 };
			struct Point dest = { 0,4 };
			returnedRoute = shortestPath(&map, start, dest);
			correctRoute = {
	{
		{0, 0}, // Point 1: (0, 0)
		{0, 1}, // Point 2: (1, 1)
		{0, 2}, // Point 3: (2, 2)
		{0, 3}, // Point 4: (3, 3)
		{0, 4}  // Point 5: (4, 4)
	},
	5, // Number of points
	'R'  // Route symbol
			};;
			test = areRoutesEqual(returnedRoute, correctRoute);
			Assert::AreEqual(1 , test);

		}
		TEST_METHOD(FP002)
		{
			double d;
			struct Point p1 = { -2,-16 };
			struct Point p2 = { 12,-54 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(FP003)
		{
			double d;
			struct Point p1 = { 1000,1000 };
			struct Point p2 = { 2000,2000 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(FP004)
		{
			double d;
			struct Point p1 = { 2,2 };
			struct Point p2 = { 2,2 };
			d = distance(&p1, &p2);
			Assert::AreEqual(0, d, 0.01);

		}
	};
}