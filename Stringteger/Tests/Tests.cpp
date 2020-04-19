#include "pch.h"
#include "CppUnitTest.h"
#include "../Stringteger/stringteger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

Stringteger s("");
std::string expected;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(ConstructorAssignsCorrectValue)
		{
			//Also tests that getValue works
			expected = "1000";
			Stringteger constructorTest(expected);
			Assert().AreEqual(expected, constructorTest.getValue());
		}

		TEST_METHOD(ConstructorChecksIsNumerical)
		{
			expected = "";
			Stringteger constructorTest("asdf");
			Assert().AreEqual(expected, constructorTest.getValue());
		}

		TEST_METHOD(SetWorks)
		{
			expected = "600";
			s.setValue(expected);
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(SetTestsIsNumerical)
		{
			expected = "500";
			s.setValue(expected);
			s.setValue("asdf");
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(IsPositive)
		{
			s.setValue("100");
			Assert().IsTrue(s.isPositive());
		}

		TEST_METHOD(IsNegative)
		{
			s.setValue("-100");
			Assert().IsFalse(s.isPositive());
		}

		TEST_METHOD(TogglePositive)
		{
			expected = "-250";
			s.setValue("250");
			s.togglePositive();
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(PositiveAddPositive)
		{
			s.setValue("500");
			s.add(60);
			expected = "560";
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(NegativeAddPositive)
		{
			s.setValue("-400");
			s.add(60);
			expected = "-340";
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(PositiveSubtractPositive)
		{
			s.setValue("700");
			s.subtract(70);
			expected = "630";
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(NegativeSubtractPositive)
		{
			s.setValue("-900");
			s.subtract(50);
			expected = "-950";
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(PositiveToNegative)
		{
			s.setValue("10");
			s.subtract(90);
			expected = "-80";
			Assert().AreEqual(expected, s.getValue());
		}

		TEST_METHOD(NegativeToPositive)
		{
			s.setValue("-10");
			s.add(90);
			expected = "80";
			Assert().AreEqual(expected, s.getValue());
		}
	};
}