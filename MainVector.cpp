#include<iostream>
#include"Vector.h"
using namespace std;

void main()
{
	srand(time(0));
	Vector a;
	a.FillArr();
	cout << a<<endl;
	a.RemoveValue();
	cout << a.ShowVect()<<endl;
	//a.ClearArr();
	cout<<a.IndexOf(30)<<endl;
	cout << a.LastIndexOf(63) << endl;
	a.Insert(16, 55);
	cout << a.ShowVect()<<"add 55"<<endl;
	a.InsertPlus(21, 333);
	cout << a.ShowVect()<<"add 333 without del"<<endl;
	a.RemoveAt(0);
	cout << a.ShowVect()<<"del index 0"<<endl;
	a.Reverse();
	cout << a.ShowVect()<<"after reverse"<<endl;
	a.Sort();
	cout << a.ShowVect()<<"after sort"<<endl;
	a.Shuffle();
	cout << a.ShowVect()<<"after shuffle"<<endl;
	Vector b = a;
	cout << b.ShowVect()<<"copy"<<endl;
	cout << a.operator==(b)<<"bool =="<<endl;
	a.operator()(8);
	cout << a.ShowVect()<<"set capacity 8"<<endl;
	b.SetCapacity(5);
	cout << b.ShowVect()<<"set capacity 5"<<endl;
	cout<<b.operator[](4)<<"show element by index 4"<<endl;
	a.operator+(b);
	cout << a<<"summ of arrays"<<endl;
	a.SetCapacity(6);
	cout << a<<"capacity=6"<<endl;
    cin >> a;
	cout << a<<"overload \">>\" done!!!!!!!\n";
}