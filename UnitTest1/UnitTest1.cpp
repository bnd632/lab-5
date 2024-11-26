#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Вадим\source\repos\lab 2\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1

{
	TEST_CLASS(calcuate_Tests)
	{
	public:
		TEST_METHOD(calculate_1) {
			int n = 4;
			double x_1 = 1.0;
			double x_2 = 2.0;
			double step = 2;
			double expected = 6;

			double actual = Calculate(x_1, x_2, step, n);
			Assert::AreEqual(expected, actual);

		};
	public:
		TEST_METHOD(calculate_2) {
			int n = 4;
			double x_1 = 2.0;
			double x_2 = 2.0;
			double step = 3;
			double expected = 10;

			double actual = Calculate(x_1, x_2, step, n);
			Assert::AreEqual(expected, actual);



		};

	};
};
TEST_CLASS(checkValidParams_Tests)
{
public:

	TEST_METHOD(checkValidParams_get10_exceptionNotThrown)
	{
		int n = 10;
		try
		{
			checkValidParams(n);
			Assert::IsTrue(true);
		}
		catch (...)
		{
			Assert::Fail();

		}

	}
};