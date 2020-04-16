#include "cell.h"
#ifndef _Date
#define _Date

class Date : public Cell
{
public:
	Date();
	Date(const char *cell);
	
private:
	int day;
	int month;
	int year;
	long number;

public:
	virtual Cell *clone() const;
	virtual const char *printCell() const;
	virtual const double getNumber() const;

private:
	void convertToNumber() override;
};

#endif // !_Date
