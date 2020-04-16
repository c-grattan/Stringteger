#include "stringteger.h"
#include <iostream>

int main()
{
	const unsigned int zero = 0;
	Stringteger s("-100");
	s.togglePositive();
	std::cout << "Should be 100: " << s.getValue() << std::endl;
	s.setValue("-100");
	s.subtract(10);
	std::cout << "Should be -110: " << s.getValue() << std::endl;
	return 0;
}