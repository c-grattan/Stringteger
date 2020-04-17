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
			Assert().AreEqual(constructorTest.getValue(), expected);
		}

		TEST_METHOD(ConstructorChecksIsNumerical)
		{
			expected = "";
			Stringteger constructorTest("asdf");
			Assert().AreEqual(constructorTest.getValue(), expected);
		}

		TEST_METHOD(SetWorks)
		{
			expected = "1000";
			s.setValue(expected);
			Assert().AreEqual(s.getValue(), expected);
		}

		TEST_METHOD(SetTestsIsNumerical)
		{
			expected = "";
			s.setValue(expected);
			s.setValue("asdf");
			Assert().AreEqual(s.getValue(), expected);
		}
	};
}