#include "Adress.h"


Adress::Adress() :Adress(nullptr,nullptr,nullptr)
{
	throw "need some adress";
}


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
