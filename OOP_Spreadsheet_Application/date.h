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
	Cell *clone() const override;
	const char *printCell() const override;
	const double getNumber() const override;

private:
	void convertToNumber() override;
};

#endif // !_Date
