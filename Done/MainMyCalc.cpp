#include <iostream>
#include"MyCalc.h"
using namespace std;


void main()
{
	MyCalc a("((10.38+20)*55-(30+40))/44*((55+60)*22-(88+88))/2");
	cout <<a.PolNot()<<endl;
	MyCalc b("3.5+2*5");
	cout <<b.PolNot()<<endl;
	MyCalc c("(3+2)*5");
	cout <<c.PolNot()<<endl;
	MyCalc d("(3+4*(5-2)-1)/2");
	cout <<d.PolNot()<<endl;
	MyCalc e("(3+2)/5 + (3+4*(5-2)-1)/2");
	cout << e.PolNot() << endl;
	MyCalc f("16.8 / ((3+2)/5 + (3+4*(5-2)-1)/2)");
	cout << f.PolNot() << endl;
	MyCalc j("(64/32)+78-(20/4)+(2*(11-6))+45+2/2");
	cout << j.PolNot() << endl;
	MyCalc k("(3+5)^2-60-2^3");
	cout << k.PolNot() << endl;
	MyCalc l("((3+2)/5 + (3+4*(5-2)-1)/2)^0.5");
	cout << l.PolNot() << endl;
}