#include<iostream>
#include"LinkedList.h"
using namespace std;

void main()
{
	SingleLinkedList l;
	l.AddTail(35);
	l.AddTail(45);
    l.AddTail(55);
	l.PrintList();
	T arr[5] = { 1, 2, 3, 4, 5 };
	l.AddRange(arr, 5);
	l.PrintList();
	cout<<l.LastIndexOf(3)<<endl;
	cout<<l.IndexOf(36)<<endl;
	cout << l.Contains(3) << endl;
	cout << l[7]<<endl;
	SingleLinkedList k(l);
	k.PrintList();
	SingleLinkedList a;
	a.AddTail(4);
	a.AddTail(3);
	a.AddTail(2);
	a.AddTail(1);
	//a = k;
	a.PrintList();
	cout<<(a == k)<< endl;
	cout<<a.Equals(k)<< endl;
	cout << a;
	SingleLinkedList b;
	b.AddTail(6);
	b.AddTail(7);
	b.AddTail(8);
	b.AddTail(9);
	b.PrintList();
	b.Insert(99,0);
	b.PrintList();
	a.InsertRange(0, arr, 5);
	cout << a;
	a.DeleteElem(2);
	cout << a;
	a.Remove(5);
	cout << a;
	a.RemoveAll(2);
	cout << a;
	a.Reverse();
	cout << a;
	a.Sort();
	cout << a;
	T *ar=a.ToArray();
	for (int i = 0; i < a.GetCount(); i++)
		cout << arr[i] << ' ';
}