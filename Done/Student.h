#pragma once
#include<string.h>
#include <iostream>
#include"Dob.h"
#include"Adress.h"
using namespace std;
typedef unsigned short ushort;


class Student
{
	char*phone;
	char*name;
	char*secondname;
	char*lastname;
	Dob birthday;
	ushort*exams;
	ushort*courses;
	ushort*tests;
	ushort examsSize=0;
	ushort coursesSize=0;
	ushort testsSize=0;
public:
	char *GetPhone()const;
	char *GetName()const;
	char *GetSecondname()const;
	char *GetLastname()const;
	char*Get1Exam(ushort index);
	char* GetExams();
	char* GetBirthday();
	char*FullName();
	Student BasicStudent();
	void SetPhone(char* phone);
	void SetName(char*name);
	void SetSecondname(char*secondname);
	void SetLastname(char*lastname);
	void SetBirthday(Dob birthday);
	void SetSomeGrade(ushort*&arr, ushort &size, ushort grade);
	void SetExam(ushort grade);
	void SetCourse(ushort grade);
	void SetTest(ushort grade);

	Student();
	Student(char* phone,char*name,char*secondname,char*lastname);
	~Student();
};

