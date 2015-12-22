#pragma once
#include <iostream>
#include"dob.h"
using namespace std;

class dob;
class Student
{
	char*name;
	char*secondname;
	char*lastname;
	dob date;
public:
	char *GetName()const;
	char *GetSecondname()const;
	char *GetLastname()const;
	dob GetDate()const;

	void SetName(char*name);
	void SetSecondname(char*secondname);
	void SetLastname(char*lastname);
	void SetDate(dob date);
	Student();//:Student ("Ivan", "Ivanovich", "Ivanov",this->date){};
	Student(char*name,char*secondname,char*lastname, dob date);
	void ShowInfo();
	~Student();
};

