#include "date.h"

Date::Date() : Cell(), number(0), day(0), month(0), year(0)
{
}

Date::Date(const char * cell) : Cell(cell), number(0), day(0), month(0), year(0)
{
	convertToNumber();
}

Cell * Date::clone() const
{
	return new Date(*this);

}

void Date::convertToNumber()
{
	char dayy[2];
	char monthh[2];
	char yearr[4];
	int j = 0;
	for (int i = 0; i < 2; i++) { dayy[i] = cell[i]; }
	for (int i = 3; i < 5; i++) { monthh[j++] = cell[i]; }
	j = 0;
	for (int i = 6; i < 10; i++) { yearr[j++] = cell[i]; }

	day = atoi(dayy);
	month = atoi(monthh);
	year = atoi(yearr);

	long y = (year - 1900) / 4;
	number = (year - 1900 - y) * 365 + y * 366;
}

const double Date::getNumber() const
{
	return number;
}

const char * Date::printCell() const
{
	return cell;
}