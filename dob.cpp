/*#include "dob.h"


dob::dob(short day, short month, short year)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}


dob::~dob()
{
}

void dob::SetDay(short day)
{
if (day>0&&day<=AllowedDay())
	this->day = day;
else this->day=1;
}

void dob::SetMonth(short month)
{
	if (month > 0 && month <=12)
		this->month = month;
	else this->month=1;
}

void dob::SetYear(short year)
{
	if (year < 2015)
		this->year = year;
	else this->year=1;
}
short dob::AllowedDay()
{
	short a;
	double b = year % 4;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	a = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11);
	a = 30;
	if (month == 2 && b == 0)
		a = 29;
	if (month == 2 && b > 0)
		a = 28;
	return a;
}*/
