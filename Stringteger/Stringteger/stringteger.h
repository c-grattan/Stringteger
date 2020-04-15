#pragma once
#include <string>

class Stringteger
{
private:
	std::string value;

public:
	Stringteger(std::string value);

	void add(int x);
	void operator+(int x);

	std::string getValue() { return value; }
};