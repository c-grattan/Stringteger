#include "stringteger.h"
#include <iostream>

int main()
{
	const int x = 100, y = 120;
	Stringteger s(std::to_string(y));
	s.subtract(x);
	std::cout << "Should be " << y - x << ": " << s.getValue() << std::endl;
	return 0;
}