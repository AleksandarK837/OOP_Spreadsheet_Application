#include "integerNumber.h"

IntegerNumber::IntegerNumber() : Cell(), number(0)
{
}

IntegerNumber::IntegerNumber(const char * cell) : Cell(cell), number(0)
{
	convertToNumber();
}

void IntegerNumber::convertToNumber()
{
	number = atoi(cell);
}

Cell * IntegerNumber::clone() const
{
	return new IntegerNumber(*this);
}

const double IntegerNumber::getNumber() const
{
	return number;
}

const char * IntegerNumber::printCell() const
{
	return cell;
}

