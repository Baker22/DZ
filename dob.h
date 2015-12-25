#pragma once
#include<iostream>
using namespace std;
class Dob
{
	short day;
	short month;
	short year;
	short AllowedDay();

public:
	short GetDay()const{ return day; }
	short GetMonth()const{ return month; }
	short GetYear()const{ return year; }
	void SetDay(short day);
	void SetMonth(short month);
	void SetYear(short year);
	Dob() :Dob(10,12,10){};
	Dob(short day, short month, short year);
	~Dob();
};

