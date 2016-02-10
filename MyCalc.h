#include <iostream>
#include<cstdlib>
using namespace std;

template<typename T>
class Stack
{
	int stack_size;
	T *mass;
	int top;
	void Resize()
	{
		stack_size *= 2;
		T*_new = new T[stack_size];
		for (int i = 0; i < top; i++)
			_new[i] = mass[i];
		delete[]mass;
		mass = _new;
	}

public:
	Stack()
	{
		stack_size = 80;
		mass = new T[stack_size];
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
	T GetPeek()
	{
		return mass[top - 1];
	}
	void Push(T sim)
	{
		if (IsFull())
			Resize();
		mass[top++] = sim;
	}
	T Pop()
	{
		if (!IsEmpty())
			return mass[--top];
		else cout << "Stack is empty!\n";
	}
	bool Contains(T sim)
	{
		for (int i = 0; i < top; i++)
		{
			if (mass[i] == sim)
				return true;
		}
		return false;
	}
	void AddIfNotYet(T sim)
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
	if ('(', ')') return true;
	if ('{', '}')  return true;
	if ('[', ']')  return true;
	if ('<', '>')  return true;
}

bool CheckExample(char*example)
{
	if (example)
	{
		Stack <char>* temp = new Stack<char>;
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

void Calculate(Stack <double> &Numbs,char sim)
{
	double b = Numbs.Pop();
	double a = Numbs.Pop();
	switch (sim)
	{
	case '+':Numbs.Push(a +b ); break;
	case '-':Numbs.Push(a - b); break;
	case '/':Numbs.Push(a / b); break;
	case '*':Numbs.Push(a * b); break;
	}
}
 
double PolNot(char*example)
{
	if (CheckExample(example))
	{
		Stack <char>Oper;
		Stack <double>Numbs;
		char*sims = new char[10];
		int N = 0;
		for (int j = 0; !IfNumber(example[j]); j++)
		{
			if (Prior(example[j]) == 3)
			{
				cerr << "incorrect expression" << endl;//как ни кручу, не получается у меня сделать "throw"
				return 0;
			}
			
		}
		for (int i = 0;example[i] != '='&& example[i] != '\0'; i++)
		{
			if (IfOper(example[i]))
			{
				if (strlen(sims))
				{
				   Numbs.Push(atof(sims));
				   N = 0;
				   sims[N] = '\0';
				}
				
				if ((Oper.IsEmpty()) || (Prior(example[i])>Prior(Oper.GetPeek())))
					Oper.Push(example[i]);
				else
				{
					while ((!Oper.IsEmpty()) && (Prior(example[i]) <= Prior(Oper.GetPeek())))
						Calculate(Numbs,Oper.Pop());
					Oper.Push(example[i]);
				}
			}
			else if (IfNumber(example[i]))
			{
				sims[N++] = example[i];
			    sims[N] = '\0';
			}	
			else if (IfLeftBrack(example[i]))
				Oper.Push(example[i]);
			else if (IfRightBrack(example[i]))
			{
				while (Oper.GetPeek() != '(')
				{
					if (IfNumber(sims[N-1]))
					{
					Numbs.Push(atof(sims));
				    N = 0;
				    sims[N] = '\0';
					}
					Calculate(Numbs,Oper.Pop());
				}
				Oper.Pop();
			}
		    }
			while (!Oper.IsEmpty())
		      {
			      if (IfNumber(sims[N-1]))
					{
					Numbs.Push(atof(sims));
				    N = 0;
				    sims[N] = '\0';
					}
			      Calculate(Numbs, Oper.Pop());
		       }	
		     return Numbs.Pop();
		
		
		}
	return 0;
}


