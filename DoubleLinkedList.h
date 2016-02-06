#pragma once
#include<iostream>
using namespace std;

typedef unsigned int uint;

struct Elem
{
	char* data;
	int prime;
	Elem*next;
	Elem*prev;
};


class DoubleLinkedList
{
	Elem*head;
	Elem*tail;
	int count;
public:
	DoubleLinkedList();
	~DoubleLinkedList(){ ClearList(); }
	void ClearList();
	int GetLenght(){ return count; }
	void AddData(int prime, char* data);
	void AddTail(int prime,char* data);
	void AddHead(int prime,char* data);
	void RemoveHead();
	void RemoveTail();
	void PrintList();
	Elem*GetFromHead(uint index);
	Elem*GetFromTail(uint index);
	Elem*GetElemAt(uint index);
	char* GetDataFromHead(uint index);
	char* GetDataFromTail(uint index);
	char* GetData(uint index);
};