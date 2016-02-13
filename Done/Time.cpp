#include"Time.h"

void Time::SetHour(uint hour)
{
	if (hour <24)
		this->hour = hour;
}
void Time::SetMin(uint min)
{
	if (min < 60)
		this->min = min;
}
void Time::SetSec(uint sec)
{
	if (sec < 60)
		this->sec = sec;
}

Time::Time() :Time(0, 0, 0){};
Time::Time(uint hour, uint min, uint sec)
{
	SetHour(hour);
	SetMin(min);
	SetSec(sec);
}

void Time::PlusTime(Time some)
{
	operator+(some);
}

void Time::MinusTime(Time some)
{
	operator-(some);
}

char*Time::ShowTime()
{
	char*res = new char[8];
	char*temp = new char[3];
	_itoa_s(this->hour, temp, 3, 10);
	strcpy_s(res,3,temp);
	strcat_s(res, 8, ":");
	_itoa_s(this->min, temp, 3, 10);
	strcat_s(res, 8, temp);
	strcat_s(res, 8, ":");
	_itoa_s(this->sec, temp,3, 10);
	strcat_s(res, 8, temp);
	return res;
}

void Time:: operator++()
{
	Time x;
	x.sec =1;
	x.min = 0;
	x.hour = 0;
	operator+(x);
}

void Time:: operator--()
{
	Time x;
	x.sec =1;
	x.min = 0;
	x.hour = 0;
	operator-(x);

}

Time Time::operator-(Time some)
{
	Time x;
	x.sec = 0;
	x.min = 0;
	x.hour = 0;
	if (this->sec >= some.sec)
		x.sec += this->sec - some.sec;
	else 
	{
		if ((this->min - 1)>= some.min)
		{
		    x.sec += (this->sec + 60 - some.sec);
		    x.min += this->min - 1 - some.min;
		}	
		else
		{
			if ((this->hour -1)>= some.hour)
			{
				x.sec += (this->sec + 60 - some.sec);
		        x.min += (this->min + 60 - some.min);
				x.hour += (this->hour - 1 - some.hour);
			}
			else
			{
				x.sec += (this->sec + 60 - some.sec);
		        x.min += (this->min +60 - some.min);
				x.hour += (this->hour + 23 - some.hour);

			}
		}
	}
	if (this->min >= some.min)
		x.min += this->min - some.min;
	else
	{
		if ((this->hour -1)>= some.hour)
			{
		        x.min += (this->min +60 - some.min);
				x.hour += (this->hour - 1 - some.hour);
			}
		else
			{
		        x.min += (this->min +60 - some.min);
				x.hour += (this->hour + 23 - some.hour);
			}
	}
	return x;
}

Time Time::operator+(Time some)
{
	Time x;
    uint s = this->sec + some.sec;
	uint m = this->min + some.min+s/60;
	uint h = this->hour + some.hour+m/60;
	this->sec = s % 60;
	this->min = m % 60;
	this->hour = h;
	x.sec = s;
	x.min = m;
	x.hour = h%24;
	return x;
}

uint Time::TimeInSeconds()
{
	uint res = this->sec+((this->min+this->hour*60)*60);
	return res;
}

bool Time::operator>(Time some)
{
	if (this->hour == some.hour&&this->min == some.min&&this->sec == some.sec)
		return false;
	if (this->TimeInSeconds() > some.TimeInSeconds())
		return true;
	return false;
}
bool Time::operator<(Time some)
{
	if (this->hour == some.hour&&this->min == some.min&&this->sec == some.sec)
		return false;
	if (this->TimeInSeconds() < some.TimeInSeconds())
		return true;
	return false;
}
bool Time::operator==(Time some)
{
    if (this->hour == some.hour&&this->min == some.min&&this->sec == some.sec)
		return true;
	return false;
}