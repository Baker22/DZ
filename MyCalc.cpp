#include"MyCalc.h"
using namespace std;

Stack::Stack()
{
	stack_size = 80;
	mass = new char[stack_size];
	top = 0;
}

Stack::~Stack()
{
	Clear();
	delete[]mass;
	mass = nullptr;
}

void Stack::Clear()
{
	top = 0;
}

bool Stack::IsEmpty()
{
	return top == 0;
}

bool Stack::IsFull()
{
	return top == stack_size;
}

int Stack::GetCount()
{
	return top;
}

char Stack::GetPeek()
{
	return mass[top - 1];
}

void Stack::Push(char sim)
{
	if (IsFull())
		Resize();
	mass[top++] = sim;
}

char Stack::Pop()
{
	if (!IsEmpty())
		return mass[--top];
	else cout<< "Stack is empty!\n";
}

bool Stack::Contains(int sim)
{
	for (int i = 0; i < top; i++)
	{
		if (mass[i] == sim)
			return true;
	}
	return false;
}

void Stack::AddIfNotYet(int sim)
{
	if (!Contains(sim))
		Push(sim);
}

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
	if ('(', ')') return true;
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

int Prior(char sim)
{
	switch (sim)
	{
	case '*':
	case '/':
		return 3; break;
	case '+':
	case '-':
		return 2; break;
	case '(':
		return 1; break;
	default: return 0; break;
	}
}

bool IfOper(char sim)
{
	if (sim == '*' || sim == '/' || sim == '+' || sim == '-' || sim == '^')
		return true;
	else
		return false;

}

bool IfNumber(char sim)
{
	if (sim > 47 && sim < 58)
		return true;
	return false;
}

char*PolNot(char*example)
{
	if (CheckExample(example))
	{
		Stack Oper;
		Stack Numbs;
		char*sims = new char[80];
		int N = 0;
		for (int i = 0; example[i] != '=', example[i] != '\0'; i++)
		{
			if (IfOper(example[i]))
			{
				if (strlen(sims))

				if ((Oper.IsEmpty())||(Prior(example[i])>Prior(Oper.GetPeek())))
					Oper.Push(example[i]);
				else
				{
					while ((!Oper.IsEmpty())&&(Prior(example[i]) <= Prior(Oper.GetPeek())))
						sims[N++] = Oper.Pop();
				}
			}
			else if (IfNumber(example[i]))
				sims[N++] = example[i];
			else if (IfLeftBrack(example[i]))
				Oper.Push(example[i]);
			else if (IfRightBrack(example[i]))
			{
				while (Oper.GetPeek() != '(')
					sims[N++] = Oper.Pop();
				Oper.Pop();
			}
			
		}
		while (!Oper.IsEmpty())
			sims[N++] = Oper.Pop();
		sims[N++] = '\0';
		return sims;
	}
	return "Incorrect Expression";
}

double Calculate(char*numbs)
{
	Stack fin;
	int i = 0;
	while (!IfOper(numbs[i]))
		fin.Push(numbs[i++]);
	switch (numbs[i])
	{
	case '+':fin.Push()
	}
	return 3;
}

