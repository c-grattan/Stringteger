#include "stringteger.h"
#include <iostream>
#include <cctype>

bool isAllDigits(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

Stringteger::Stringteger(std::string value)
{
	if (!isAllDigits(value))
	{
		std::cerr << "Cannot create stringteger with value " << value << ", is NaN" << std::endl;
	}
	else
	{
		this->value = value;
	}
}

void Stringteger::add(int x)
{
	if (x > 0) //Base case for recursion
	{
		//Get top and bottom values (like in a chimney sum)
		std::string xStr = std::to_string(x);
		bool valueIsLonger = xStr.length() < value.length();
		std::string top = valueIsLonger ? xStr : value;
		std::string bottom = valueIsLonger ? value : xStr;

		//nextX holds any overflow that needs to be added after this iteration
		int nextX = 0;
		int result;
		int topLen = top.length(), botLen = bottom.length();
		char topCh, botCh;
		for (int i = 0; i < topLen; i++)
		{
			topCh = top[topLen - i - 1] - 48;
			botCh = bottom[botLen - i - 1] - 48;
			result = botCh + topCh;
			if (result > 9)
			{
				bottom[botLen - 1 - i] = '0';
				nextX += result * (int)pow(10, i);
			}
			else
			{
				bottom[botLen - 1 - i] = result + 48;
			}
		}

		//Update value and add any overflow
		value = bottom;
		add(nextX);
	}
}

void Stringteger::operator+(int x)
{
	add(x);
}

void Stringteger::subtract(int x)
{
	
}

void Stringteger::operator-(int x)
{
	subtract(x);
}