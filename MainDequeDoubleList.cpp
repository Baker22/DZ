#include<iostream>
#include"Deque.cpp"
#include"DoubleLinkedList.h"

using namespace std;


void main()
{
	DoubleLinkedList d;
	d.AddHead(1,"one");
	d.AddHead(2,"two");
	d.AddHead(3,"three");
	d.AddTail(4,"four");
	d.AddTail(5,"five");
	d.AddTail(6,"six");
	d.PrintList();
	cout<<d.GetElemAt(5)<<endl;
	DoubleLinkedList a;
	a.AddData(5,"five");
	a.AddData(6, "six");
	a.AddData(2, "two");
	a.AddData(4, "four");
	a.AddData(1, "one");
	a.AddData(3, "three");
	a.PrintList();
	Deque q;
	q.PushByPriority(13,"CORRECT");
	q.PushByPriority(10,"HOPE");
	q.PushByPriority(11,"IT");
	q.PushByPriority(9,"I");
	q.PushByPriority(12,"IS");
	q.PrintDeque();
}