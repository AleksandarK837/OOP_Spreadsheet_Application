#include <fstream>
#include "row.h"
#ifndef _RowArr
#define _RowArr

class RowArr
{

public:
	RowArr();
	RowArr(const RowArr &rhs);
	RowArr &operator=(const RowArr &rhs);
	~RowArr();

private:
	size_t size;
	Row *row;

public:
	bool load(const char *filePath);
	void print();
	void edit(int row, int col);
	void save(const char *filePath);
	void sortAscending(int col);
	void sortDescending(int col);

	RowArr &operator++(int); // add COL
	RowArr &operator++(); // add ROW
	Row &operator[](int row); //edit

private:
	bool takeCell(const char *row, int index);
	int CellSize(const char *str);

	void copyFrom(const RowArr &rhs);
	void clear();
	void resize();
};

#endif // !_RowArr
