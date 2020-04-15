#include "stringteger.h"
#include <iostream>

int main()
{
	const int x = 12334, y = 66678;
	Stringteger s(std::to_string(x));
	s.add(y);
	std::cout << "Should be " << x + y << ": " << s.getValue() << std::endl;
	return 0;
}