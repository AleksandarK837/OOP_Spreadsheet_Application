#include "fractionalNumber.h"

FractionalNumber::FractionalNumber() : Cell(), number(0)
{
}

FractionalNumber::FractionalNumber(const char * cell) : Cell(cell), number(0)
{
	convertToNumber();
}

void FractionalNumber::convertToNumber()
{
	number = atof(cell);
}

const double FractionalNumber::getNumber() const
{
	return number;
}

Cell * FractionalNumber::clone() const
{
	return new FractionalNumber(*this);
}

const char * FractionalNumber::printCell() const
{
	return cell;
}