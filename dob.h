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
	short GetDay()const;
	short GetMonth()const; 
	short GetYear()const;
	void SetDay(short day);
	void SetMonth(short month);
	void SetYear(short year);
	Dob();
	Dob(short day, short month, short year);
	~Dob();
};

