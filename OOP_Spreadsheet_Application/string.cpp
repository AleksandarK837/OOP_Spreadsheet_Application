#include "string.h"

void String::copyFrom(const String & rhs)
{
	//Cell::copyFrom(rhs);
	int len = strlen(rhs.str);
	str = new char[len + 1];
	strcpy_s(str, len + 1, rhs.str);
	number = rhs.number;
}

void String::clear()
{
	//Cell::clear();
	delete[]str;
	str = nullptr;
	number = 0;
}

String::String() : Cell(), number(0)
{
}

String::String(const char * cell) : Cell(cell), number(0), str(nullptr)
{
	setStr();
	convertToNumber();
}

String::String(const String &rhs) : Cell(rhs)
{
	copyFrom(rhs);
}

String & String::operator=(const String & rhs)
{
	if (this != &rhs)
	{
		Cell::operator=(rhs);
		clear();
		copyFrom(rhs);
	}
	return *this;
}

String::~String()
{
	delete[]str;
	str = nullptr;
}

Cell * String::clone() const
{
	return new String(*this);
}

const char * String::printCell() const
{
	return str;
}

void String::convertToNumber()
{
	int i = 0;
	int len = 0;
	while (str[i])
	{
		if (str[i] != '"') len += 1;
		i += 1;
	}

	char *temp = new char[len + 1];
	int j = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != '"')
			temp[j++] = str[i];
	}
	temp[len] = '\0';

	i = 0;
	int point = 0;
	while (temp[i])
	{
		if (temp[i] == '.') point += 1;
		bool flag = ((temp[i] >= '0' && temp[i] <= '9') || temp[i] == '.');
		if (flag == false) return;
		i += 1;
	}
	number = atof(temp);
	delete[]temp;
}

const double String::getNumber() const
{
	return number;
}

void String::setStr()
{
	int i = 0;
	int j = 0;
	int len = 0;
	while (cell[i])
	{
		if (cell[i] != '"' && cell[i] != '\\') len += 1;
		i += 1;
	}
	if (cell[1] == '\\') len += 2;
	str = new char[len + 1];
	if (cell[1] == '\\')
	{
		j = 1;
		str[0] = '"';
		str[len - 1] = '"';
	}

	i = 0;
	while (cell[i])
	{
		if (cell[i] != '"' && cell[i] != '\\') str[j++] = cell[i];
		i += 1;
	}
	str[len] = '\0';
}
