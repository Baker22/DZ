#include<iostream>
using namespace std;
typedef unsigned int uint;
class Container abstract
{
	int count;
public:
	virtual int GetCount()=0;
	virtual void Add(int value)=0;
	virtual void Remove(int value)=0;
	virtual void Print()=0;
	virtual int Search(int value)=0;
	virtual void Replace(int target,int value)=0;
	virtual void Sort()=0;
};

class DoubleLinkedList :public Container
{
struct Elem
{
	int data;
	int prime;
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
	int GetCount(){ return count; }
	void Add(int value)
	{
		AddData(0, value);
	}
	void AddData(int prime, int data)
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
	void AddTail(int prime, int data)
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
	void AddHead(int prime, int data)
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
	void Remove(int value)
	{
		if (count)
		{
			Elem*temp = new Elem;
			for (int i = GetCount(); i > 0; i--)
			{
				if (GetData(i) == value)
				{
					temp = GetElemAt(i);
					if (temp == tail)
						RemoveTail();
					else if (temp == head)
						RemoveHead();
					else
					{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete[]temp;
					}
				}
			}
		count--;
		}
	}
	void Print()
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
	int Search(int value)
	{
		if (count)
		{
			Elem*temp = new Elem;
			for (int i = 0; i < GetCount(); i++)
			{
				if (GetDataFromHead(i) == value)
					return i;
			}
		}
		return -1;
	}
	void Replace(int target, int value)
	{
		if (count)
		{
			GetFromHead(Search(target))->data = value;
		}
		
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
	int GetDataFromHead(uint index)
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
	int GetDataFromTail(uint index)
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
	int GetData(uint index)
	{
		if (count)
		if (index <= count / 2)
			return GetDataFromHead(index);
		return GetDataFromTail(index);
	}
	void Sort()
	{
		for (int i = 1; i <GetCount(); i++)
		for (int j = i; j>0 && GetDataFromHead(j) <= GetDataFromHead(j - 1); j--)
		{
			int a = GetDataFromHead(j - 1);
			int b = GetDataFromHead(j);
			Replace(b,a);
			Replace(a,b);
		}
	}
};


class SingleLinkedList:public Container
{
struct Elem
{
	int data;
	Elem* next;
};

private:
	Elem* head;
	Elem* tail;
	uint count;
public:
	SingleLinkedList()
	{
		head = tail = nullptr;
		count = 0;
	}
	~SingleLinkedList(){ ClearList(); }
	void AddTail(int data)
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
	void AddHead(int data)
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
	void RemoveHead()
	{
		if (count)
		{
			Elem*temp = head;
			head = head->next;
			delete temp;
			count--;
		}
	}
	void ClearList()
	{
		while (head != nullptr)
			RemoveHead();
		count = 0;
	}
	void Print()
	{
		PrintList();
	}
	void PrintList()const
	{
		Elem*temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << "\n\n";
	}
	Elem* GetElemAt(int index)
	{
		if (index <= count - 1)
		{
			Elem*temp = head;
			for (int i = 0; i < count; i++)
			{
				if (i == index)
					return temp;
				temp = temp->next;
			}
		}
	}
	int GetCount(){ return count; }
	int IndexOf(int data)
	{
		int index = 0;
		Elem* temp = head;
		for (int i = 0; i < count; i++)
		{
			if (temp->data == data)
				return index;
			temp = temp->next;
			index++;
		}
		return -1;
	}
	bool Contains(const int some)
	{return IndexOf(some);}
	int operator[](uint index)const
	{
		if (index > count - 1)
			return-1;
		Elem *temp = head;
		for (int i = 0; i < count; i++)
		{
			if (i == index)
				return temp->data;
			temp = temp->next;
		}
	}
	void Insert(int data, uint index)
	{
		if (index >= count)
		{
			AddTail(data);
			return;
		}
		if (index == 0)
		{
			AddHead(data);
			return;
		}
		Elem*_new = new Elem;
		_new->data = data;
		_new->next = GetElemAt(index);
		GetElemAt(index - 1)->next = _new;
		count++;
	}
	void Remove(int number)
	{
		for (int i = 0; i < count; i++)
		if (operator[](i) == number)
		{
			DeleteElem(i);
			return;
		}
	}
	void DeleteElem(uint index)
	{
		Elem*temp = new Elem;
		temp = GetElemAt(index);
		GetElemAt(index - 1)->next = GetElemAt(index + 1);
		delete[]temp;
		temp = nullptr;
		count--;
	}
	void RemoveAll(int number)
	{
		for (int i = 0; i < count; i++)
			Remove(number);
	}
	void RemoveAt(int index)
	{
		DeleteElem(index);
	}
	void Reverse()
	{
		int j = count - 1;
		for (int i = 0; i < count / 2; i++, j--)
		{
			swap(GetElemAt(i)->data, GetElemAt(j)->data);
		}
	}
	void Sort()
	{
		for (int i = 1; i < count; i++)
		for (int j = i; j>0 && GetElemAt(j)->data<GetElemAt(j - 1)->data; j--)
			swap(GetElemAt(j)->data, GetElemAt(j - 1)->data);

	}
	void Replace(int target, int value)
	{
		if (count)
		{
			GetElemAt(IndexOf(target))->data = value;
		}

	}
	int Search(int value)
	{
		return IndexOf(value);
	}
	void Add(int value)
	{
		AddTail(value);
	}
};

class Vector:public Container
{
	uint count;
	uint capacity;
	int*arr;
	void SetCount(uint count)
	{
		this->count = count;
	}
public:
	Vector()
	{
		count = 0;
		capacity = 10;
		arr = new int[capacity];
	}
	Vector(uint capacity)
	{
		SetCount(0);
		SetCapacity(capacity);
		arr = new int[capacity];
	}
	Vector( Vector & other)
	{
		this->count = other.GetCount();
		this->capacity = other.GetCapacity();
		arr = new int[capacity];
		for (uint i = 0; i < other.count; i++)
			arr[i] = other.arr[i];
	}
	~Vector()
	{

		ClearArr();
		cout << "DEST DONE\n";
	}
	int GetCount(){ return count; }
	uint GetCapacity()const{ return capacity; }
	void SetCapacity(uint capacity)
	{
		if (this->capacity == capacity)
			return;
		this->capacity = capacity;
		int*temp = new int[capacity];
		int arr_size = (this->count < capacity) ? this->count : capacity;
		for (int i = 0; i < arr_size; i++)
			temp[i] = arr[i];
		delete[]this->arr;
		this->arr = temp;
		count = arr_size;
	}
	void Resize()
	{
		int*temp = new int[capacity + 10];
		for (uint i = 0; i < count; i++)
			temp[i] = arr[i];
		delete[]arr;
		arr = temp;
	}
	char*ShowVect()
	{
		if (!count)
			return "array contains: 0";
		char*res = new char[250];
		char*temp = new char[20];
		strcpy_s(res, 17, "array contains: ");
		for (uint i = 0; i < count; i++)
		{
			int numbers = 1;
			int value = arr[i];
			for (; value > 0; numbers++, value /= 10){}
			_itoa_s(arr[i], temp, numbers, 10);
			strcat_s(res, 250, temp);
			strcat_s(res, 250, "; ");
		}
		delete[]temp;
		return res;
	}
	void FillArr()
	{
		for (uint i = 0; i < capacity; i++)
		{
			this->arr[i] = (i + 1);
			this->count++;
		}

	}
	void Add(int value)//добавить элемент в конец массива
	{
		if (capacity == count)
			Resize();
		arr[count] = value;
		count++;
	}
	void RemoveValue()//удаление элемента с конца массива
	{
		if (!count)
			return;
		arr[count - 1] = 0;
		count--;
	}
	void ClearArr()//все значения массива=0
	{
		delete[]arr;
		arr = nullptr;
		count = 0;
	}
	int IndexOf(int value)//проверка на подмножество (поиск слева)
	{
		for (uint i = 0; i < count; i++)
		{
			if (arr[i] == value)
				return i;
		}
		return -1;
	}
	int LastIndexOf(int value)//проверка на подмножество (поиск справа)
	{
		for (uint i = count - 1; i >0; i--)
		{
			if (arr[i] == value)
				return i;
		}
		return -1;
	}
	void Insert(uint index, int value)//вставка элемента в массив по указанному индексу,с заменой существующего (если такой есть), с проверкой на выход за пределы массива 
	{
		if (index > capacity - 1)
			Resize();
		if (index > count - 1)
		{
			index = count;
			arr[index] = value;
			count++;
		}
		else
			arr[index] = value;
	}
	void InsertPlus(uint index, int value)//вставка элемента в массив по указанному индексу, с проверкой на выход за пределы массива
	{
		if (index > capacity - 1 && count >= capacity - 1)
			Resize();
		if (index > count)
		{
			index = count;
			arr[count] = value;
		}
		else
		{
			for (uint i = count; i > index; i--)
			{
				int temp = arr[i];
				arr[i + 1] = temp;
			}
			arr[index] = value;
		}
		count++;
	}
	void Remove(int value)
	{
		RemoveAt(IndexOf(value));
	}
	void RemoveAt(uint index)//удаление элемента из массива по указанному индексу, с проверкой на выход за пределы массива
	{
		if (index > count - 1)
			return;
		for (uint i = index; i < count - 1; i++)
			arr[i] = arr[i + 1];
		arr[count - 1] = 0;
		count--;
	}
	void Reverse()//изменение порядка следования элементов в массиве на противоположный
	{
		if (count < 2)
			return;
		for (uint i = 0, j = count - 1; i < (count / 2); i++, j--)
			swap(arr[i], arr[j]);
	}
	void Sort()//сортировка
	{
		if (count < 2)
			return;
		for (uint i = 1; i < count; i++)
		for (uint j = i; j>0 && arr[j] < arr[j - 1]; j--)
			swap(arr[j], arr[j - 1]);
	}
	void Shuffle()//пипец
	{
		for (uint i = 0; i < count; i++)
		{
			int index = rand() % count;
			if (i == index)continue;
			swap(arr[i], arr[index]);
		}
	}
	bool operator==(Vector &other)// (сравнение двух массивов)
	{
		if (this->count != other.count)
			return false;
		for (uint i = 0; i < count; i++)
		{
			if (this->arr[i] != other.arr[i])
				return false;
		}
		return true;
	}
	void operator()(uint capacity) //(изменение capacity - альтернатива Resize).
	{
		if (this->capacity == capacity)
			return;
		int*temp = new int[capacity];
		int arr_size = (this->count < capacity) ? this->count : capacity;
		for (int i = 0; i < arr_size; i++)
			temp[i] = arr[i];
		delete[]this->arr;
		this->arr = temp;
		count = arr_size;
	}
	int operator[](uint index)// (доступ к элементу массива по указанному индексу, с проверкой на выход за пределы массива).
	{

		if (index>count - 1)
			return -1;
		return arr[index];
	}
	void Print()
	{
		cout << ShowVect();
	}
	int Search(int value)
	{
		return IndexOf(value);
	}
	void Replace(int target, int value)
	{
		Insert(IndexOf(target), value);
	}
	friend ostream& operator<<(ostream& os, Vector& arr)//вывод на экран
	{
		os << arr.ShowVect();
		return os;
	}
	friend istream& operator>>(istream& is, Vector& arr)//(ввод с клавиатуры)
	{
		int capacity;
		is >> capacity;
		arr.SetCapacity(capacity);
		return is;
	}
};


class BinaryTree
{
public:
	struct Node 
	{
		int value; 
		Node* parent;
		Node* right;
		Node* left;

		void ShowNode()
		{
			cout << value << " ";
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
	void Add(int value)
	{
		AddNode(value);
	}
	void Remove(int value)
	{
		DeleteNode(value);
	}
	void Print()
	{
		ShowTree();
	}
	int Search(int value)
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
					return 1;
			}
			return 0;
		}
	}
	void Replace(int target, int value)
	{
		FindNode(target)->value = value;
	}
	void Sort()
	{
		ShowTree();
	}
	Node* FindNode(int value)
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
	void AddNode(int value)
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
	BinaryTree& operator = (const BinaryTree& obj)
	{
		if (!IsEmpty())
			Clear();
		AddNode(obj.root->value);
		Copy(obj.root);
		return *this;
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
	void DeleteNode(int value)
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
	DoubleLinkedList a;
	a.Add(23);
	a.Add(20);
	a.Add(45);
	a.Add(10);
	cout<<a.GetCount()<<endl;
	a.Print();
	cout << endl;
	a.Replace(20, 21);
	a.Print();
	cout << endl;
	a.Sort();
	a.Print();
	cout << endl;
	cout<<a.Search(212)<<endl;
	a.Remove(45);
	a.Print();
	cout << "--------------------------\n";
	SingleLinkedList b;
	b.Add(40);
	b.Add(50);
	b.Add(20);
	b.Add(30);
	cout<<b.GetCount()<<endl;
	b.Print();
	cout << endl;
	b.Replace(20, 21);
	b.Print();
	cout << endl;
	b.Sort();
	b.Print();
	cout << endl;
	cout<<b.Search(212)<<endl;
	b.Remove(45);
	b.Print();
	cout << "--------------------------\n";
	Vector c;
	c.Add(40);
	c.Add(50);
	c.Add(20);
	c.Add(30);
	cout<<c.GetCount()<<endl;
	c.Print();
	cout << endl;
	c.Replace(20, 21);
	c.Print();
	cout << endl;
	c.Sort();
	c.Print();
	cout << endl;
	cout<<c.Search(212)<<endl;
	c.Remove(40);
	c.Print();
	cout<<endl;
	cout << "--------------------------\n";
	BinaryTree d;
	d.Add(40);
	d.Add(50);
	d.Add(20);
	d.Add(30);
	cout<<d.GetCount()<<endl;
	d.Print();
	cout << endl;
	d.Replace(20, 21);
	d.Print();
	cout << endl;
	d.Sort();
	d.Print();
	cout << endl;
	cout<<d.Search(212)<<endl;
	d.Remove(40);
	d.Print();
}