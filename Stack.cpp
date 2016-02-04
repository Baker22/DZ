#include <iostream>
#include <ctime>
using namespace std;

class Stack
{
	int stack_size;
	int *mass;
	int top;

public:
	Stack()
	{
		stack_size = 10;
		mass = new int[stack_size];
		top = 0;
	}

	void Clear()
	{
		top = 0;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	bool IsFull()
	{
		return top == stack_size;
	}

	int GetCount()
	{
		return top;
	}

	int GetPeek()
	{
		return mass[top - 1];
	}

	void Push(int digit)
	{
		if (IsFull())
			Resize();
		mass[top++] = digit;
	}

	int Pop()
	{
		if (!IsEmpty())
			return mass[--top];
		else throw "Stack is empty!";
	}
	void Resize()
	{
		stack_size *= 2;
		int*_new = new int[stack_size];
		for (int i = 0; i < top; i++)
			_new[i] = mass[i];
		delete[]mass;
		mass = _new;
	}

	bool Contains(int elem)
	{
		for (int i = 0; i < top; i++)
		{
			if (mass[i] == elem)
				return true;
		}
		return false;
	}

	void AddIfNotYet(int elem)
	{
		if (!Contains(elem))
			Push(elem);
	}
};

void main()
{
	system("title Пользовательский адаптер Stack (динамический массив)");
	srand(time(0));

	Stack*st = new Stack;

	while (st->IsFull() == false)
		st->Push(rand() % 90 + 10);
	cout << st->GetPeek() << endl;
	cout << st->Contains(25) << endl;
	st->Push(88);
	st->AddIfNotYet(18);
	while (st->IsEmpty() == false)
		cout << st->Pop() << "  ";


	cout << "\n\n";
}
