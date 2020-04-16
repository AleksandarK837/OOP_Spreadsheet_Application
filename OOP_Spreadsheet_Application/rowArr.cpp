#include "rowArr.h"
using std::cin;
using std::cout;
using std::endl;

void RowArr::copyFrom(const RowArr &rhs)
{
	size = rhs.size;

	row = new Row[size];
	for (int i = 0; i < size; i++)
	{
		row[i] = rhs.row[i];
	}
}

void RowArr::clear()
{
	delete[]row;
}

void RowArr::resize()
{
	Row *temp = new Row[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = row[i];
	}
	delete[]row;
	row = temp;
	size += 1;
}

RowArr::RowArr() : row(nullptr), size(0)
{
}

RowArr::RowArr(const RowArr & rhs)
{
	copyFrom(rhs);
}

RowArr & RowArr::operator=(const RowArr & rhs)
{
	if (this != &rhs)
	{
		clear();
		copyFrom(rhs);
	}
	return *this;
}

RowArr::~RowArr()
{
	clear();
}

bool RowArr::load(const char *filePath)
{
	std::ifstream file;
	file.open(filePath, std::ios::in);
	char r[1024];

	while (!file.eof())
	{
		file.getline(r, 1024);
		size += 1;
	}
	row = new Row[size];
	file.seekg(0, std::ios::beg);

	int longestRow = 0;

	for (int i = 0; i < size; i++)
	{
		file.getline(r, 1024);
		if (takeCell(r, i) == false) return false;
		int cnt = CellSize(r);
		if (longestRow < cnt) longestRow = cnt;
	}

	for (int i = 0; i < size; i++)
	{
		while (row[i].getSize() < longestRow)
		{
			row[i].addEmptyString();
		}
	}
	return true;
}

void RowArr::edit(int r, int col)
{
	if (r > size || r < 1)
	{
		cout << r << " doesnt exist\n";
		return;
	}
	row[r - 1].edit(col);
}

void RowArr::save(const char *filePath)
{
	std::ofstream file;
	file.open(filePath, std::ios::out | std::ios::trunc);

	int SIZE;
	for (int i = 0; i < size; i++)
	{
		SIZE = row[i].getSize();
		for (int j = 0; j < SIZE; j++)
		{
			if (j == SIZE - 1)
			{
				file << row[i].getCells()[j]->getCell();
				if (i != size - 1)
					file << "\n";
				break;
			}
			file << row[i].getCells()[j]->getCell() << ",";
		}
	}
	file.close();
}

void RowArr::sortAscending(int col)
{
	int SIZE = row[0].getSize();
	if (col > SIZE || col < 1)
	{
		cout << "Col" << col << "doesn't exist" << std::endl;
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (row[j].getCells()[col - 1]->getNumber() > row[j + 1].getCells()[col - 1]->getNumber())
			{
				std::swap(row[j], row[j + 1]);
			}
		}
	}
}

void RowArr::sortDescending(int col)
{
	int SIZE = row[0].getSize();
	if (col > SIZE || col < 1)
	{
		std::cout << "Col" << col << "doesn't exist" << std::endl;
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (row[j].getCells()[col - 1]->getNumber() < row[j + 1].getCells()[col - 1]->getNumber())
			{
				std::swap(row[j], row[j + 1]);
			}
		}
	}
}

bool RowArr::takeCell(const char *row, int index)
{
	if (strlen(row) == 0) return true;
	char cell[1024];
	int j = 0;
	int cellNumber = 0;
	int len = strlen(row);

	for (int i = 0; i < len; i++)
	{
		while (row[i] == ' ') i += 1;
		while (row[i] != ',')
		{
			if (i == len) break;
			cell[j++] = row[i];
			i += 1;
		}
		cell[j] = '\0';
		j = 0;

		if (this->row[index].checkType(cell) == false)
		{
			cout << "Line " << index + 1 << ", Col " << cellNumber + 1 << " --> unknown type\n";
			return false;
		}
		cellNumber += 1;
		memset(cell, 0, 1024);
	}
	return true;
}

RowArr & RowArr::operator++(int)
{
	for (int i = 0; i < size; i++)
	{
		row[i]++;
	}
	return *this;
}

RowArr & RowArr::operator++()
{
	resize();
	int rowSize = row[0].getSize();
	while (row[size - 1].getSize() < rowSize)
	{
		row[size - 1].addEmptyString();
	}
	return *this;
}

Row & RowArr::operator[](int row)
{
	return this->row[row - 1];
}

int RowArr::CellSize(const char * str)
{
	int cnt = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == ',') cnt += 1;
		i += 1;
	}
	return cnt + 1;
}

void RowArr::print()
{
	int cellSize = row[0].getSize();
	int *colLargestInterval = new int[cellSize];

	for (int i = 0; i < cellSize; i++)
	{
		colLargestInterval[i] = strlen(row[0].getCells()[i]->printCell());
	}

	int cellLen = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < cellSize; j++)
		{
			cellLen = strlen(row[i].getCells()[j]->printCell());
			if (colLargestInterval[j] < cellLen)
				colLargestInterval[j] = cellLen;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cellSize = row[i].getSize();
		for (int j = 0; j < cellSize; j++)
		{
			cellLen = colLargestInterval[j] - strlen(row[i].getCells()[j]->printCell());
			cout << "| ";
			cout << row[i].getCells()[j]->printCell();
			for (int k = 0; k < cellLen; k++)
				cout << " ";
			cout << " |";
		}
		cout << std::endl;
	}
	delete[]colLargestInterval;
}
