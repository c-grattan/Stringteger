#pragma once
#include <string>

class Stringteger
{
private:
	std::string value;

public:
	Stringteger(std::string value);

	void togglePositive();

	void add(int x);
	void operator+(int x);

	bool lessThan(std::string value);
	bool lessThan(Stringteger value);

	void subtract(int x);
	void operator-(int x);

	std::string getValue() { return value; }
	void setValue(std::string value);
};