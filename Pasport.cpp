#include<iostream>
#include<string>
using namespace std;

class Pasport
{
	string name;
	string fathername;
	string lastname;
	string gender;
	string DOB;
	string pasport_number;
	string nationality;
	bool conviction;
public:
	void SetName(string name)
	{
		this->name = name;
	}

	void SetFathername(string fathername)
	{
		this->fathername = fathername;
	}

	void SetLastame(string lastame)
	{
		this->lastname = lastame;
	}
	
	void SetGender(string gender)
	{
		this->gender = gender;
	}
	
	void SetDOB(string DOB)
	{
		this->DOB = DOB;
	}

	void SetPasportNumber(string number)
	{
		this->pasport_number = number;
	}

	void SetNationality(string nationality)
	{
		this->nationality = nationality;
	}

	void SetConviction(bool conviction)
	{
		this->conviction = conviction;
	}
	Pasport() :Pasport("Ivan", "Ivanovich", "Ivanov", "male","20,09,1985","387456","Ukrainian",false){};
	Pasport(string name, string fathername, string lastame, string gender, string DOB,
		string pasport_number, string nationality,bool conviction)
	{
		SetName(name);
		SetFathername(fathername);
		SetLastame(lastame);
		SetGender(gender);
		SetDOB(DOB);
		SetPasportNumber(pasport_number);
		SetNationality(nationality);
		SetConviction(conviction);
	}

	~Pasport(){};
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
	string GetGender()
	{
		return GetCopy(this->gender);
	}
	string GetDOB()
	{
		return GetCopy(this->DOB);
	}
	string GetPasportNumber()
	{
		return GetCopy(this->pasport_number);
	}
	string GetNationality()
	{
		return GetCopy(this->nationality);
	}
	bool GetConviction()
	{
		return conviction;
	}
	virtual string GetFullInfo()
	{
		string temp;
		temp = GetName() + ' ' + GetFathername() + ' ' + GetLastname() + ' ' + GetGender() +
			GetDOB() + ' ' + GetPasportNumber() + ' ' + GetNationality()+' '+((GetConviction()==true)?"convicted":"not convicted")+'\n';
		return temp;
	}
};


class InternationalPasport :public Pasport
{
	bool shengen;
public:
	void SetShengen()
	{
		this->shengen=(!GetConviction());
	}

	bool GetShengen()
	{
		return shengen;
	}
	InternationalPasport(){};
	InternationalPasport(string name, string fathername, string lastame, string gender, string DOB,
		string pasport_number, string nationality, bool conviction)
	{
		SetName(name);
		SetFathername(fathername);
		SetLastame(lastame);
		SetGender(gender);
		SetDOB(DOB);
		SetPasportNumber(pasport_number);
		SetNationality(nationality);
		SetConviction(conviction);
		SetShengen();
	}
	~InternationalPasport(){};
	string GetFullInfo()
	{
		string temp;
		temp = Pasport::GetFullInfo() + ' ' + ((GetShengen() == true) ? "Visa granted" : " Visa not granted")+ '\n' ;
		return temp;
	}
};

void main()
{
	Pasport a("Vasiliy", "Ivanovich", "Tatarin", "male", "01,02,1980", "396856", "Ukrainian", true);
	cout << a.GetFullInfo() << endl;
	InternationalPasport b;
	cout << b.GetFullInfo() << endl;
	InternationalPasport c("Alexey", "Nikolaevich", "Feshchuk", "male", "22.10.1981", "0101010","Ukrainian",false);
	cout << c.GetFullInfo() << endl;

}