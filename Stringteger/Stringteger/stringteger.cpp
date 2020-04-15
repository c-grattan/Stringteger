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
		int topLen = (int)top.length(), botLen = (int)bottom.length();
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
		setValue(bottom);
		add(nextX);
	}
	else if (x < 0)
	{
		subtract(x * -1);
	}
}

void Stringteger::operator+(int x)
{
	add(x);
}

void Stringteger::setValue(std::string value)
{
	int v = std::atoi(value.c_str());
	this->value = std::to_string(v);
}

bool Stringteger::lessThan(std::string val)
{
	int len = val.length(),
		thisLen = value.length();
	if (thisLen < len)
	{
		return true;
	}
	else if (thisLen > len)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			char ch = value[i];
			char vCh = val[i];
			if (value[i] != val[i])
			{
				return ch < vCh;
			}
		}
		return false;
	}
}

bool Stringteger::lessThan(Stringteger val)
{
	return lessThan(val.getValue());
}

void Stringteger::subtract(int x)
{
	if (x > 0)
	{
		//Get top and bottom values (like in a chimney sum)
		std::string xStr = std::to_string(x);
		bool valueIsLonger = xStr.length() < value.length();
		std::string top = valueIsLonger ? xStr : value;
		std::string bottom = valueIsLonger ? value : xStr;

		int nextX = 0;
		int result;
		int topLen = (int)top.length(), botLen = (int)bottom.length();
		char topCh, botCh;
		for (int i = 0; i < topLen; i++)
		{
			topCh = top[topLen - i - 1] - 48;
			botCh = bottom[botLen - i - 1] - 48;
			if (botCh < topCh)
			{
				result = (botCh + 10) - topCh;
			}
			else
			{
				result = botCh - topCh;
			}

			bottom[botLen - i - 1] = result + 48;
		}

		setValue(bottom);
		subtract(nextX);
	}
	else if (x < 0)
	{
		add(x * -1);
	}
}

void Stringteger::operator-(int x)
{
	subtract(x);
}