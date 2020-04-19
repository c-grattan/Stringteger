#pragma once
#include <string>

class Stringteger
{
private:
	std::string value;

public:
	Stringteger(std::string value);

	void togglePositive();

	bool isPositive();

	void add(std::string xStr);
	void add(int x);
	void operator+(int x);
	void operator+(std::string x);

	bool lessThan(std::string value);
	bool lessThan(Stringteger value);

	void subtract(std::string xStr);
	void subtract(int x);
	void operator-(int x);
	void operator-(std::string x);

	std::string getValue() { return value; }
	void setValue(std::string value);
};