#include "row.h"
using std::cin;
using std::cout;
using std::endl;

void Row::copyFrom(const Row &rhs)
{
	c = new Cell*[rhs.capacity];
	for (int i = 0; i < rhs.size; i++)
	{
		c[i] = rhs.c[i]->clone();
	}
	size = rhs.size;
	capacity = rhs.capacity;
}

void Row::clear()
{
	for (int i = 0; i < size; i++)
	{
		delete c[i];
	}
	delete[]c;
	c = nullptr;
}

Row::Row() : c(nullptr), size(0), capacity(0)
{
}

Row::Row(const Row & rhs)
{
	copyFrom(rhs);
}

Row & Row::operator=(const Row & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Row::~Row()
{
	clear();
}

void Row::add(const Cell &obj)
{

	if (size >= capacity)
	{
		capacity *= 2;
		if (capacity == 0) capacity = 2;
		resize();
	}
	c[size++] = obj.clone();
}

void Row::resize()
{
	Cell **temp = new Cell*[capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = c[i]->clone();
	}
	delete[]c;
	c = temp;
}

void Row::addEmptyString()
{
	if (size >= capacity)
	{
		capacity *= 2;
		if (capacity == 0) capacity = 2;
		resize();
	}
	c[size++] = new String('\0');
}

Cell ** Row::getCells() const
{
	return c;
}

size_t Row::getSize() const
{
	return size;
}

void Row::edit(int cell)
{
	if (cell > size)
	{
		cout << "Cell " << cell << " doesnt exist\n";
		return;
	}
	cin.get();
	cout << "Enter new content: ";
	char newContent[1024];
	cin.getline(newContent, 1024);

	if (isInt(newContent) == true)
	{
		delete c[cell - 1];
		c[cell - 1] = new IntegerNumber(newContent);
	}
	else if (isDouble(newContent) == true)
	{
		delete c[cell - 1];
		c[cell - 1] = new FractionalNumber(newContent);
	}
	else if (isDate(newContent) == true)
	{
		delete c[cell - 1];
		c[cell - 1] = new Date(newContent);
	}
	else if (isString(newContent) == true)
	{
		delete c[cell - 1];
		c[cell - 1] = new String(newContent);
	}
	else cout << "The new content is unknown type\n";
}

bool Row::checkType(const char * cell)
{
	if (isInt(cell) == true)
	{
		add(IntegerNumber(cell));
		return true;
	}
	else if (isDouble(cell) == true)
	{
		add(FractionalNumber(cell));
		return true;
	}
	else if (isDate(cell) == true)
	{
		add(Date(cell));
		return true;
	}
	else if (isString(cell) == true)
	{
		add(String(cell));
		return true;
	}
	return false;
}

bool Row::isDate(const char * cell)
{
	if (strlen(cell) == 0) return false;
	bool flag;
	int point = 0;
	int i = 0;
	while (cell[i])
	{
		if (cell[i] == '.') point += 1;
		flag = ((cell[i] >= '0' && cell[i] <= '9') || cell[i] == '.');
		if (flag == false) return false;
		i += 1;
	}
	if (point != 2) return false;
	return true;
}

bool Row::isInt(const char * cell)
{
	bool flag;
	int i = 0;
	if (strlen(cell) == 0) return false;
	while (cell[i])
	{
		flag = cell[i] >= '0' && cell[i] <= '9';
		if (flag == false) return false;
		i += 1;
	}
	return true;
}

bool Row::isDouble(const char * cell)
{
	if (strlen(cell) == 0) return false;
	bool flag;
	int point = 0;
	int i = 0;
	while (cell[i])
	{
		if (cell[i] == '.') point += 1;
		flag = ((cell[i] >= '0' && cell[i] <= '9') || cell[i] == '.');
		if (flag == false) return false;
		i += 1;
	}
	if (point != 1) return false;
	return true;
}

bool Row::isString(const char * cell)
{
	if (strlen(cell) == 0) return true;
	int len = strlen(cell);
	if (cell[0] != '"' && cell[len - 1] != '"')
		return false;
	return true;
}

Row & Row::operator++(int)
{
	addEmptyString();
	return *this;
}

Row & Row::operator[](int col)
{
	edit(col);
	return *this;
}
