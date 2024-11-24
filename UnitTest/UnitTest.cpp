#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab3\lab3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(calculate_get4and3_return6)
		{
			int x = 4;
			int n = 3;
			int excepted = 6;
			int actual = calculate(x, n);
			Assert::AreEqual(excepted, actual);
		}

	public:

		TEST_METHOD(calculate_get5and2_return5)
		{
			int x = 5;
			int n = 2;
			int excepted = 5;
			int actual = calculate(x, n);
			Assert::AreEqual(excepted, actual);
		}
		
	public:

		TEST_METHOD(checkValidParams_get1_exceptionThrown)
		{
			int a = 3;
			int b = 3;
			int h = 0;
			int n = 1;

			try
			{
				checkValidParams(a, b, h, n);
				Assert::Fail;
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkValidParams_get5_exceptionNotThrown)
		{
			int a = -3;
			int b = 1;
			int h = 1;
			int n = 5;

			try
			{
				checkValidParams(a, b, h, n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail;
			}
		}
	};
}
