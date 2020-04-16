#include "cell.h"
#ifndef _IntegerNumber
#define _IntegerNumber

class IntegerNumber : public Cell
{
public:
	IntegerNumber();
	IntegerNumber(const char *cell);
	
private:
	int number;

public:
	Cell *clone() const override;
	const double getNumber() const override;
	const char *printCell() const override;

private:
	virtual void convertToNumber();
};

#endif // !_IntegerNumber
