#include "Student.h"
#include"dob.h"

Student::Student(char*name,char*secondname,char*lastname, dob date)
{
	SetName(name);
	SetSecondname(secondname);
	SetLastname(lastname);
	SetDate(date);
}

Student::Student()
{
	char*name = "ivan";
	char*secondname = "ivanovich";
	char*lastname = "ivanov";
	dob date = date;
}

Student::~Student()
{
}

char* Student::GetName()const
{
	char*copyName = new char[strlen(this->name) + 1];
	strcpy_s(copyName, (strlen(this->name)+1), this->name);
		return copyName;
}

char* Student::GetSecondname()const
{
	char*copySecondname = new char[strlen(this->secondname) + 1];
	strcpy_s(copySecondname, (strlen(this->secondname)+1), this->secondname);
		return copySecondname;
}

char* Student::GetLastname()const
{
	char*copyLastname = new char[strlen(this->lastname) + 1];
	strcpy_s(copyLastname, (strlen(this->lastname)+1), this->lastname);
		return lastname;
}

/*dob Student::GetDate()const
{

}*/
void Student::SetName(char*name)
{
	if (!this->name)return;
		delete[]this->name;
		this->name = nullptr;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, (strlen(name) + 1), name);
}
void Student::SetSecondname(char*secondname)
{
	if (!this->secondname)return;
	delete[]this->secondname;
		this->secondname = nullptr;
	this->secondname = new char[strlen(secondname) + 1];
	strcpy_s(this->secondname, (strlen(secondname) + 1), secondname);
}
void Student::SetLastname(char*lastname)
{
	if (!this->lastname)return;
	delete[]this->lastname;
		this->lastname = nullptr;
	this->lastname = new char[strlen(lastname) + 1];
	strcpy_s(this->name, (strlen(lastname) + 1), lastname);
}
void Student::SetDate(dob date)
{
	this->date = date;
}
