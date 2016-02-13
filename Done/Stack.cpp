#include <iostream>
#include <ctime>
using namespace std;

class Stack
{
	int stack_size;
	char *mass;
	int top;
	void Resize()
	{
		stack_size *= 2;
		char*_new = new char[stack_size];
		for (int i = 0; i < top; i++)
			_new[i] = mass[i];
		delete[]mass;
		mass = _new;
	}

public:
	Stack()
	{
		stack_size = 10;
		mass = new char[stack_size];
		top = 0;
	}
	
	~Stack()
	{
		Clear();
		delete[]mass;
		mass = nullptr;
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

	char GetPeek()
	{
		return mass[top - 1];
	}

	void Push(char sim)
	{
		if (IsFull())
			Resize();
		mass[top++] = sim;
	}

	char Pop()
	{
		if (!IsEmpty())
			return mass[--top];
		else throw "Stack is empty!";
	}
	
	bool Contains(int sim)
	{
		for (int i = 0; i < top; i++)
		{
			if (mass[i] == sim)
				return true;
		}
		return false;
	}

	void AddIfNotYet(int sim)
	{
		if (!Contains(sim))
			Push(sim);
	}
};

bool IfLeftBrack(char sim)
{
	switch (sim)
	{
	case '(': return true; break;
	case '{': return true; break;
	case '[': return true; break;
	case '<': return true; break;
	default: return false; break;
	}
}

bool IfRightBrack(char sim)
{
	switch (sim)
	{
	case ')': return true; break;
	case '}': return true; break;
	case ']': return true; break;
	case '>': return true; break;
	default: return false; break;
	}
}

bool CheckPair(char peek, char sim)
{
	if('(',')') return true;
	if ('{', '}')  return true;
	if ('[', ']')  return true;
	if ('<', '>')  return true;
}


bool CheckExample(char*example)
{
	if (example)
	{
		Stack*temp = new Stack;
		for (int i = 0; i < strlen(example); i++)
		{
			char sim = example[i];
			if (IfLeftBrack(sim))
				temp->Push(sim);
			if (IfRightBrack(sim))
			{
				char peek = temp->GetPeek();
				if (CheckPair(peek, sim))
					temp->Pop();
			}
				
		}
		return temp->IsEmpty();
	}

}
void main()
{
	system("title Пользовательский адаптер Stack (динамический массив)");
	srand(time(0));

	Stack*st = new Stack;

	while (st->IsFull() == false)
		st->Push(rand() % 90 + 10);
	st->Push('e');
	cout << st->GetPeek() << endl;
	cout << st->Contains(30) << endl;
	
	st->AddIfNotYet(18);
	while (st->IsEmpty() == false)
		cout << st->Pop() << "  ";
	cout << "\n\n";

	char*ex = ("{(100+200)*<300/50>/[80!=10]}");
	cout<<CheckExample(ex);
}
