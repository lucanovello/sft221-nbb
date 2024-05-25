#include "pch.h"
#include "CppUnitTest.h"
#include "UnitTest_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WS3Test
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestValidPostalCode)
		{
			// Black-box test: Valid postal code
			char postalCode[] = "m2e4x4";
			char formattedPostalCode[10];
			bool result = isValidPostalCode(postalCode, formattedPostalCode);
			Assert::IsTrue(result);
			Assert::AreEqual("M2E 4X4", formattedPostalCode);
		}

		TEST_METHOD(TestInvalidPostalCode)
		{
			// Black-box test: Invalid postal code
			char postalCode[] = "m2e4x";
			char formattedPostalCode[10];
			bool result = isValidPostalCode(postalCode, formattedPostalCode);
			Assert::IsFalse(result);
		}

		TEST_METHOD(TestFormattedPostalCodeWithSpaces)
		{
			// White-box test: Postal code with spaces
			char postalCode[] = " m2e  4x4 ";
			char formattedPostalCode[10];
			bool result = isValidPostalCode(postalCode, formattedPostalCode);
			Assert::IsTrue(result);
			Assert::AreEqual("M2E 4X4", formattedPostalCode);
		}

	
	};
}
