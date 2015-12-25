#include "Student.h"
#include"Dob.h"
#include"Adress.h"

class Adress;
class dob;
Student::Student(char* phone,char*name,char*secondname,char*lastname)
{
	SetPhone(phone);
	SetName(name);
	SetSecondname(secondname);
	SetLastname(lastname);
}

Student::Student() :Student("0934229968","ivan", "ivanovich", "ivanov"){};

Student::~Student()
{
	if (phone)
	{
		delete[]phone;
		phone = nullptr;
	}
	if (name)
	{
		delete[]name;
	name = nullptr;
	}
	if (secondname)
	{
		delete[]secondname;
	secondname = nullptr;
	}
	if (lastname)
	{
		delete[]lastname;
		lastname = nullptr;
	}
	
}

char* Student :: GetPhone()const
{ 
	unsigned int lenght = strlen(this->phone) + 1;
	char*copyPhone = new char[lenght];
	strcpy_s(copyPhone, lenght, this->phone);
	return copyPhone; 
}

char* Student::GetName()const
{
	unsigned int lenght = strlen(this->name) + 1;
	char*copyName = new char[lenght];
	strcpy_s(copyName, (strlen(this->name)+1), this->name);
		return copyName;
}

char* Student::GetSecondname()const
{
    unsigned int lenght = strlen(this->secondname) + 1;
	char*copySecondname = new char[lenght];
	strcpy_s(copySecondname,lenght, this->secondname);
		return copySecondname;
}

char* Student::GetLastname()const
{
	unsigned int lenght = strlen(this->lastname) + 1;
	char*copyLastname = new char[lenght];
	strcpy_s(copyLastname,lenght, this->lastname);
		return lastname;
}

void Student::SetPhone(char* phone)
{
	if (phone > 0)
	{
		if (this->phone)
		{
			delete[]this->phone;
			this->phone = nullptr;
		}
		this->phone = phone;
	}
		
}
void Student::SetName(char*name)
{
	if (this->name);
	delete[]this->name;
	this->name = nullptr;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, (strlen(name) + 1), name);
}

void Student::SetSecondname(char*secondname)
{
	if (this->secondname);
	delete[]this->secondname;
	this->secondname = nullptr;
	this->secondname = new char[strlen(secondname) + 1];
	strcpy_s(this->secondname, (strlen(secondname) + 1), secondname);
}

void Student::SetLastname(char*lastname)
{
	if (this->lastname);
	delete[]this->lastname;
	this->lastname = nullptr;
	this->lastname = new char[strlen(lastname) + 1];
	strcpy_s(this->lastname, (strlen(lastname) + 1), lastname);
}

void Student::SetBirthday(Dob & birthday)
{
	this->birthday = birthday;
}

