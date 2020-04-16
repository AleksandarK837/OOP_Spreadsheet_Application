#include "cell.h"
#ifndef _String
#define _String

class String : public Cell
{
public:
	String();
	String(const char *cell);
	String(const String &rhs);
	String &operator=(const String &rhs);
	virtual ~String();

private:
	char *str;
	double number;

public:
	Cell *clone() const override;
	const char *printCell() const override;
	const double getNumber() const override;

private:
	void copyFrom(const String &rhs);
	void clear();

	void setStr();
	void convertToNumber() override;
};


#endif // !_String
