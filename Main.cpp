#include<iostream>
#include"Bank.h"
#include"Student.h"
#include"Dob.h"
#include"Adress.h"

using namespace std;

void ShowStud(Student & student,Dob & date,Adress & adress)
{
	cout << "Student: " <<student.GetName() << ","<<student.GetSecondname()<<","<<student.GetLastname()<<"."<<endl;
	cout << "Was Born: " << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear() <<"."<< endl;
	cout << "Tel.: " << student.GetPhone() << "." << endl;
	cout << "Adress: " << adress.GetCity() << "," << adress.GetStreet() << "," << adress.GetHome() << "." << endl;
}

void main()
{
	
	Adress aaa;
	Dob aa;
	Student a;
	a.SetName("Alexey");
	a.SetSecondname("Nickolaevich");
	a.SetLastname("Feshchuk");
	ShowStud(a,aa,aaa);
	a.SetExam(10);
	a.SetExam(9);
	a.SetExam(8);
	cout<<a.GetExams();
}