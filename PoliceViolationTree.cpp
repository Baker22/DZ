#include<iostream>
using namespace std;

typedef unsigned int uint;

 class Violation
{
	struct Elem
{
	int size;
	char*text;
	Elem*next;
};
	Elem*tail;
	Elem*head;
	uint list_count;
public:
	Violation()
	{
		head = tail = nullptr;
		list_count = 0;
	}
	~Violation(){ ClearList(); }
	void AddTail(char*text)
	{
		Elem*temp = new Elem;
		temp->next = nullptr;
		temp->text = text;
		if (head == nullptr)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		list_count++;
	}
	void RemoveHead()
	{
		Elem*temp = new Elem;
		temp = head;
		head = head->next;
		delete[]temp;
	}
	void ClearList()
	{
		while (head != nullptr)
			RemoveHead();
	}
	void GetViolation()
	{
		for (uint i = 0; i < list_count;i++)
		{
			cout << CharCopy(i)<<endl;
		}
	}
	char*CharCopy(uint index)
	{
		Elem*temp = new Elem;
		temp = head;
		for (uint i = 0; i < list_count; i++)
		{
		if (i == index)
		return temp->text;
		temp=temp->next;

		}
		
	}	
	void EditInfo(uint index,char*text)
	{
		Elem*temp = new Elem;
		temp = head;
		for (uint i = 0; i < list_count;i++)
		if (i == index)
		{
			delete[]temp->text;
			temp->text = text;
		}
	}
	uint GetListCount()
	{
		return list_count;
	}
};

class PoliceData
{
	struct CarInfo
{
	char*num;
	Violation list;
};
	struct Node
{
	
	CarInfo*main;
	Node *left;
	Node *right;
	Node *parent;
};
	Node*root;
	uint count;
	void AddRoot(char*carnum, char*Violation)
	{
		Node*temp = new Node;
		temp->main->num = carnum;
		temp->main->list.AddTail(Violation);
		temp->left = nullptr;
		temp->right = nullptr;
		root->parent =nullptr;
		root = temp;
	}
	void AddNode(char*carnum, char*Violation)
	{
		if (!IfInBase(carnum))
		{
			Node*temp = new Node;
		temp->main->num = carnum;
		temp->main->list.AddTail(Violation);
		temp->left = nullptr;
		temp->right = nullptr;
		Node*a = root;
		while (a!= nullptr)
		{
			if (a->main->num < temp->main->num)
			a = a->left;
			else if(a->main->num > temp->main->num)
				a = a->right;
		}
		if (a->main->num < temp->main->num)
			a->left = temp;
		else
			a->right = temp;
		}
		else
		{
			IfInBase(carnum)->main->list.AddTail(Violation);
		}
	}
public:
	PoliceData()
	{
		root = nullptr;
		count = 0;
	}
	~PoliceData(){};
	bool IsEmpty()
	{
		return root == 0;
	}
	Node*IfInBase(char*carnum)
	{
		Node*temp = new Node;
		temp = root;
		while (temp->main->num != carnum||temp!=nullptr)
		{
			if (temp->main->num > carnum)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}
	
	void PrintBase()
	{
		;
	}
	void AddViolation(char*carnum, char*Violation)
	{
		if (IsEmpty())
			AddRoot(carnum, Violation);	
		AddNode(carnum, Violation);
	}
};

void main()
{
	PoliceData a;
	a.AddViolation("aa9988b","Driving with hangover");
	/*a.AddViolation("aa9988b","Sleepping at the wheel");
	a.AddViolation("aa9988b","Sleepping at the wheel");*/
	/*Violation a;
	a.AddTail("char*text");
	a.AddTail("chaext");
	a.GetViolation();*/
}