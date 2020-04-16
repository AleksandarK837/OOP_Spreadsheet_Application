#include "integerNumber.h"
#include "fractionalNumber.h"
#include "date.h"
#include "string.h"

#ifndef _Row
#define _Row

class Row
{
public:
	Row();
	Row(const Row &rhs);
	Row &operator=(const Row &rhs);
	~Row();

private:
	Cell **c;
	size_t capacity;
	size_t size;

public:
	void add(const Cell &obj);
	void addEmptyString();

	bool checkType(const char *cell);
	void edit(int cell);

	Cell **getCells() const;
	size_t getSize() const;

	Row &operator++(int); // add cell at the end
	Row &operator[](int col); // edit cell

private:
	bool isDate(const char *cell);
	bool isInt(const char *cell);
	bool isDouble(const char *cell);
	bool isString(const char *cell);

	void copyFrom(const Row &rhs);
	void clear();
	void resize();
};

#endif // !_Row
