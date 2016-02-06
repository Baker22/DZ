#include<iostream>
#include"DoubleLinkedList.h"
using namespace std;

class Deque
{
	DoubleLinkedList d;
	uint counter = 0;
public:
	Deque()
	{
		counter = 0;
	}

	~Deque()
	{
		Clear();
	}

	bool IsEmpty()
	{
		return counter == 0;
	}

	void Clear()
	{
		if (!IsEmpty())
		{
		d.ClearList();
		counter = 0;
		}	
	}

	void PushBack(int prime, char* data)
	{
		d.AddTail(prime,data);
		counter++;
	}

	void PushFront(int prime, char* data)
	{
		d.AddHead(prime, data);
		counter++;
	}

	void PushByPriority(int prime, char* data)
	{
		d.AddData(prime, data);
	}

	void PopBack()
	{
		if (!IsEmpty())
		{
		d.GetDataFromTail(counter);
		d.RemoveTail();
		counter--;
		}
		
	}

	void PopFront()
	{
		if (!IsEmpty())
		{
		d.GetDataFromHead(0);
		d.RemoveHead();
		counter--;
		}
		
	}

	void PrintDeque()
	{
		d.PrintList();
	}
};
