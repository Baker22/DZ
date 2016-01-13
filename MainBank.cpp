#include<iostream>
#include"Bank.h"
using namespace std;

void main()
{
	Bank a;
	a.SetPersent(18);
	cout << Bank::GetMainBall() << endl;
	a.SetFilBall(98);
	cout << "Ballanse= " << a.GetMainBall() << endl;
	a.SetFilBall(98);
	cout << "Ballanse= " << a.GetMainBall() << endl;
	a.SetFilBall(98);
	cout << "Ballanse= " << a.GetMainBall() << endl;
	a.FormDeposit(100);
	a.FormDeposit(250);
	a.FormDeposit(260);
	cout << "Ballanse= " << a.GetMainBall() << endl;
	a.FormCredit(150);
	a.FormCredit(200);
	cout << "GetBackDeposit" << a.issueDeposit(120) << endl;
	cout << "GetBackDeposit" << a.issueDeposit(250) << endl;
	cout << "GetBackDeposit" << a.issueDeposit(260) << endl;
	cout << "Ballanse= " << a.GetMainBall() << endl;
	a.issueCredit(150, 50);
	cout << "Ballanse= " << a.GetMainBall() << endl;
	a.issueCredit(150, 120);
	cout << a.issueCredit(150, 100) << endl;
	cout << a.issueCredit(150, 100) << endl;
	a.issueCredit(150, 100);
	cout << "Ballanse= " << a.GetMainBall() << endl;

}