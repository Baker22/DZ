#include <iostream>
#include"MyCalc.h"
using namespace std;


void main()
{
	cout << "((11+22)*55-(33+44))/44*((55+66)*22-(88+88))/22\n\n\n";

	cout << PolNot("((11+22)*55-(33+44))/44*((55+66)*22-(88+88))/22");
	//cout << Calculate(PolNot("((1+2)*5-(3+4))/3*((5+6)*2-(7+8))/4"));

}