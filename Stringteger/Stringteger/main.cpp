#include "stringteger.h"
#include <iostream>

int main()
{
	const int x = 120, y = 100;
	Stringteger s(std::to_string(y));
	//s.subtract(x);
	std::cout << "Should be " << (y < x) << ": " << s.lessThan(std::to_string(x)) << std::endl;
	return 0;
}