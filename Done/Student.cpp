#include "Student.h"
#include"Dob.h"
#include"Adress.h"
#include<string.h>


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

char*Student::FullName()
{
	char *temp = new char[250];
	strcpy_s(temp, strlen(GetName()) + 1, GetName());
	strcat_s(temp, 250, " ");
	strcat_s(temp, 250, GetSecondname());
	strcat_s(temp, 250, " ");
	strcat_s(temp, 250, GetLastname());
	strcat_s(temp, 250, " ");
	char*res = new char[strlen(temp) + 1];
	strcpy_s(res, strlen(temp) + 1, temp);
	return res;
}
char* Student::GetExams()
{
	
	char*res = new char[250];
	char *temp=new char[3];
	int lenght=0;
	strcpy_s(res, 7, "Exams:");
	for (int i =0;i<examsSize; i++)
	{
		_itoa_s(exams[i],temp, 3, 10);
		strcat_s(res,250,temp);
		strcat_s(res,250,",");

	}	
	
	return res;
}

char*Student::Get1Exam(ushort index)
{
	char*temp = new char[3];
	_itoa_s(exams[index-1],temp,3,10);
	char*res = new char[strlen(temp) + 1];
	strcpy_s(res, strlen(temp) + 1, temp);
	return res;
}
void Student::SetPhone(char* phone)
{
		if (this->phone)
		delete[]this->phone;
		this->phone = nullptr;
		this->phone = new char[strlen(phone)+1];
		strcpy_s(this->phone, (strlen(phone) + 1), phone);
}
void Student::SetName(char*name)
{
	if (this->name)
	delete[]this->name;
	this->name = nullptr;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, (strlen(name) + 1), name);
}

void Student::SetSecondname(char*secondname)
{
	if (this->secondname)
	delete[]this->secondname;
	this->secondname = nullptr;
	this->secondname = new char[strlen(secondname) + 1];
	strcpy_s(this->secondname, (strlen(secondname) + 1), secondname);
}

void Student::SetLastname(char*lastname)
{
	if (this->lastname)
	delete[]this->lastname;
	this->lastname = nullptr;
	this->lastname = new char[strlen(lastname) + 1];
	strcpy_s(this->lastname, (strlen(lastname) + 1), lastname);
}

void Student::SetBirthday(Dob birthday)
{
	this->birthday = birthday;
}

void Student::SetSomeGrade(ushort*&arr, ushort &size, ushort grade)
{
	ushort*temp = new ushort[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	temp[size] = grade;
	delete[]arr;
	arr = temp;
	size++;
}
void Student::SetExam(ushort grade)
{
	SetSomeGrade(exams,examsSize,grade);
}
void Student::SetCourse(ushort grade)
{
	SetSomeGrade(courses, coursesSize, grade);
}
void Student::SetTest(ushort grade)
{
	SetSomeGrade(tests, testsSize, grade);
}

char*Student:: GetBirthday()
{
	return birthday.ShowDob();
}

Student Student::BasicStudent()
{
	Student x;
	x.phone = "No phone";
	x.name = "No name";
	x.secondname = "No secondname";
	x.lastname = "No lastname";
	return x;
}


