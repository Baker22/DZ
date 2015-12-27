#include "Dob.h"

Dob ::Dob()
{
	day = 0;
	month = 0;
	year = 0;
}

Dob::Dob(short day, short month, short year)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}


Dob::~Dob()
{
}

short Dob::GetDay()const
{
	if (!day)
		return 1;
	return day;
}
short Dob::GetMonth()const
{
if (!month)
		return 1;
	return month;
}
short Dob::GetYear()const
{
if (!year)
  return 1;
	return year;
}

void Dob::SetDay(short day)
{
if (day>0&&day<=AllowedDay())
	this->day = day;
else this->day=1;
}

void Dob::SetMonth(short month)
{
	if (month > 0 && month <=12)
		this->month = month;
	else this->month=1;
}

void Dob::SetYear(short year)
{
	if (year < 2015)
		this->year = year;
	else this->year=1;
}
short Dob::AllowedDay()
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
}
