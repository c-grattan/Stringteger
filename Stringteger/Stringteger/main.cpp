#include "stringteger.h"
#include <iostream>

int main()
{
	const unsigned int zero = 0;
	Stringteger s(std::to_string(zero - 1));
	for (int i = 0; i < 10; i++)
	{
		std::cout << s.getValue() << std::endl;
		s.add(1);
	}
	return 0;
}