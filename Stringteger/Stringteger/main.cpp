#include "stringteger.h"
#include <iostream>

int main()
{
	Stringteger s("90");
	s.add(78);
	std::cout << "Should be 168: " << s.getValue() << std::endl;
	return 0;
}