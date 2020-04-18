#include "stringteger.h"
#include <iostream>
#include <cctype>

bool isAllDigits(std::string str)
{
	if (!std::isdigit(str[0]) && str[0] != '-')
	{
		return false;
	}

	for (unsigned int i = 1; i < str.length(); i++)
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
		this->value = "";
	}
	else
	{
		this->value = value;
	}
}

bool stringIsPositive(std::string value)
{
	return value[0] != '-';
}

void toggleStringPositivity(std::string* value)
{
	if (stringIsPositive(*value))
	{
		*value = '-' + *value;
	}
	else
	{
		*value = value->substr(1);
	}
}

void Stringteger::togglePositive()
{
	toggleStringPositivity(&value);
}

bool Stringteger::isPositive()
{
	return stringIsPositive(value);
}

void Stringteger::add(int x)
{
	if (x > 0) //Base case for recursion
	{
		//Get top and bottom values (like in a chimney sum)
		std::string xStr = std::to_string(x);
		std::string top;
		std::string bottom;
		{
			bool valueIsLonger = xStr.length() < (value[0] == '-' ? value.length() - 1 : value.length());
			top = valueIsLonger ? xStr : value;
			bottom = valueIsLonger ? value : xStr;
		}

		if (isPositive())
		{
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
		else
		{
			const char* oldVal = value.c_str();
			value = x;
			subtract(std::atoi(oldVal));
		}
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

void Stringteger::setValue(std::string val)
{
	if (isAllDigits(val))
	{
		value = val;
	}
	else
	{
		std::cerr << "Cannot set value to: " << val << ", is NaN" << std::endl;
	}
}

bool Stringteger::lessThan(std::string val)
{
	bool valIsPositive = stringIsPositive(val);

	int len = (int)val.length(),
		thisLen = (int)value.length();

	if (valIsPositive != isPositive())
	{
		return valIsPositive; //Return true if given value is positive and stored value is negative
	}

	if (thisLen < len)
	{
		return valIsPositive; //Return true if there are less digits in the stored value, if both values are positive - false otherwise
	}
	else if (thisLen > len)
	{
		return !valIsPositive; //..
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			char ch = value[i];
			char vCh = val[i];
			if (ch != vCh)
			{
				return ch < vCh && valIsPositive;
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
		bool valueIsGreater = !lessThan(xStr);
		std::string top = valueIsGreater ? xStr : value;
		std::string bottom = valueIsGreater ? value : xStr;

		if (isPositive())
		{
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
					nextX += (int)pow(10, i + 1);
				}
				else
				{
					result = botCh - topCh;
				}

				bottom[botLen - i - 1] = result + 48;
			}

			if (valueIsGreater)
			{
				setValue(bottom);
			}
			else
			{
				setValue('-' + bottom);
			}
			subtract(nextX);
		}
		else
		{
			togglePositive();
			add(x);
			togglePositive();
		}
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