#include<iostream>
using namespace std;

typedef unsigned int uint;

class Time
{
	uint hour;
	uint min;
	uint sec;
public:
	uint GetHour()const{ return hour; }
	uint GetMin()const{ return min; }
	uint GetSec()const{ return sec; }

	void SetHour(uint hour);
	void SetMin(uint min);
	void SetSec(uint sec);

	Time();
	Time(uint hour, uint min, uint sec);
	~Time(){}
	void PlusTime(Time some);
	void MinusTime(Time some);
	char*ShowTime();
	void operator++();
	void operator--();
	Time operator-(Time some);
	Time operator+(Time some);
	bool operator>(Time some);
	bool operator<(Time some);
	bool operator==(Time some);
	uint TimeInSeconds();
};