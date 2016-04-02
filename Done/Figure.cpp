#include<iostream>
#include<Windows.h>
#include<math.h>
using namespace std;

static double Pi = 3.14;
class Figure abstract
{
public:
	Figure(){};
	virtual double yardage() = 0;
	virtual double perimeter() = 0;
	virtual void draw() = 0;
	~Figure(){};
};

class Point :public Figure
{
	int x;
	int y;
public:
	Point():Point(0, 0) {};
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	double yardage(){ return 0; }
	double perimeter(){ return 0; }
	void draw()
	{
		cout << "." << endl;
	}
};

class Line : public Figure
{
	Point x;
	Point y;
public:
	Line(){};
	Line(Point x, Point y)
	{
		this->x = x;
		this->y = y;
	}
	double yardage(){ return 0; }
	double perimeter(){ return 0; }
	void draw()
	{
		cout << "Point x----------------Point y" << endl;
	}
};


class Elips : public Figure
{
	Point A;
	int width;
	int height;
public:
	Elips(){};
	Elips(Point A,int width,int height)
	{
		this->A = A;
		this->width = width;
		this->height = height;
	}
	double yardage()
	{
		return (width / 2)*(height/2)*Pi;
	}
	double perimeter()
	{
		return (width / 2+height/2) * Pi;
	}
	void draw()
	{
		cout << "Draw a Elipse" << endl;
	}
};

class Manyangle abstract:public Figure
{
	Point A;
public:
	Manyangle(){};
	virtual double yardage() = 0;
	virtual double perimeter() = 0;
	virtual void draw() = 0;
	Manyangle(Point A){ this->A = A; }
	~Manyangle(){};
};

class Circle :public Elips
{
	double radius;
public:
	Circle(){};
	Circle(Point A, int radius) :Elips(A, radius / 2, radius / 2){};
	double yardage()
	{
		return (radius*radius)*Pi;
	}
	double perimeter()
	{
		return 2 * radius*Pi;
	}
	void draw()
	{
		cout << "Draw a Circle" << endl;
	}
};

class Triangle :public Manyangle
{
	Point B;
	Point C;
public:
	Triangle(){};
	Triangle(Point A, Point B, Point C)
	{
		this->B = B;
		this->C = C;
	}
	virtual double yardage()
	{
		double AB;
		double BC;
		double AC;
		double P = perimeter();
		double S;
		S = sqrt(P*(P - AB)*(P - BC)*(P - AC));
		return S;
	}
	virtual double perimeter()
	{
		double AB;
		double BC;
		double AC;
		double P;
		P= (AB + BC + AC) / 2;
		return P;
	}
	virtual void draw()
	{
		cout << "Draw a Triangle" << endl;
	}
	~Triangle(){};
};

class Tetragon :public Manyangle
{

};

class UsualOxygon :public Triangle
{
public:
	UsualOxygon(){}; 
	UsualOxygon(Point A,Point B,Point C): Triangle(A, B, C){};
	double yardage(){};
	double perimeter(){};
	virtual void draw()
	{
		cout << "Draw a Triangle" << endl;
	}
	~UsualOxygon(){};
};

class IsoscelesOxygon :public Triangle
{
public:
	IsoscelesOxygon(){};
	IsoscelesOxygon(Point A, Point B, Point C) : Triangle(A, B, C){};
	double yardage()
	{
	Triangle:yardage();
	}
	double perimeter()
	{
	Triangle:perimeter();
	}
	~IsoscelesOxygon(){};
};

class UsualObtuseTriangle : public Triangle
{

};

class IsoscelesObtuseTriangle : public Triangle
{

};

class UsualRightTriangle : public Triangle
{

};

class IsoscelesRightTriangle : public Triangle
{

};

class Parallelogram : public Tetragon
{

};

class Trapeze : public Tetragon
{

};

class Deltoid : public Tetragon
{

};

class Rectangle : public Parallelogram
{

};

class Rhombus : public Parallelogram
{

};

class Square : public Rectangle
{

};

class CircleInSquare:public Square, public Circle
{

};

void main()
{

}