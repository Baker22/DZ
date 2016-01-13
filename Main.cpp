#include<iostream>
#include"Bank.h"
#include"Student.h"
#include"Dob.h"
#include"Adress.h"
#include"Group.h"

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
	
	/*Adress aaa;
	Dob aa(22,10,1981);
	Student a;
	a.SetBirthday(aa);
	a.SetName("Alexey");
	a.SetSecondname("Nickolaevich");
	a.SetLastname("Feshchuk");
	ShowStud(a,aa,aaa);
	a.SetExam(10);
	a.SetExam(9);
	a.SetExam(8);
	cout<<a.GetExams()<<endl;
	
	Group x("VPD","Programmers","1511");
	cout << x.GetGroup_name()<<x.GetGroup_spec()<<x.GetCourse_num()<<endl;
	//cout << x.GroupList();
	cout << x.StudentsInfo();
	cout << aa.ShowDob();
	cout << a.GetBirthday();
	cout << a.FullName()<<endl;*/
	Group y(7);
	cout << y.GroupList();
}