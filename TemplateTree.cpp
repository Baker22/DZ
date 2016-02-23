#include <iostream>
using namespace std;

template<typename T>
class BinaryTree
{
public:
	struct Node 
	{
		T value;
		Node* parent;
		Node* right;
		Node* left;

		void ShowNode()
		{
			cout << value << "\t";
		}
	};

private:
	Node* root;
public:
	BinaryTree()
	{
		root = 0;
	}

	bool IsEmpty()
	{
		return root == 0;
	}

	~BinaryTree()
	{
		Clear();
	}

private:
	void ShowTree(Node* elem)
	{
		if (elem != 0)
		{
			ShowTree(elem->left);
			elem->ShowNode();
			ShowTree(elem->right);
		}
	}

public:
	void ShowTree()
	{
		cout << "\n\n";
		ShowTree(root);
		cout << "\n\n";
	}

	Node* GetRoot()
	{
		return root;
	}

private:
	int GetCount(Node* elem, int count)
	{
		if (elem != 0)
		{
			count = GetCount(elem->left, count);
			count++;
			count = GetCount(elem->right, count);
		}
		return count;
	}

public:
	int GetCount()
	{
		int count = 0;
		count = GetCount(root, count);
		return count;
	}

private:
	void Clear(Node* elem)
	{
		if (elem != 0)
		{
			Clear(elem->left);
			Clear(elem->right);
			delete elem;
			elem = 0;
		}
	}

public:
	void Clear()
	{
		if (!IsEmpty())
		{
			Clear(root);
			root = 0;
		}
	}

	Node* FindNode(T value)
	{
		if (IsEmpty())
			return 0;
		else
		{
			Node* f = root;
			while (true)
			{
				if (value < f->value)
				{
					if (f->left != 0)
						f = f->left;
					else
						break;
				}
				else if (value > f->value)
				{
					if (f->right != 0)
						f = f->right;
					else
						break;
				}
				else
					return f;
			}
			return 0;
		}
	}

	void AddNode(T value)
	{
		if (FindNode(value))
			return;
		Node* n = new Node;
		n->right = n->left = 0;
		n->value = value;
		Node* parent = 0;
		if (IsEmpty())
		{
			root = n;
			root->parent = parent;
		}
		else
		{
			Node*p = root;
			while (p != 0)
			{
				parent = p;
				if (n->value>p->value)
					p = p->right;
				else
					p = p->left;
			}
			if (n->value<parent->value)
				parent->left = n;
			else
				parent->right = n;
			n->parent = parent;
		}
	}

	BinaryTree(const BinaryTree& obj)
	{
		root = 0;
		AddNode(obj.root->value);
		Copy(obj.root);
	}

	void Copy(Node* elem)
	{
		if (elem->left != 0)
			AddNode(elem->left->value);
		if (elem->right != 0)
			AddNode(elem->right->value);
		if (elem->left != 0)
			Copy(elem->left);
		if (elem->right != 0)
			Copy(elem->right);
	}

	void DeleteNode(T value)
	{
		Node* d = FindNode(value);
		if (d == 0)
			return;
		Node* parent = d->parent;
		if (d == root && GetCount() == 1)
		{
			Clear();
			return;
		}
		if (d->left == 0 && d->right == 0)
		{
			if (parent->left == d)
				parent->left = 0;
			else
				parent->right = 0;
			delete d;
			return;
		}
		if (d->left == 0 && d->right != 0)
		{
			if (parent->left == d)
			{
				parent->left = d->right;
			}
			else
			{
				parent->right = d->right;

			}
			d->right->parent = parent;
			delete d;
			return;
		}
		if (d->left != 0 && d->right == 0)
		{
			if (parent->left == d)
			{
				parent->left = d->left;
			}
			else
			{
				parent->right = d->left;

			}
			d->left->parent = parent;
			delete d;
			return;
		}
		if (d->left != 0 && d->right != 0)
		{
			Node*r = d->right;
			if (r->right == 0 && r->left == 0)
			{
				d->value = r->value;
				d->right = 0;
				delete r;
			}
			else if (r->left != 0)
			{
				Node*p = r->left;
				while (p->left != 0)
					p = p->left;
				d->value = p->value;
				if (p->right == 0)
					p->parent->left = 0;
				else
					p->parent->left = p->right;
				delete p;
			}
			else
			{
				d->value = r->value;
				d->right = r->right;
				delete r;
			}
		}
	}
};

void main()
{
	const int size = 25;
	int ar[size] = { 100, 50, 25, 10, 5, 15, 35, 27, 40, 75, 60, 90, 300, 200, 150, 250, 500, 400, 350, 370, 700, 800, 750, 900, 100 };

	BinaryTree <int>bt;
	for (int i = 0; i<size; i++)
		bt.AddNode(ar[i]);
	bt.ShowTree();

	BinaryTree <double>bt2;
	for(int i = 0;i<10;i++)
	bt2.AddNode(rand()%100);
	bt2.ShowTree();

}