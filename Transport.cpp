#include<iostream>
#include<string>
using namespace std;

class Transport abstract
{
	string type;
	string brand;
	int max_speed;
	int year_of_issue;
	int max_loading;
public:
	Transport(){};
	void SetBrand(string&brand){ this->brand = brand; }
	void SetMaxSpeed(int max_speed){ this->max_speed = max_speed; }
	void SetYearOfIssue(int year_of_issue){ this->year_of_issue = year_of_issue; }
	void SetMaxLoading(int max_loading){ this->max_loading = max_loading; }
	void SetType(string&type){ this->type = type; }
	Transport(string type,string brand, int max_speed, int year_of_issue, int max_loading)
	{
		SetBrand(brand);
		SetMaxSpeed(max_speed);
		SetYearOfIssue(year_of_issue);
		SetMaxLoading(max_loading);
		SetType(type);
	}
	//virtual void move() = 0;
	virtual void GetInfo()
	{
		cout << "Type: " << type << endl;
		cout << "Brand: " << brand<<endl;
		cout << "Max Speed: " << max_speed << endl;
		cout << "Year of issue: " << year_of_issue << endl;
		cout << "Max Loading: " << max_loading << endl;
	}
		
};

class Flying:public Transport
{
	int max_fly_height;
public:
	Flying(){};
	void SetMaxHeight(int max_fly_height){ this->max_fly_height = max_fly_height; }
	Flying(string type, string brand, int max_speed, int year_of_issue, int max_loading, int max_fly_height) :Transport(type, brand, max_speed, year_of_issue, max_loading)
	{
		SetMaxHeight(max_fly_height);
	}
	void GetInfo()
	{
		Transport::GetInfo();
		cout << "Max fly height: " << max_fly_height << endl;
	}
	~Flying(){};
};


class Riding :public Transport
{
	int wheel_count;
public:
	Riding(){};
	void SetWheelCount(int wheel_count){ this->wheel_count = wheel_count; }
	Riding(string type, string brand, int max_speed, int year_of_issue, int max_loading, int wheel_count) :Transport(type, brand, max_speed, year_of_issue, max_loading)
	{
		SetWheelCount(wheel_count);
	}
	void GetInfo()
	{
		Transport::GetInfo();
		cout << wheel_count << " wheels" << endl;
	}
	~Riding(){};
};

class Floating :public Transport
{
	int crew_count;
public:
	Floating(){};
	void SetCrewCount(int crew_count){ this->crew_count = crew_count; }
	Floating(string type, string brand, int max_speed, int year_of_issue, int max_loading, int crew_count) :Transport(type, brand, max_speed, year_of_issue, max_loading)
	{
		SetCrewCount(crew_count);
	}
	void GetInfo()
	{
		Transport::GetInfo();
		cout << crew_count << " crew members" << endl;
	}
	~Floating(){};
};

class Underwater:public Floating
{
	int max_depth;
public:
	Underwater():Underwater("No info", "No info", 0, 0, 0, 0, 0){};
	void SetMaxDepth(int max_depth){ this->max_depth = max_depth; }
	Underwater(string type, string brand, int max_speed, int year_of_issue, int max_loading, int crew_count, int max_depth) :Floating(type,brand, max_speed, year_of_issue, max_loading, crew_count)
	{
		SetMaxDepth(max_depth);
	}
	void GetInfo()
	{
		Floating::GetInfo();
		cout << "Max Depth: " << max_depth << endl<<endl;
	}
	~Underwater(){};
};

class TwoWheels :public Riding
{
	string _class;
public:
	TwoWheels() :TwoWheels("No info", "No info", 0, 0, 0, 0, "No info"){};
	void SetClass(string&_class){ this->_class = _class; }
	TwoWheels(string type, string brand, int max_speed, int year_of_issue, int max_loading, int wheel_count, string _class) :Riding(type,brand,max_speed, year_of_issue, max_loading, wheel_count)
	{
		SetClass(_class);
	}
	void GetInfo()
	{
		Riding::GetInfo();
		cout << "Class: " << _class<<endl<<endl;
	}
	~TwoWheels(){};
};

class FlyByGas :public Flying
{
	int diameter;
public:
	void SetDiameter(int diameter){ this->diameter = diameter; }
	FlyByGas(string type, string brand, int max_speed, int year_of_issue, int max_loading, int max_fly_height, int diameter) :Flying(type, brand, max_speed, year_of_issue, max_loading, max_fly_height)
	{
		SetDiameter(diameter);
	}
	FlyByGas():FlyByGas("No info", "No info", 0, 0, 0, 0, 0){};
	void GetInfo()
	{
		Flying::GetInfo();
		cout << "Diameter: " << diameter << endl<<endl;
	}
	~FlyByGas(){};
};
void main()
{
	system ("title Class Transport");
	FlyByGas a("Airship", "Passenger",10,1960,1000,800,100 );
	TwoWheels b("Bike","Honda",320,2015,120,2,"sport");
	Underwater c("Submarine","U-110",25,1940,1000,20,1200);
	FlyByGas d;
	TwoWheels e;
	Underwater f;
	a.GetInfo();
	b.GetInfo();
	c.GetInfo();
	d.GetInfo();
	e.GetInfo();
	f.GetInfo();
}
