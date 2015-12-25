#include<iostream>
#include"Student.h"
#include"Dob.h"
#include"Adress.h"
using namespace std;

void ShowStud(Student & student,Dob & date)
{
	cout << "Student: " << student.GetName() << ","<<student.GetSecondname()<<","<<student.GetLastname()<<"."<<endl;
	cout << "Was Born: " << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear() <<"."<< endl;
	cout << "Tel.: " << student.GetPhone() << "." << endl;
}

void main()
{
	Dob aa;
	Student a;
	a.SetName("Alexey");
	a.SetSecondname("Nickolaevich");
	a.SetLastname("Feshchuk");
	ShowStud(a,aa);
	//aa.SetDay(35);
	//cout << aa.GetDay()<<endl;
	//cout << aa.GetMonth()<<endl;
}