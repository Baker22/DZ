#include"LinkedList.h"

SingleLinkedList::SingleLinkedList()
{
	head = tail = nullptr;
	count = 0;
}

void SingleLinkedList:: AddTail(T data)
{
	Elem*temp = new Elem;
	temp->data = data;
	temp->next = nullptr;
	if (head == nullptr)
		head = tail = temp;
	else
	{
		tail->next = temp;
		tail = temp;
	}
	count++;
}

void SingleLinkedList::AddHead(T data)
{
	Elem*temp = new Elem;
	temp->data = data;
	temp->next = head;
	if (head == nullptr)
	head = tail = temp;
	else
	{
	head = temp;
	}
	count++;
}

void SingleLinkedList::RemoveHead()
{
	if (count)
	{
	Elem*temp = head;
	head = head->next;
	delete temp;
	count--;
	}
}

void SingleLinkedList::ClearList()
{
	while (head != nullptr)
		RemoveHead();
}

void SingleLinkedList::PrintList()const
{
	Elem*temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << "\n\n";
}