#include<iostream>
#include<string>
using namespace std;

class Student
{
	string name;
	string fathername;
	string lastname;
	string age;
public:
	void SetName(string name)
	{
		this->name=name;
	}

	void SetFathername(string fathername)
	{
		this->fathername = fathername;
	}
	
	void SetLastame(string lastame)
	{
		this->lastname = lastame;
	}

	void SetAge(string age)
	{
		this->age = age;
	}
	Student():Student("Ivan","Ivanovich","Ivanov","18"){};
	Student(string name,string fathername,string lastame,string age)
	{
		SetName(name);
		SetFathername(fathername);
		SetLastame(lastame);
		SetAge(age);
	}

	~Student(){};
	string GetCopy(string field)
	{
		string temp = field;
		return temp;
	}
	string GetName()
	{
		return GetCopy(this->name);
	}
	string GetFathername()
	{
		return GetCopy(this->fathername);
	}
	string GetLastname()
	{
		return GetCopy(this->lastname);
	}
	string GetAge()
	{
		return GetCopy(this->age);
	}
	virtual string GetFullInfo()
	{
		string temp;
		temp = GetName() + ' ' + GetFathername() + ' ' + GetLastname()+' '+GetAge();
		return temp;
	}
};


class Aspirant :public Student
{
	string name_of_course_work;
	string professor_name;
public:
	void SetWork(string name_of_course_work)
	{
		this->name_of_course_work = name_of_course_work;
	}

	void SetProfessorName(string professor_name)
	{
		this->professor_name = professor_name;
	}
	Aspirant():Aspirant("Humanity and Earth","Seleznev"){};
	Aspirant(string name, string fathername, string lastame, string age, string name_of_course_work, string professor_name)
	{
		SetName(name);
		SetFathername(fathername);
		SetLastame(lastame);
		SetAge(age);
		SetWork(name_of_course_work);
		SetProfessorName(professor_name);
	}
	Aspirant(string name_of_course_work, string professor_name)
	{
		SetWork(name_of_course_work);
		SetProfessorName(professor_name);
	}
	~Aspirant(){};
	string GetFullInfo()
	{
		string temp;
		temp = Student::GetFullInfo() + ' ' + GetCopy(this->name_of_course_work) + ' ' + GetCopy(this->professor_name);
		return temp;
	}
};

void main()
{
	Student a("Vasiliy","Petrovich","Petrov","20");
	cout<<a.GetFullInfo()<<endl;
	Aspirant b("Deep water life", "Shpulman");
	cout << b.GetFullInfo()<<endl;
	Aspirant c("Alexey", "Nikolaevich", "Feshchuk", "25", "Deep water life", "Shpulman");
	cout << c.GetFullInfo()<<endl;

}