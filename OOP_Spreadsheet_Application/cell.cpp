#include "cell.h"

void Cell::setCell(const char *cell)
{
	delete[]this->cell;
	int len = strlen(cell);
	this->cell = new char[len + 1];
	strcpy_s(this->cell, len + 1, cell);
}

const char * Cell::getCell() const
{
	return cell;
}

void Cell::copyFrom(const Cell &rhs)
{
	setCell(rhs.cell);
}

void Cell::clear()
{
	delete[]cell;
	cell = nullptr;
}

Cell::Cell() : cell(nullptr)
{
}

Cell::Cell(const char *cell) : cell(nullptr)
{
	setCell(cell);
}

Cell::Cell(const Cell & rhs)
{
	copyFrom(rhs);
}

Cell & Cell::operator=(const Cell &rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

Cell::~Cell()
{
	clear();
}
