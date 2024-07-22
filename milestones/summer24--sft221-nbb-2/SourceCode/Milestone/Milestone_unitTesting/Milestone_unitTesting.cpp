#include "pch.h"
#include "CppUnitTest.h"
#include "Milestone_unitTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MilestoneunitTesting
{
	TEST_CLASS(DistanceTesting)
	{
	public:
		
		TEST_METHOD(Distance1)
		{
			Logger::WriteMessage("Black box Test FD001");
			double d;
			struct Point p1 = {1,1};
			struct Point p2 = {4,4};
			d = distance(&p1, &p2);
			Assert::AreEqual(4.24264, d, 0.01);

		}
		TEST_METHOD(Distance2)
		{
			Logger::WriteMessage("Black box Test FD002");
			double d;
			struct Point p1 = { -2,-16 };
			struct Point p2 = { 12,-54 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}		
		TEST_METHOD(Distance3)
		{
			Logger::WriteMessage("Black box Test FD003");
			double d;
			struct Point p1 = { 1000,1000 };
			struct Point p2 = { 2000,2000 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}		
		TEST_METHOD(Distance4)
		{
			Logger::WriteMessage("Black box Test FD004");
			double d;
			struct Point p1 = { 2,2 };
			struct Point p2 = { 2,2 };
			d = distance(&p1, &p2);
			Assert::AreEqual(0, d, 0.01);

		}
	};

    TEST_CLASS(TruckForShipmentTesting)
    {
    public:

        TEST_METHOD(FindTruckForShipment1)
        {
            Logger::WriteMessage("White box Test FT001_WT");
            Map map = populateMap();
            printMap(&map, 5, 5);
            Truck trucks[1] = { };
            int numTrucks = 1;
            Package package = { };

            int result = findTruckForShipment(map, trucks, numTrucks, package);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(FindTruckForShipment2)
        {
            Logger::WriteMessage("White box Test FT002_WT");
            Map map = populateMap();
            printMap(&map, 5, 5);
            Truck tr1{};
            Truck tr2{};
            Truck tr3{};
            Truck trucks[3] = { tr1, tr2, tr3 };
            int numTrucks = 3;
            Package package{};
			package.destination = new Point{ 10, 10 };

            int result = findTruckForShipment(map, trucks, numTrucks, package);
            Assert::AreEqual(1, result);
        }

        TEST_METHOD(FindTruckForShipment3)
        {
            Logger::WriteMessage("White box Test FT003_WT");
            Map map;
            printMap(&map, 5, 5); 
            Truck trucks[2] = { };
            int numTrucks = 2;
            Package package = { };

            int result = findTruckForShipment(map, trucks, numTrucks, package);
            Assert::AreEqual(-1, result);
        }

        TEST_METHOD(FindTruckForShipment4)
        {
            Logger::WriteMessage("White box Test FT004_WT");
            Map map;
            Truck trucks[2] = { };
            int numTrucks = 2;
            Package package = {  };

            int result = findTruckForShipment(map, trucks, numTrucks, package);
            Assert::AreEqual(-1, result); 
        }
    };

    TEST_CLASS(DestinationValidationTesting)
    {
    public:

        TEST_METHOD(IsValidDestination1)
        {
            Logger::WriteMessage("White box Test VD001_WT");
            Point dest = { };

            bool result = isValidDestination(&dest);

            Assert::IsTrue(result);
        }

        TEST_METHOD(IsValidDestination2)
        {
            Logger::WriteMessage("White box Test VD002_WT");
            Point dest = {  };

            bool result = isValidDestination(&dest);
            Assert::IsFalse(result);
        }

        TEST_METHOD(IsValidDestination3)
        {
            Logger::WriteMessage("White box Test VD003_WT");
            Point dest = {  };

            bool result = isValidDestination(&dest);
            Assert::IsTrue(result);
        }

        TEST_METHOD(IsValidDestination4)
        {
            Logger::WriteMessage("White box Test VD004_WT");
            bool result = isValidDestination(NULL);

            Assert::IsFalse(result); 
        }
    };

    TEST_CLASS(CalculateSpaceTesting)
    {
    public:

        TEST_METHOD(CalculateAvailableSpace1)
        {
            Logger::WriteMessage("White box Test CS001_WT");
            Truck truck = { };

            int availableSpace = calculateAvailableSpace(&truck);
            int expectedSpace = ;
            Assert::AreEqual(expectedSpace, availableSpace);
        }

        TEST_METHOD(CalculateAvailableSpace2)
        {
            Logger::WriteMessage("White box Test CS002_WT");
            Truck truck = { };

            int availableSpace = calculateAvailableSpace(&truck);
            Assert::AreEqual(0, availableSpace);
        }

        TEST_METHOD(CalculateAvailableSpace3)
        {
            Logger::WriteMessage("White box Test CS003_WT");
            Truck truck = { };

            int availableSpace = calculateAvailableSpace(&truck);
            int expectedSpace = ;
            Assert::AreEqual(expectedSpace, availableSpace);
        }

        TEST_METHOD(CalculateAvailableSpace4)
        {
            Logger::WriteMessage("White box Test CS004_WT");
            int availableSpace = calculateAvailableSpace(NULL);
            Assert::AreEqual(-1, availableSpace); 
        }
    };
}
