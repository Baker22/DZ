#pragma once
#include<iostream>
using namespace std;
class Adress
{
	char*home;
	char*street;
	char*city;
public:
	char*GetHome()const;
	char*GetStreet()const;
	char*GetCity()const;
	void SetHome(char*home);
	void SetStreet(char*street);
	void SetCity(char*city);
	Adress();
	Adress(char*home);
	Adress(char*home,char*street);
	Adress(char*home, char*street, char*city);

	~Adress();
};

