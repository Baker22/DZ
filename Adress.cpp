#include "Adress.h"


Adress::Adress() :Adress(nullptr,nullptr,nullptr)
{
}

Adress::Adress(char*home, char*street, char*city)
{
SetHome(home);
SetStreet(street);
SetCity(city);
}

Adress::Adress(char*home, char*street) :Adress(home, street, nullptr){};
Adress::Adress(char*home) :Adress(home, nullptr, nullptr){};
Adress::~Adress()
{
	if (home)
	{
		delete[]home;
	home = nullptr;
	}
	if (street)
	{
		delete[]street;
	street = nullptr;
	}
	if (city)
	{
		delete[]city;
		city = nullptr;
	}
}
char*Adress::GetHome()const
	{
	if (home == nullptr)
		return "no info";
		int leng = strlen(home) + 1;
		char *copyHome = new char[leng];
		strcpy_s(copyHome, leng, home);
		return copyHome;
	}
char*Adress::GetStreet()const
{
	if (street == nullptr)
		return "no info";
	int leng = strlen(street) + 1;
	char *copyStreet = new char[leng];
	strcpy_s(copyStreet, leng, street);
	return copyStreet;
}
char*Adress::GetCity()const
{
	if (city == nullptr)
		return "no info";
	int leng = strlen(city) + 1;
	char *copyCity = new char[leng];
	strcpy_s(copyCity, leng, city);
	return copyCity;
}

void Adress::SetHome(char*home)
{
	if (this->home)
	{
		delete[]this->home;
		this->home = nullptr;
	}
	this->home = home;
}
void Adress::SetStreet(char*street)
{
	if (this->street)
	{
		delete[]this->street;
		this->street = nullptr;
	}
	this->street = street;
}
void Adress::SetCity(char*city)
{
	if (this->city)
	{
		delete[]this->city;
		this->city = nullptr;
	}
	this->city = city;
}