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
			Logger::WriteMessage("Test BB_FD001");
			double d;
			struct Point p1 = { 1,1 };
			struct Point p2 = { 4,4 };
			d = distance(&p1, &p2);
			Assert::AreEqual(4.24264, d, 0.01);

		}
		TEST_METHOD(Distance2)
		{
			Logger::WriteMessage("Test BB_FD002");
			double d;
			struct Point p1 = { -2,-16 };
			struct Point p2 = { 12,-54 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(Distance3)
		{
			Logger::WriteMessage("Test BB_FD003");
			double d;
			struct Point p1 = { 1000,1000 };
			struct Point p2 = { 2000,2000 };
			d = distance(&p1, &p2);
			Assert::AreEqual(-1, d, 0.01);

		}
		TEST_METHOD(Distance4)
		{
			Logger::WriteMessage("Test BB_FD004");
			double d;
			struct Point p1 = { 2,2 };
			struct Point p2 = { 2,2 };
			d = distance(&p1, &p2);
			Assert::AreEqual(0, d, 0.01);

		}
	};
	TEST_CLASS(isValidDestinationTesting)
	{
	public:

		TEST_METHOD(validDest1)
		{
			Logger::WriteMessage("Test BB_FDV01");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 1,3 };
			d = isValidDestination(&map, p1);
			Assert::AreEqual(1, d, 0.01);

		}
		TEST_METHOD(validDest2)
		{
			Logger::WriteMessage("Test BB_FDV02");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { 2,2 };
			d = isValidDestination(&map, p1);
			Assert::AreEqual(0, d, 0.01);

		}
		TEST_METHOD(validDest3)
		{
			Logger::WriteMessage("Test BB_FDV03");
			int d;
			struct Map map = populateMap();
			struct Point p1 = { -2,5 };
			d = isValidDestination(&map, p1);
			Assert::AreEqual(0, d, 0.01);

		}
		TEST_METHOD(validDest4)
		{
			Logger::WriteMessage("Test BB_FDV04");
			int d;
			{
				struct Point p1 = { 2,2 };
				d = isValidDestination(NULL, p1);
				Assert::AreEqual(0, d, 0.01);

			}
		};
	};
}