#include "cell.h"
#ifndef _FractionalNumber
#define _FractionalNumber

class FractionalNumber : public Cell
{
public:
	FractionalNumber();
	FractionalNumber(const char *cell);
	
private:
	double number;

public:
	const double getNumber() const override;
	Cell *clone() const override;
	const char *printCell() const override;

private:
	void convertToNumber() override;
};

#endif // !_FractionalNumber

