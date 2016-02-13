#include"Date.h"

void Date::SetDay(uint day)
{
	if (day > 0 && day <= AllowedDay())
     this->day = day;
}

void Date::SetMonth(uint month)
{
	if (month > 0 && month <= 12)
		this->month = month;	
}

void Date::SetYear(uint year)
{
	if (year > 0 && year < 2016)
		this->year = year;
}

Date::Date(){ 1, 1, 1; }

Date::Date(uint day, uint month, uint year)

{
	SetYear(year);
	SetMonth(month);
	SetDay(day);	
}

uint Date::AllowedDay()const
{
	uint a;
	if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
		a = 31;
	else if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
	a = 30;
	if (this->month == 2 && YearIsLeap(this->year) ==true)
		a = 29;
	if (this->month == 2 && YearIsLeap(this->year)==0)
		a = 28;
	return a;
}

bool Date::YearIsLeap(uint year)const
{
	if (this->year % 4==0&&this->year%100!=0||this->year%400==0)
		return true;
	return false;
}
char*Date::DayOfWeek()const
{
	char*d = new char[10];
	int res;
	Date basic;
	basic.day = 18;
	basic.month = 10;
	basic.year = 1981;
	int basic_days = basic.DateInDays();
	int incoming_days = DateInDays();
	if ( incoming_days==basic_days )
		res = 0;
	if (incoming_days> basic_days)
		res = (incoming_days - basic_days) % 7;
	if (incoming_days < basic_days)
		res = (basic_days - incoming_days) % 7;
	switch (res)
	{
	case 0:
			d ="Sunday ";
			break;
	case 1:
		d = "Monday ";
			break;
	case 2:
		d = "Tuesday ";
			break;
	case 3:
		d = "Wednesday ";
			break;
	case 4:
		d = "Thursday ";
			break;
	case 5:
		d = "Friday ";
			break;
	case 6:
		d = "Saturday ";
			break;
	default:
		break;
	}
	return d;
}



char *Date::PrintDate()
{
	char*date = new char[21];
	char*temp = new char[3];
	strcpy_s(date,strlen(DayOfWeek())+1,DayOfWeek());
	_itoa_s(day, temp, 3, 10);
	strcat_s(date, 21, temp);
	strcat_s(date,21,".");
	_itoa_s(month,temp, 3,10);
	strcat_s(date, 21, temp);
	strcat_s(date,21,".");
	_itoa_s(year, temp, 5, 10);
	strcat_s(date, 21, temp);
	strcat_s(date, 21, ".");
	return date;
}

Date Date::operator++()
{
	Date x;
	x.day=this->day;
	x.month = this->month;
	x.year = this->year;
	if (x.day<AllowedDay())
	x.day++;
	else if (x.day == AllowedDay())
	{
		x.day = 1;
		if (x.month < 12)
			x.month++;
		else if (x.month == 12)
		{
			x.month = 1;
			x.year++;
		}
			
	}
	return x;
}

Date Date:: operator--()
{
	Date x;
	x.day = this->day;
	x.month = this->month;
	x.year = this->year;
	if (x.day>1)
	x.day--;
	else if (x.day == 1)
	{
		if (x.month > 1)
			x.month--;
		else if (x.month == 1)
			x.year--;
		x.month = 12;
		x.day = AllowedDay();
	}
	return x;
}

void Date::operator+(uint days)
{
	for (uint i = 0; i <days;i++)
	if (this->day < AllowedDay())
		this->day++;
	else if (this->day == AllowedDay())
	{
		this->day = 1;
		if (this->month < 12)
			this->month++;
		else if (this->month == 12)
		{
			this->month = 1;
			this->year++;
		}
	}
}

void Date::operator-(uint days)
{
	for (uint i = 0; i <days;i++)
	if (this->day > 1)
		this->day--;
	else if (this->day == 1)
	{
		if (this->month > 1)
			this->month--;
		else if (this->month == 1)
		{
			this->month = 12;
			this->year--;
		}
		this->day = AllowedDay();
	}
}

uint Date::operator-(Date slave)
{
	uint days;
	if (DateInDays() == slave.DateInDays())
		days = 0;
	if(DateInDays() <slave.DateInDays())
		days = (slave.DateInDays() -DateInDays() );
	if(DateInDays() >slave.DateInDays())
		days = ( DateInDays()-slave.DateInDays() );
		return days;
}

uint Date::YearInDays()const
{
	uint days = 0;
	for (int i =this->year; i >0; i--)
	{
		if(YearIsLeap(this->year))
			days += 366;
		else
			days += 365;
	}
	return days;
}
uint Date::MonthInDays()const
{
	Date temp;
	temp.year = this->year;
	temp.month = this->month-1;
	temp.day = this->day;
	uint days = 0;
	for (; temp.month> 0;temp.month --)
		days += temp.AllowedDay();
	return days;
}

uint Date::DateInDays()const
{
	uint days = this->day;
	days += MonthInDays();
	days += YearInDays();
	return days;
}

bool Date::operator>(Date d)
{
	if (DateInDays() > d.DateInDays())
		return true;
	return false;
}
bool Date::operator<(Date d)
{
	if (DateInDays() < d.DateInDays())
		return true;
	return false;
}
bool Date::operator==(Date d)
{
	if (DateInDays() == d.DateInDays())
		return true;
	return false;
}
bool Date::operator!=(Date d)
{
	if (DateInDays() != d.DateInDays())
		return true;
	return false;
}
void Date ::operator+=(Date d)
{
	if ((this->day + d.day) <= AllowedDay())
		this->day += d.day;
	else
		operator+(d.day);
	if ((this->month + d.month) <= 12)
		this->month += d.month;
	else
		this->year++;
	this->month = 1;
	this->year += d.year;
}

void Date ::operator-=(Date d)
{
	if (DateInDays() > d.DateInDays())
	{
		if (this->day > d.day)
		this->day -= d.day;
	else
		operator-(d.day);
	if (this->month > d.month)
		this->month -= d.month;
	else
		this->year--;
	short a = this->month;
	this->month = (12-(d.month-a));
	this->year -= d.year;
	}
	
}

