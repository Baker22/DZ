#include"DoubleLinkedList.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
	head = tail = nullptr;
	count = 0;
}

void DoubleLinkedList::ClearList()
{
	while (head != nullptr)
		RemoveHead();
}

void DoubleLinkedList::AddData(int prime, char* data)
{
	if (count==0 ||prime >= tail->prime)
		AddTail(prime, data);
	else if (prime<=head->prime)
		AddHead(prime, data);
	else
	{
	Elem*_new = new Elem;
	Elem*temp = new Elem;
	_new->data = data;
	_new->prime = prime;
	temp = head;
	while (temp->next->prime<=_new->prime)
		temp = temp->next;
		_new->next = temp->next;
		_new->prev = temp;
		temp->next = _new;
		count++;		
	}
}

void DoubleLinkedList::AddTail(int prime, char* data)
{
	Elem*temp = new Elem;
	temp->data = data;
	temp->prime = prime;
	temp->next = nullptr;
	if (head==nullptr)
	{
	temp->prev=nullptr;
	head = tail = temp;
	}

	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	count++;
}

void DoubleLinkedList::AddHead(int prime, char* data)
{
	Elem*temp = new Elem;
	temp->data = data;
	temp->prime = prime;
	if (head == nullptr)
	{
	temp->next = nullptr;
	temp->prev = nullptr;
	head = tail = temp;
	}
	else
	{
	temp->next = head;
	head->prev = temp;
	head =temp ;
	}
	
	count++;
}

void DoubleLinkedList::RemoveHead()
{
	Elem*temp = new Elem;
	temp = head;
	head= head->next ;
	delete[]temp;
	if(head)
	head->prev = nullptr;
	count--;
}

void DoubleLinkedList::RemoveTail()
{
	Elem*temp = new Elem;
	tail = tail->prev;
	tail->next = nullptr;
	delete[]temp;
	count--;
}

void DoubleLinkedList::PrintList()
{
	Elem*temp = new Elem;
	temp = head;
	while (temp)
	{
	cout <<"priority ("<<temp->prime<<") "<< temp->data<<endl;
	temp = temp->next;
	}
	delete[]temp;
}

Elem*DoubleLinkedList::GetFromHead(uint index)
{
	Elem*temp = new Elem;
	temp = head;
	for (uint i = 0; i < count;i++)
	{
		if (i == index)
			return temp;
		temp = temp->next;
	}
}

Elem*DoubleLinkedList::GetFromTail(uint index)
{
	Elem*temp = new Elem;
	temp = tail;
	for (uint i = count; i>0; i--)
	{
		if (i == index)
			return temp;
		temp = temp->prev;
	}
}

Elem*DoubleLinkedList::GetElemAt(uint index)
{
	if (count)
	if (index <= count/2)
		return GetFromHead(index);
	    return GetFromTail(index);
}

char* DoubleLinkedList::GetDataFromHead(uint index)
{
	Elem*temp = new Elem;
	temp = head;
	for (uint i = 0; i < count; i++)
	{
		if (i == index)
			return temp->data;
		temp = temp->next;
	}
}

char* DoubleLinkedList::GetDataFromTail(uint index)
{
	Elem*temp = new Elem;
	temp = tail;
	for (uint i = count; i>0; i--)
	{
		if (i == index)
			return temp->data;
		temp = temp->prev;
	}
}

char* DoubleLinkedList::GetData(uint index)
{
	if (count)
	if (index <= count / 2)
	    return GetDataFromHead(index);
	    return GetDataFromTail(index);
}