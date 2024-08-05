#include "pch.h"
#include "CppUnitTest.h"
#include "Milestone_unitTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MilestoneUnitTesting
{
	TEST_CLASS(isValidDestinationTesting)
	{
	public:
		// BLACK BOX TESTING
		TEST_METHOD(BB_IVD001)
		{
			Logger::WriteMessage("Valid Inputs test with no building in point");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 1,3 };
			d = isValidDestination(&map, &p1);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(BB_IVD002)
		{
			Logger::WriteMessage("Valid Inputs test with building in point");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 2,2 };
			d = isValidDestination(&map, &p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(BB_IVD003)
		{
			Logger::WriteMessage("Negative inputs test");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { -2,5 };
			d = isValidDestination(&map, &p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(BB_IVD004)
		{
			Logger::WriteMessage("NULL map test");
			int d;
			struct Point p1 = { 2,2 };
			d = isValidDestination(NULL, &p1);
			Assert::AreEqual(0, d, 0.01);
		};
		// WHITE BOX TESTING
		TEST_METHOD(WB_IVD001)
		{
			Logger::WriteMessage("Valid Inputs test with building in point");
			int d = 1;
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			d = isValidDestination(&map, &p1);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(WB_IVD002)
		{
			Logger::WriteMessage("valid map with dest row out of bounds");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { MAP_ROWS + 1, 1 };
			d = isValidDestination(&map, &p1);
			Assert::AreEqual(0, d, 0.01);

		}
		TEST_METHOD(WB_IVD003)
		{
			Logger::WriteMessage("valid map with dest col out of bounds");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 1, MAP_COLS + 1 };
			d = isValidDestination(&map, &p1);
			Assert::AreEqual(0, d, 0.01);

		}
		TEST_METHOD(WB_IVD004)
		{
			Logger::WriteMessage("Pass NULL as map");
			int d = 1;
			struct Point p1 = { 1, 1 };
			d = isValidDestination(NULL, &p1);
			Assert::AreEqual(0, d, 0.01);
		}
	};
	TEST_CLASS(calculateAvailableSpaceTesting)
	{
	public:
		// BLACK BOX TESTING
		TEST_METHOD(BB_CAS001)
		{
			Logger::WriteMessage("Truck has space for this package");
			int d;
			struct Truck truck = { nullptr, 500, 50, 'B', {}, 0 };
			struct Package package = { nullptr, 500, 2 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(BB_CAS002)
		{
			Logger::WriteMessage("Package Exceeds Weight Limit");
			int d;
			struct Truck truck = { nullptr, 2400, 20, 'B', {}, 0 };
			struct Package package = { nullptr, 332, 29 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(BB_CAS003)
		{
			Logger::WriteMessage("Package Exceeds Volume Limit");
			int d;
			struct Truck truck = { nullptr, 2000, 89, 'B', {}, 0 };
			struct Package package = { nullptr, 332, 29 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(BB_CAS004)
		{
			Logger::WriteMessage("Package Exactly fits limits Limit");
			int d;
			struct Truck truck = { nullptr, 0, 0, 'B', {}, 0 };
			struct Package package = { nullptr, 2500, 100 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, d, 0.01);
		};
		// WHITE BOX TESTING
		TEST_METHOD(WB_CAS001)
		{
			Logger::WriteMessage("valid truck, weight");
			int d;
			struct Truck truck = { nullptr, 500, 50, 'B', {}, 0 };
			struct Package package = { nullptr, 500, 2 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(WB_CAS002)
		{
			Logger::WriteMessage("Package Exceeds TRUCK_MAX_WEIGHT");
			int d;
			struct Truck truck = { nullptr, 2400, 20, 'B', {}, 0 };
			struct Package package = { nullptr, 332, 29 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(WB_CAS003)
		{
			Logger::WriteMessage("Package Exceeds TRUCK_MAX_VOLUME");
			int d;
			struct Truck truck = { nullptr, 2000, 89, 'B', {}, 0 };
			struct Package package = { nullptr, 332, 29 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(WB_CAS004)
		{
			Logger::WriteMessage("Package Exactly fits limits");
			int d;
			struct Truck truck = { nullptr, 0, 0, 'B', {}, 0 };
			struct Package package = { nullptr, 2500, 100 };
			d = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, d, 0.01);
		};
	};
	TEST_CLASS(isValidPointTesting)
	{
	public:
		// BLACK BOX TESTING
		TEST_METHOD(BB_IVP001)
		{
			Logger::WriteMessage("Valid Point Test");
			int d;
			struct Point p1 = { 12,5 };
			d = isValidPoint(&p1);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(BB_IVP002)
		{
			Logger::WriteMessage("Invalid Points test");
			int d;
			struct Point p1 = { -2,5 };
			d = isValidPoint(&p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(BB_IVP003)
		{
			Logger::WriteMessage("Empty point test");
			int d;
			struct Point p1;
			d = isValidPoint(&p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(BB_IVP004)
		{
			Logger::WriteMessage("Max Value test");
			int d;
			struct Point p1 = { 24,24 };
			d = isValidPoint(&p1);
			Assert::AreEqual(1, d, 0.01);
		};
		// WHITE BOX TESTING
		TEST_METHOD(WB_IVP001)
		{
			Logger::WriteMessage("Pass valid Point");
			int d;
			struct Point p1 = { 1, 1 };
			d = isValidPoint(&p1);
			Assert::AreEqual(1, d, 0.01);
		}
		TEST_METHOD(WB_IVP002)
		{
			Logger::WriteMessage("Pass Null Point");
			int d;
			struct Point p1;
			d = isValidPoint(&p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(WB_IVP003)
		{
			Logger::WriteMessage("Pass Point with row higher than limit");
			int d;
			struct Point p1 = { MAP_ROWS + 1, 1 };
			d = isValidPoint(&p1);
			Assert::AreEqual(0, d, 0.01);
		}
		TEST_METHOD(WB_IVP004)
		{
			Logger::WriteMessage("Pass Point with col higher than limit");
			int d;
			struct Point p1 = { 1, MAP_COLS + 1 };
			d = isValidPoint(&p1);
			Assert::AreEqual(0, d, 0.01);
		}
	};
	TEST_CLASS(distanceTesting)
	{
	public:
		// BLACK BOX TESTING
		TEST_METHOD(BB_DST001)
		{
			Logger::WriteMessage("positive inputs test");
			double d;
			struct Point p1 = { 1,1 };
			struct Point p2 = { 4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(4.24264, d, 0.01);

		}
		TEST_METHOD(BB_DST002)
		{
			Logger::WriteMessage("negative inputs test");
			double d;
			struct Point p1 = { -2,-16 };
			struct Point p2 = { 12,-54 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(BB_DST003)
		{
			Logger::WriteMessage("large values test");
			double d;
			struct Point p1 = { 1000,1000 };
			struct Point p2 = { 2000,2000 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(BB_DST004)
		{
			Logger::WriteMessage("same point test");
			double d;
			struct Point p1 = { 2,2 };
			struct Point p2 = { 2,2 };
			d = distance(&p1, &p2);
			Assert::AreEqual(0, d, 0.01);
		}
		// WHITE BOX TESTING
		TEST_METHOD(WB_DST001)
		{
			Logger::WriteMessage("valid p1 and p2");
			double d;
			struct Point p1 = { 1,1 };
			struct Point p2 = { 4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(4.24264, d, 0.01);
		}
		TEST_METHOD(WB_DST002)
		{
			Logger::WriteMessage("p1 row higher than MAP_ROWS");
			double d;
			struct Point p1 = { -1,1 };
			struct Point p2 = { 4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);
		}
		TEST_METHOD(WB_DST003)
		{
			Logger::WriteMessage("p1 col higher than MAP_COLS");
			double d;
			struct Point p1 = { 1,-1 };
			struct Point p2 = { 4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);
		}
		TEST_METHOD(WB_DST004)
		{
			Logger::WriteMessage("p2 row higher than MAP_ROWS");
			double d;
			struct Point p1 = { 1,1 };
			struct Point p2 = { -4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);
		}
		TEST_METHOD(WB_DST005)
		{
			Logger::WriteMessage("p2 col higher than MAP_COLS");
			double d;
			struct Point p1 = { 1,1 };
			struct Point p2 = { 4,-4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);
		}
	};
	TEST_CLASS(findTruckForShipmentTesting)
	{
	public:
		// BLACK BOX TESTING
		TEST_METHOD(BB_FTFS001)
		{
			Logger::WriteMessage("Valid inputs test");
			int result;
			struct Map map = populateMap(); // Assuming this function populates a valid map
			struct Point truckPosition = { 1, 1 };
			struct Truck trucks[1] = { { &truckPosition, 500, 50, 'B', nullptr, 0 } }; // Single truck that can handle the package
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 100, 10 }; // Package within the capacity of the truck
			int numTrucks = 1;

			result = findTruckForShipment(&map, trucks, numTrucks, &package);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(BB_FTFS002)
		{
			Logger::WriteMessage("Valid inputs test with multiple trucks");
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

			result = findTruckForShipment(&map, trucks, numTrucks, &package);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(BB_FTFS003)
		{
			Logger::WriteMessage("No Suitable Truck");
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

			result = findTruckForShipment(&map, trucks, numTrucks, &package);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(BB_FTFS004)
		{
			Logger::WriteMessage("Invalid Input");
			int result;
			struct Point truckPositions[2] = { { 1, 1 }, { 2, 2 } };
			struct Truck trucks[2] = {
				{ &truckPositions[0], 500, 50, 'B', nullptr, 0 }, // Valid truck
				{ &truckPositions[1], 300, 30, 'B', nullptr, 0 }  // Valid truck
			};
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 100, 10 }; // Any valid package
			int numTrucks = 2;

			result = findTruckForShipment(NULL, trucks, numTrucks, &package);
			Assert::AreEqual(-1, result); // or check for an error message
		}
		// WHITE BOX TESTING
		TEST_METHOD(WB_FTFS001)
		{
			Logger::WriteMessage("Valid inputs test with 3 trucks");
			int result;
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 10, 10 };
			struct Point p3 = { 20, 20 };
			struct Route exp1 = { p1 };
			struct Route exp2 = { p2 };
			struct Route exp3 = { p3 };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &exp1, 2 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &exp2, 2 };
			struct Truck tr3 = { &p3, 0.0, 0.0, 'B', &exp3, 2 };
			struct Truck trucks[] = { tr1, tr2, tr3 };
			struct Package package = { &p1, 1.0, 1.0 };
			result = findTruckForShipment(&map, trucks, 3, &package);
			Assert::AreEqual(0, result, 0.01);

		}
		TEST_METHOD(WB_FTFS002)
		{
			Logger::WriteMessage("Valid inputs test with 2 trucks");
			int result = 0;
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 10, 10 };
			struct Route exp1 = { p1, 1, 'B' };
			struct Route exp2 = { p2, 1, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &exp1, 2 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &exp2, 2 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &p2, 1.0, 1.0 };
			result = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(1, result, 0.01);
		}
		TEST_METHOD(WB_FTFS003)
		{
			Logger::WriteMessage("No Suitable Truck");
			int result = 0;
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Point p2 = { MAP_ROWS / 2, MAP_COLS / 2 };
			struct Route exp1 = { p1 };
			struct Route exp2 = { p2 };
			struct Truck tr1 = { &p1, TRUCK_MAX_WEIGHT, 0.0, 'B', &exp1, 2 };
			struct Truck tr2 = { &p2, 0.0, TRUCK_MAX_VOLUME, 'B', &exp2, 2 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &p2, 1.0, 1.0 };
			result = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(-1, result, 0.01);
		}
		TEST_METHOD(WB_FTFS004)
		{
			Logger::WriteMessage("No Trucks in Trucks array");
			int result = 0;
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Package package = { &p1, 1.0, 1.0 };
			result = findTruckForShipment(&map, NULL, 3, &package);
			Assert::AreEqual(-1, result, 0.01);
		}
	};
	TEST_CLASS(shortestPathTesting)
	{
	public:
		// BLACK BOX TESTING
		TEST_METHOD(BB_SHP001)
		{
			Logger::WriteMessage("Valid test");
			int test = 1;
			struct Route returnedRoute;
			struct Route correctRoute;
			struct Map map = populateMap();
			struct Point start = { 0,0 };
			struct Point dest = { 0,4 };
			returnedRoute = shortestPath(&map, start, dest);
			correctRoute = {
			{
			{0, 1},
			{0, 2},
			{0, 3}
				},
				3, // Number of points
				DIVERSION  // Route symbol
			};

			// Check if the route symbols are the same
			if (returnedRoute.routeSymbol != correctRoute.routeSymbol) {
				test = 0;
			}
			// Check if each corresponding point is the same
			for (int i = 0; i < returnedRoute.numPoints; ++i) {
				if (!eqPt(returnedRoute.points[i], correctRoute.points[i])) {
					test = 0;
				}
			}
			Assert::AreEqual(3, returnedRoute.numPoints);
			Assert::AreEqual(1, test);
		}
		TEST_METHOD(BB_SHP002)
		{
			Logger::WriteMessage("invalid points test");
			int test = 1;
			struct Route returnedRoute;
			struct Route correctRoute;
			struct Map map = populateMap();
			struct Point start = { 3,28 };
			struct Point dest = { 5, 29 };
			returnedRoute = shortestPath(&map, start, dest);
			correctRoute = {
			{{}},
				0, // Number of points
				DIVERSION  // Route symbol
			};

			// Check if the route symbols are the same
			if (returnedRoute.routeSymbol != correctRoute.routeSymbol) {
				test = 0;
			}
			// Check if each corresponding point is the same
			for (int i = 0; i < returnedRoute.numPoints; ++i) {
				if (!eqPt(returnedRoute.points[i], correctRoute.points[i])) {
					test = 0;
				}
			}
			Assert::AreEqual(0, returnedRoute.numPoints);
			Assert::AreEqual(1, test);
		}
		TEST_METHOD(BB_SHP003)
		{
			Logger::WriteMessage("Start and Dest are equal test");
			int test = 1;
			struct Route returnedRoute;
			struct Route correctRoute;
			struct Map map = populateMap();
			struct Point start = { 13,4 };
			struct Point dest = { 13, 4 };
			returnedRoute = shortestPath(&map, start, dest);
			correctRoute = {
			{{}},
				0, // Number of points
				DIVERSION  // Route symbol
			};

			// Check if the route symbols are the same
			if (returnedRoute.routeSymbol != correctRoute.routeSymbol) {
				test = 0;
			}
			// Check if each corresponding point is the same
			for (int i = 0; i < returnedRoute.numPoints; ++i) {
				if (!eqPt(returnedRoute.points[i], correctRoute.points[i])) {
					test = 0;
				}
			}
			Assert::AreEqual(0, returnedRoute.numPoints);
			Assert::AreEqual(1, test);
		}
		TEST_METHOD(BB_SHP004)
		{
			Logger::WriteMessage("Negative points test");
			int test = 1;
			struct Route returnedRoute;
			struct Route correctRoute;
			struct Map map = populateMap();
			struct Point start = { -1,-1 };
			struct Point dest = { -4, -4 };
			returnedRoute = shortestPath(&map, start, dest);
			correctRoute = {
			{{}},
				0, // Number of points
				DIVERSION  // Route symbol
			};

			// Check if the route symbols are the same
			if (returnedRoute.routeSymbol != correctRoute.routeSymbol) {
				test = 0;
			}
			// Check if each corresponding point is the same
			for (int i = 0; i < returnedRoute.numPoints; ++i) {
				if (!eqPt(returnedRoute.points[i], correctRoute.points[i])) {
					test = 0;
				}
			}
			Assert::AreEqual(0, returnedRoute.numPoints);
			Assert::AreEqual(1, test);
		}
		// WHITE BOX TESTING
		TEST_METHOD(WB_SHP001)
		{
			Logger::WriteMessage("Valid test");
			struct Route expected = { { { 0, 1}, { 0, 2 }, { 1, 3 }, { 2, 3 }, { 3, 4 }, { 4, 4 } }, 5, 16 };
			struct Route results = {};
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 4, 4 };
			results = shortestPath(&map, p1, p2);
			Assert::AreEqual(expected.routeSymbol, results.routeSymbol);
			Assert::AreEqual(expected.numPoints, results.numPoints);
			for (int i = 0; i < results.numPoints; i++)
			{
				Assert::AreEqual(expected.points[i].row, results.points[i].row);
				Assert::AreEqual(expected.points[i].col, results.points[i].col);
			}
		}
		TEST_METHOD(WB_SHP002)
		{
			Logger::WriteMessage("Start and Dest are equal");
			struct Route expected = { {0,0}, 0, DIVERSION };
			struct Route results = {};
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 0, 0 };
			results = shortestPath(&map, p1, p2);
			Assert::AreEqual(expected.routeSymbol, results.routeSymbol);
			Assert::AreEqual(expected.numPoints, results.numPoints);
			for (int i = 0; i < results.numPoints; i++)
			{
				Assert::AreEqual(expected.points[i].row, results.points[i].row);
				Assert::AreEqual(expected.points[i].col, results.points[i].col);
			}
		}
		TEST_METHOD(WB_SHP003)
		{
			Logger::WriteMessage("Point start invalid");
			struct Route expected = { {0,0}, 0, DIVERSION };
			struct Route results = {};
			struct Map map = populateMap();
			struct Point p1 = { -1, 0 };
			struct Point p2 = { 4, 4 };
			results = shortestPath(&map, p1, p2);
			Assert::AreEqual(expected.routeSymbol, results.routeSymbol);
			Assert::AreEqual(expected.numPoints, results.numPoints);
			for (int i = 0; i < results.numPoints; i++)
			{
				Assert::AreEqual(expected.points[i].row, results.points[i].row);
				Assert::AreEqual(expected.points[i].col, results.points[i].col);
			}
		}
		TEST_METHOD(WB_SHP004)
		{
			Logger::WriteMessage("Point dest invalid");
			struct Route expected = { {0,0}, 0, DIVERSION };
			struct Route results = {};
			struct Map map = populateMap();
			struct Point p1 = { 0, 0 };
			struct Point p2 = { -4, 4 };
			results = shortestPath(&map, p1, p2);
			Assert::AreEqual(expected.routeSymbol, results.routeSymbol);
			Assert::AreEqual(expected.numPoints, results.numPoints);
			for (int i = 0; i < results.numPoints; i++)
			{
				Assert::AreEqual(expected.points[i].row, results.points[i].row);
				Assert::AreEqual(expected.points[i].col, results.points[i].col);
			}
		}


	};
}

namespace MilestoneIntegrationTesting
{
	TEST_CLASS(isValidPointIntegrationTesting)
	{
	public:
		TEST_METHOD(INT_IVP001)
		{
			Logger::WriteMessage("Use valid Point in isValidPoint() and in isValidDestination()");
			int ivpResults;
			int ivdResults;
			struct Point p1 = { 0, 0 };
			struct Map map = populateMap();
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivpResults, 0.01);
			ivdResults = isValidDestination(&map, &p1);
			Assert::AreEqual(1, ivdResults, 0.01);
		}
		TEST_METHOD(INT_IVP002)
		{
			Logger::WriteMessage("Use invalid Point in isValidPoint() and in isValidDestination()");
			int ivpResults;
			int ivdResults;
			struct Point p1 = { MAP_ROWS + 1, MAP_COLS + 1 };
			struct Map map = populateMap();
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(0, ivpResults, 0.01);
			ivdResults = isValidDestination(&map, &p1);
			Assert::AreEqual(0, ivdResults, 0.01);
		}
		TEST_METHOD(INT_IVP003)
		{
			Logger::WriteMessage("Use valid Point in isValidPoint() to validate Package argument in calculateAvailableSpace()");
			int ivpResults;
			int casResults;
			struct Point p1 = { 0, 0 };
			struct Point p2 = { MAP_ROWS, MAP_COLS };
			struct Point destPoint = { 0, 0 };
			struct Map map = populateMap();
			struct Route route = { NULL, 0, 'B'};
			struct Truck truck = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivpResults, 0.01);
			casResults = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, casResults, 0.01);
		}
		TEST_METHOD(INT_IVP004)
		{
			Logger::WriteMessage("Use valid Point in isValidPoint() to validate Package argument in findTruckForShipment()");
			int ivpResult;
			int ftsResult;
			struct Map map = populateMap();
			struct Point destPoint = { 0, 0 };
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResult = isValidPoint(&destPoint);
			Assert::AreEqual(1, ivpResult, 0.01);
			ftsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, ftsResult, 0.01);
		}
	};
	TEST_CLASS(isValidDestinationIntegrationTesting)
	{
	public:
		TEST_METHOD(INT_IVD001)
		{
			Logger::WriteMessage("Use valid Point in isValidDestination() and in isValidPoint()");
			int ivpResults;
			int ivdResults;
			struct Point p1 = { 4, 4 };
			struct Map map = populateMap();
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivpResults, 0.01);
			ivdResults = isValidDestination(&map, &p1);
			Assert::AreEqual(1, ivdResults, 0.01);
		}
		TEST_METHOD(INT_IVD002)
		{
			Logger::WriteMessage("Use invalid Point in isValidDestination() and in isValidPoint()");
			int ivpResults;
			int ivdResults;
			struct Point p1 = { MAP_ROWS * 2, MAP_COLS * 2 };
			struct Map map = populateMap();
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(0, ivpResults, 0.01);
			ivdResults = isValidDestination(&map, &p1);
			Assert::AreEqual(0, ivdResults, 0.01);
		}
		TEST_METHOD(INT_IVD003)
		{
			Logger::WriteMessage("Use valid Point in isValidDestination() to validate Package argument in calculateAvailableSpace()");
			int ivdResults;
			int casResults;
			struct Point p1 = { 0, 0 };
			struct Point destPoint = { 0, 0 };
			struct Route route = { NULL, 0, 'B' };
			struct Truck truck = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivdResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivdResults, 0.01);
			casResults = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, casResults, 0.01);
		}
		TEST_METHOD(INT_IVD004)
		{
			Logger::WriteMessage("Use valid Point in isValidDestination() to validate Package argument in findTruckForShipment()");
			int ivpResult;
			int ftfsResult;
			struct Map map = populateMap();
			struct Point destPoint = { 0, 0 };
			struct Point p1 = { 4, 4 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResult = isValidDestination(&map, &destPoint);
			Assert::AreEqual(1, ivpResult, 0.01);
			ftfsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, ftfsResult, 0.01);
		}
	};
	TEST_CLASS(calculateAvailableSpaceIntegrationTesting)
	{
	public:
		TEST_METHOD(INT_CAS001)
		{
			Logger::WriteMessage("Use valid Point p in isValidPoint() and pass p to valid Package for calculateAvailableSpace()");
			int ivpResults;
			int casResults;
			struct Point p1 = { 0, 0 };
			struct Point destPoint = { 0, 0 };
			struct Route route = { NULL, 0, 'B' };
			struct Truck truck = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivpResults, 0.01);
			casResults = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, casResults, 0.01);
		}
		TEST_METHOD(INT_CAS002)
		{
			Logger::WriteMessage("Use invalid Point p in isValidPoint() and pass p to valid Package for calculateAvailableSpace()");
			int ivpResults;
			int casResults;
			struct Point p1 = { 0, 0 };
			struct Point destPoint = { MAP_ROWS+1, MAP_COLS+1 };
			struct Route route = { NULL, 0, 'B' };
			struct Truck truck = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivpResults, 0.01);
			casResults = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, casResults, 0.01);
		}
		TEST_METHOD(INT_CAS003)
		{
			Logger::WriteMessage("Use valid Point p in isValidDestination() and pass p to valid Package for calculateAvailableSpace()");
			int ivdResults;
			int casResults;
			struct Point p1 = { 0, 0 };
			struct Point destPoint = { 0, 0 };
			struct Route route = { NULL, 0, 'B' };
			struct Truck truck = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivdResults = isValidPoint(&p1);
			Assert::AreEqual(1, ivdResults, 0.01);
			casResults = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, casResults, 0.01);
		}
		TEST_METHOD(INT_CAS004)
		{
			Logger::WriteMessage("create and pass valid Truck, Package to calculateAvailableSpace() and then to findTruckForShipment()");
			int ftfsResult;
			int casResult;
			struct Map map = populateMap();
			struct Point destPoint = { 4, 4 };
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			casResult = calculateAvailableSpace(&tr1, &package);
			Assert::AreEqual(1, casResult, 0.01);
			ftfsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, ftfsResult, 0.01);
		};
	};
	TEST_CLASS(findTruckForShipmentIntegrationTesting)
	{
	public:
		TEST_METHOD(INT_FTFS001)
		{
			Logger::WriteMessage("Use valid Point in isValidPoint() to validate Package argument in findTruckForShipment()");
			int ftfsResult;
			int ivpResult;
			struct Map map = populateMap();
			struct Point destPoint = { 0, 0 };
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResult = isValidPoint(&destPoint);
			Assert::AreEqual(1, ivpResult, 0.01);
			ftfsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, ftfsResult, 0.01);
		}
		TEST_METHOD(INT_FTFS002)
		{
			Logger::WriteMessage("Use invalid Point in isValidPoint() to invalidate Package argument in findTruckForShipment()");
			int ftfsResult;
			int ivpResult;
			struct Map map = populateMap();
			struct Point destPoint = { MAP_ROWS + 1, MAP_COLS + 1 };
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResult = isValidPoint(&destPoint);
			Assert::AreEqual(0, ivpResult, 0.01);
			ftfsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(-1, ftfsResult, 0.01);
		}
		TEST_METHOD(INT_FTFS003)
		{
			Logger::WriteMessage("Use valid Point in isValidDestination() to validate Package argument in findTruckForShipment()");
			int ftfsResult;
			int ivpResult;
			struct Map map = populateMap();
			struct Point destPoint = { 0, 0 };
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			ivpResult = isValidDestination(&map, &destPoint);
			Assert::AreEqual(1, ivpResult, 0.01);
			ftfsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, ftfsResult, 0.01);
		}
		TEST_METHOD(INT_FTFS004)
		{
			Logger::WriteMessage("Use valid Point in new valid Package package and pass to calculateAvailableSpace() and findTruckForShipment()");
			int ftfsResult;
			int casResult;
			struct Map map = populateMap();
			struct Point destPoint = { 0, 0 };
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 20, 20 };
			struct Route route = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, 'B' };
			struct Truck tr1 = { &p1, 0.0, 0.0, 'B', &route, 0 };
			struct Truck tr2 = { &p2, 0.0, 0.0, 'B', &route, 0 };
			struct Truck trucks[] = { tr1, tr2 };
			struct Package package = { &destPoint, 1.0, 1.0 };
			casResult = calculateAvailableSpace(&tr1, &package);
			Assert::AreEqual(1, casResult, 0.01);
			ftfsResult = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, ftfsResult, 0.01);
		}
	};



}

namespace MilestoneAcceptanceTests
{
	TEST_CLASS(AcceptanceTests)
	{
	public:

		// Acceptance test for the isValidDestination function
		TEST_METHOD(ACC_IVD001)
		{
			Logger::WriteMessage("Acceptance Test: isValidDestination with valid point");
			struct Map map = populateMap();
			struct Point p1 = { 1, 3 };
			int result = isValidDestination(&map, &p1);
			Assert::AreEqual(1, result, L"Expected point to be a valid destination.");
		}

		// Acceptance test for the calculateAvailableSpace function
		TEST_METHOD(ACC_CAS001)
		{
			Logger::WriteMessage("Acceptance Test: calculateAvailableSpace with fitting package");
			struct Truck truck = { nullptr, 500, 50, 'B', {}, 0 };
			struct Package package = { nullptr, 500, 2 };
			int result = calculateAvailableSpace(&truck, &package);
			Assert::AreEqual(1, result, L"Expected truck to have available space for the package.");
		}

		// Acceptance test for the shortestPath function
		TEST_METHOD(ACC_SHP001)
		{
			Logger::WriteMessage("Acceptance Test: shortestPath with valid route");
			struct Route expectedRoute = { { { 0, 1 }, { 0, 2 }, { 0, 3 } }, 3, DIVERSION };
			struct Map map = populateMap();
			struct Point start = { 0, 0 };
			struct Point dest = { 0, 4 };
			struct Route actualRoute = shortestPath(&map, start, dest);

			Assert::AreEqual(expectedRoute.routeSymbol, actualRoute.routeSymbol, L"Expected route symbol to match.");
			Assert::AreEqual(expectedRoute.numPoints, actualRoute.numPoints, L"Expected number of points to match.");
			for (int i = 0; i < actualRoute.numPoints; ++i)
			{
				Assert::AreEqual(expectedRoute.points[i].row, actualRoute.points[i].row, L"Expected row values to match.");
				Assert::AreEqual(expectedRoute.points[i].col, actualRoute.points[i].col, L"Expected column values to match.");
			}
		}
		// Acceptance tests for the findTruckForShipment function
		TEST_METHOD(ACC_FTFS001)
		{
			Logger::WriteMessage("Acceptance Test: findTruckForShipment with suitable truck");
			struct Map map = populateMap();
			struct Point truckPosition = { 1, 1 };
			struct Truck trucks[1] = { { &truckPosition, 500, 50, 'B', nullptr, 0 } };
			struct Point packageDestination = { 3, 3 };
			struct Package package = { &packageDestination, 100, 10 };
			int result = findTruckForShipment(&map, trucks, 1, &package);
			Assert::AreEqual(0, result, L"Expected truck to be suitable for shipment.");
		}
		TEST_METHOD(ACC_FTFS002)
		{
			Logger::WriteMessage("Test with all trucks unavailable and package does not fit any truck");
			int result;
			struct Map map = populateMap();
			struct Point destination = { 1, 19 };
			struct Truck trucks[] = {
				{ new Point{0, 0}, 0, 0, 'B', NULL, 0 },
				{ new Point{0, 0}, 0, 0, 'B', NULL, 0 }
			};
			struct Package package = { &destination, 5.0, TRUCK_MAX_VOLUME+1 };

			result = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(ACC_FTFS003)
		{
			Logger::WriteMessage("Test with one truck unavailable and the other available");
			int result;
			struct Map map = populateMap();
			struct Point destination = { 4, 4 };
			struct Truck trucks[] = {
				{ new Point{0, 0}, 0, 0, 'Y', NULL, 0},
				{ new Point{0, 0}, 0, 0, 'Y', NULL, 0 }
			};
			struct Package package = { &destination, 5.0, 5.0 };
			result = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(0, result); 
		}
		TEST_METHOD(ACC_FTFS004)
		{
			Logger::WriteMessage("Test with all trucks available and package fits in multiple trucks");
			int result;
			struct Map map = populateMap();
			struct Point destination = { 4, 6 };
			struct Truck trucks[] = {
				{ new Point{0, 0}, 0, 0, 'Y', NULL, 0 },
				{ new Point{4, 4}, 0, 0, 'B', NULL, 0 }
			};
			struct Package package = { &destination, 5.0, 5.0 };
			result = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(ACC_FTFS005)
		{
			Logger::WriteMessage("Test with all trucks unavailable and invalid package destination");
			int result;
			struct Map map = populateMap();
			struct Point destination = { -1, -1 }; 
			struct Truck trucks[] = {
				{ new Point{0, 0}, 0, 0, 'B', NULL, 0 },
				{ new Point{2, 2}, 0, 0, 'B', NULL, 0 }
			};
			struct Package package = { &destination, 5.0, 5.0 };
			result = findTruckForShipment(&map, trucks, 2, &package);
			Assert::AreEqual(-1, result);
		}
	};
}