#include<iostream>
#include"Date.h"
#include"Time.h"
using namespace std;

void main()
{
	Time aa(5,56,32);
	Time bb(3, 34, 0);
	aa.PlusTime(bb);
	Date a(1, 1, 1501);
	Date b(21, 1, 1985);
	cout << a.PrintDate()<<endl;
	cout << b.PrintDate()<<endl;
	cout << a.operator-(b)<<endl;
	cout << "-------------------------\n";
	cout << a.PrintDate()<<endl;
	Date c = a.operator++();
	cout << c.PrintDate()<<endl;
	cout << "-------------------------\n";
	Date d = a.operator--();
	cout << d.PrintDate() << endl;
	cout << "-------------------------\n";
	Date j(10, 12, 3);
	cout << b.PrintDate()<<endl;
	cout << j.PrintDate() << endl;
	b.operator-=(j);
	cout << b.PrintDate()<<endl;
	cout << "-------------------------\n";
	cout << c.PrintDate() << endl;
    cout << j.PrintDate() << endl;
	c.operator+=(j);
	cout << c.PrintDate()<<endl;
	cout << "-------------------------\n";
	cout << a.PrintDate()<<endl;
	a - 500;
	cout << a.PrintDate()<<endl;
	cout << "-------------------------\n";
	a + 100;
	Date k(21, 1, 1980);
	cout << k.PrintDate()<<endl;
	cout << "-------------------------\n";
	cout << k.DayOfWeek();
    cout << "-------------------------\n";
	cout<<aa.ShowTime()<<endl;
	cout<<bb.ShowTime()<<endl;
	cout << "-------------------------\n";
	cout << aa.operator>(bb)<<endl;
	cout << aa.operator<(bb)<<endl;
	cout << aa.operator==(bb)<<endl;
}