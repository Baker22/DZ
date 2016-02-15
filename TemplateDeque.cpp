#include<iostream>

using namespace std;
typedef unsigned int uint;
template<typename P,typename T>
class Deque
{
	class DoubleLinkedList
{
	struct Elem
{
	T data;
	P prime;
	Elem*next;
	Elem*prev;
};
	Elem*head;
	Elem*tail;
	int count;
public:
	DoubleLinkedList()
	{
		head = tail = nullptr;
		count = 0;
	}
	~DoubleLinkedList(){ ClearList(); }
	void ClearList()
	{
		while (head != nullptr)
			RemoveHead();
	}
	int GetLenght(){ return count; }
	void AddData(P prime, T data)
	{
		if (count == 0 || prime >= tail->prime)
			AddTail(prime, data);
		else if (prime <= head->prime)
			AddHead(prime, data);
		else
		{
			Elem*_new = new Elem;
			Elem*temp = new Elem;
			_new->data = data;
			_new->prime = prime;
			temp = head;
			while (temp->next->prime <= _new->prime)
				temp = temp->next;
			_new->next = temp->next;
			_new->prev = temp;
			temp->next = _new;
			count++;
		}
	}
	void AddTail(P prime, T data)
	{
		Elem*temp = new Elem;
		temp->data = data;
		temp->prime = prime;
		temp->next = nullptr;
		if (head == nullptr)
		{
			temp->prev = nullptr;
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
	void AddHead(P prime, T data)
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
			head = temp;
		}

		count++;
	}
	void RemoveHead()
	{
		Elem*temp = new Elem;
		temp = head;
		head = head->next;
		delete[]temp;
		if (head)
			head->prev = nullptr;
		count--;
	}
	void RemoveTail()
	{
		Elem*temp = new Elem;
		tail = tail->prev;
		tail->next = nullptr;
		delete[]temp;
		count--;
	}
	void PrintList()
	{
		Elem*temp = new Elem;
		temp = head;
		while (temp)
		{
			cout << "priority (" << temp->prime << ") " << temp->data << endl;
			temp = temp->next;
		}
		delete[]temp;
	}
	Elem*GetFromHead(uint index)
	{
		Elem*temp = new Elem;
		temp = head;
		for (uint i = 0; i < count; i++)
		{
			if (i == index)
				return temp;
			temp = temp->next;
		}
	}
	Elem*GetFromTail(uint index)
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
	Elem*GetElemAt(uint index)
	{
		if (count)
		if (index <= count / 2)
			return GetFromHead(index);
		return GetFromTail(index);
	}
	T* GetDataFromHead(uint index)
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
	T* GetDataFromTail(uint index)
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
	T* GetData(uint index)
	{
		if (count)
		if (index <= count / 2)
			return GetDataFromHead(index);
		return GetDataFromTail(index);
	}
};
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

	void PushBack(P prime, T data)
	{
		d.AddTail(prime, data);
		counter++;
	}

	void PushFront(P prime, T data)
	{
		d.AddHead(prime, data);
		counter++;
	}

	void PushByPriority(P prime, T data)
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
void main()
{
	Deque <double,char*> q;
	q.PushByPriority(13, "CORRECT");
	q.PushByPriority(10, "HOPE");
	q.PushByPriority(11, "IT");
	q.PushByPriority(9, "I");
	q.PushByPriority(12, "IS");
	q.PrintDeque();
}