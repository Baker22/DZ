#include<iostream>
using namespace std;

typedef unsigned int uint;

class Date
{
	uint year;
	uint month;
	uint day;
	
public:
	uint GetDay()const{ return day; }
	uint GetMonth()const{ return month; }
	uint GetYear()const{ return year; }
	
	void SetYear(uint year);
	void SetMonth(uint month);
	void SetDay(uint day);
	
	Date();
	Date(uint day, uint month, uint year);
	~Date(){};

	char*DayOfWeek()const;
	uint AllowedDay()const;
	bool YearIsLeap(uint year)const;
	char *PrintDate();
	uint YearInDays()const;
	uint MonthInDays()const;
	uint DateInDays()const;
	Date operator++();
	Date operator--();
	void operator+(uint days);
	void operator-(uint days);
	uint operator-(Date days);
	bool operator>(Date d);
	bool operator<(Date d);
	bool operator==(Date d);
	bool operator!=(Date d);
	void operator+=(Date d);
	void operator-=(Date d);
};