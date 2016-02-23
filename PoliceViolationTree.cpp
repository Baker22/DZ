#include<iostream>
using namespace std;

typedef unsigned int uint;

class PoliceData;
class Node;
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
	~Violation(){ ClearList(); cout << "LISTdestdone"; }
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
	void GetFullList()
	{
		for (int i = 0; i < list_count;i++)
		cout << CharCopy(i) << endl;
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
	friend Node;
	friend PoliceData;
};

class Node
{
	char*carnum;
	Violation list;
	Node *left;
	Node *right;
	Node *parent;
public:
	Node()
	{
		left = right = parent = nullptr;
	}
	~Node(){};
	friend PoliceData;
};


class PoliceData
{
	Node*root;
	uint count;
	void AddRoot(char*carnum, char*Violation)
	{
		Node*temp = new Node;
		temp->carnum=carnum;
		temp->list.AddTail(Violation);
		temp->left = nullptr;
		temp->right = nullptr;
		root = temp;
	}
	void AddNode(char*carnum, char*Violation)
	{
		if (!IfInBase(carnum))
		{
			Node*temp = new Node;
			Node*a = root;
			while (a!=nullptr)
			{
				temp->parent = a;
				if (strcmp(a->carnum,carnum)<0)
				{
					a = a->right;
				}
				else
				{
					a = a->left;
				}
				
			}
			temp->carnum = carnum;
			temp->list.AddTail(Violation);
			if (strcmp(temp->parent->carnum, temp->carnum)<0)
				temp->parent->right = temp;
			else
				temp->parent->left = temp;
		}
		else
		{
			IfInBase(carnum)->list.AddTail(Violation);
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
		while ( temp!=nullptr && strcmp(temp->carnum, carnum)!=0)
		{
			if (strcmp(temp->carnum, carnum)>0)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}
	
	void PrintTree(Node*root)
	{
		if (root!= nullptr)
		{
		PrintTree(root->left);
		PrintNode(root);
		PrintTree(root->right);
		}
	}

	void PrintNode(Node*current)
	{
		cout << current->carnum<<":\n";
		current->list.GetFullList();
		cout << endl;
	}
	
	void PrintByNum(Node*root,char*carnum)
	{
		while (root!=0 && root->carnum != carnum)
		{
			if (strcmp(root->carnum, carnum)>0)
				root = root->left;
			else
				root = root->right;

		}
		PrintNode(root);
	}
	void AddViolation(char*carnum, char*Violation)
	{
		if (IsEmpty())
		{
			AddRoot(carnum, Violation);	
			return;
		}
		AddNode(carnum, Violation);
	}
	Node*GetRoot()
	{
		return root;
	}

	void PrintByViolation(Node*root,char*Violation)
	{
		if (root != nullptr)
		{
			PrintByViolation(root->left, Violation);
			CheckViolation(root,Violation);
			PrintByViolation(root->right, Violation);
		}
	}

	void CheckViolation(Node*node,char*Violation)
	{
		for (int i = 0; i < node->list.GetListCount(); i++)
		{
			if (strcmp(node->list.CharCopy(i), Violation) == 0)
				cout << node->carnum << ";";
		}
	}
};

void main()
{
	PoliceData a;
	a.AddViolation("2","Driving with hangover");
	a.AddViolation("2","Sleepping at the wheel");
	a.AddViolation("2","Drinking at the wheel");
	a.PrintByNum(a.GetRoot(),"2");
	a.AddViolation("3","Driving with hangover");
	a.AddViolation("3","Dansing");
	a.AddViolation("3","Eating");
	a.AddViolation("3", "Drinking at the wheel");
	a.AddViolation("1","Overspeed");
	a.AddViolation("1","NoNStop");
	a.AddViolation("1","Crashing");
	a.AddViolation("1", "Drinking at the wheel");
	a.PrintByNum(a.GetRoot(),"3");
	a.PrintTree(a.GetRoot());
	a.PrintByNum(a.GetRoot(),"1");
	a.PrintByViolation(a.GetRoot(),"Drinking at the wheel");

}