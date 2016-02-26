#include<iostream>
#include<string>
using namespace std;

class Transport abstract
{
public:
	virtual void move() = 0;
};

class Flying:public Transport
{
	string body;
public:
	Flying(string body)
	{
		this->body = body;
	}
	void move()
	{
		cout <<"The "<< body << " is flying." << endl;
	}
	~Flying(){};
};

class Riding :public Transport
{
	string body;
public:
	Riding(string body)
	{
		this->body = body;
	}
	void move()
	{
		cout <<"The "<< body << " is riding." << endl;
	}
	~Riding(){};
};

class Floating :public Transport
{
	string body;
public:
	Floating(string body)
	{
		this->body = body;
	}
	void move()
	{
		cout <<"The "<< body << " is floating." << endl;
	}
	~Floating(){};
};

void main()
{
	Flying a("airplane");
	Riding c("car");
	Floating b("boat");
	a.move();
	c.move();
	b.move();
}
