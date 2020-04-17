#include "pch.h"
#include "CppUnitTest.h"
#include "../Stringteger/stringteger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(ConstructorAssignsCorrectValue)
		{
			std::string expected = "1000";
			Stringteger s(expected);
			Assert().AreEqual(s.getValue(), expected);
		}

		TEST_METHOD(ConstructorChecksIsNumerical)
		{
			std::string expected = "";
			Stringteger s("asdf");
			Assert().AreEqual(s.getValue(), expected);
		}
	};
}