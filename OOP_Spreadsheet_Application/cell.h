#include <iostream>
#ifndef _Cell
#define _Cell

class Cell
{
public:
	Cell();
	Cell(const char *cell);
	Cell(const Cell &rhs);
	Cell &operator=(const Cell &rhs);
	virtual ~Cell();

protected:
	char *cell;

	void setCell(const char *cell);
	virtual void convertToNumber() = 0;

public:
	virtual Cell *clone() const = 0;
	virtual const double getNumber() const = 0;
	virtual const char *printCell() const = 0;

	const char *getCell() const;

private:
	void copyFrom(const Cell &rhs);
	void clear();
};

#endif // !_Cell
