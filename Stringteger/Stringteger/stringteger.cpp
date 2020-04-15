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
	if (x)
	{
		std::string xStr = std::to_string(x);
		bool valueIsLonger = xStr.length() < value.length();
		std::string top = valueIsLonger ? xStr : value;
		std::string bottom = valueIsLonger ? value : xStr;

		int nextX = 0;
		int result;
		int topLen = top.length(), botLen = bottom.length();
		for (int i = 0; i < topLen; i++)
		{
			result = (top[topLen - 1 - i] - 48) + (bottom[botLen - 1 - i] - 48);
			if (result > 9)
			{
				bottom[botLen - 1 - i] = '9';
				nextX += result - 9;
			}
			else
			{
				bottom[botLen - 1 - i] = result + 48;
			}
		}

		value = bottom;
		add(nextX);
	}
}

void Stringteger::operator+(int x)
{
	add(x);
}