#pragma once
#include <iostream>
#include"Dob.h"
#include"Adress.h"
using namespace std;

class Adress;
class Dob;
class Student
{
	char*phone;
	char*name;
	char*secondname;
	char*lastname;
	Dob birthday;
public:
	char *GetPhone()const;
	char *GetName()const;
	char *GetSecondname()const;
	char *GetLastname()const;
	Dob & GetBirthday(){ return this->birthday; }
	void SetPhone(char* phone);
	void SetName(char*name);
	void SetSecondname(char*secondname);
	void SetLastname(char*lastname);
	void SetBirthday(Dob & birthday);
	Student();
	Student(char* phone,char*name,char*secondname,char*lastname);
	~Student();
};

