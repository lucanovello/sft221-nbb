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
}