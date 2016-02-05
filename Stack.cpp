#include <iostream>
#include <ctime>
using namespace std;

class Stack
{
	int stack_size;
	char *mass;
	int top;
	char *mass;
	char*example;
	char*pair1;
	char*pair2;
	char*pair3;
	char*pair4;
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
		example = nullptr;
		this->pair1 = nullptr;
		this->pair2 = nullptr;
		this->pair3 = nullptr;
		this->pair4 = nullptr;
	}
	Stack(char*text,char*examples,char*pair1,char*pair2,char*pair3,char*pair4)
	{
		stack_size = strlen(text)+1;
		mass = text;
		top = strlen(text);
		this->example = examples;
		this->pair1 =pair1;
		this->pair2 =pair2;
		this->pair3 =pair3;
		this->pair4 =pair4;
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

	bool IfCorrect()
	{
		Stack*temp = new Stack;
		for (int i = 0; i < top; i++)
		{
			for (int j = 0; j < strlen(this->example); j++)
			{
				if (this->mass[i] == this->example[j])
				{
					char sim_a = (temp->GetPeek());
					temp->Push(this->example[i]);
					char sim_b= (temp->GetPeek());
					char*a(sim_a,sim_b)
					if()
					{
						
					}
				}
					temp->Push(this->example[i])
					
				if (temp->GetPeek())
			}
				
		}
			
	}
};

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
	char *example = ("(){}[]<>");
	char *pair1 = ("()");
	char *pair2 = ("{}");
	char *pair3 = ("[]");
	char *pair4 = ("<>");
	char *text = ("(153 + 20)*{ 83 - 5 }-<1000>[bingo]");
	Stack Ariphmetic(text,example,pair1,pair2,pair3,pair4);

	delete[]st;
	st = nullptr;
}
