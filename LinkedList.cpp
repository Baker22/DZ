#include"LinkedList.h"
using namespace std;

SingleLinkedList::SingleLinkedList()
{
	head = tail = nullptr;
	count = 0;
}

SingleLinkedList::SingleLinkedList(SingleLinkedList& origin)
{
	CopyData(origin);
}

void SingleLinkedList::AddTail(T data)
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

void SingleLinkedList::AddHead(T data)
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

void SingleLinkedList::RemoveHead()
{
	if (count)
	{
	Elem*temp = head;
	head = head->next;
	delete temp;
	count--;
	}
}

void SingleLinkedList::CopyData(SingleLinkedList& other)
{
	for (int i = 0; i < other.count; i++)
		this->AddTail(other[i]);
}

void SingleLinkedList::ClearList()
{
	while (head != nullptr)
		RemoveHead();
	count = 0;
}

void SingleLinkedList::PrintList()const
{
	Elem*temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << "\n\n";
}

char* SingleLinkedList::PrintListForIo()const
{
	if (!count)
		return "List contains: 0";
	char*res = new char[250];
	char*temp = new char[20];
	strcpy_s(res, 17, "List contains: ");
	for (uint i = 0; i < count; i++)
	{
		int numbers = 1;
		int value = GetCopyData(i);
		for (; value > 0; numbers++, value /= 10){}
		_itoa_s(GetCopyData(i), temp, numbers, 10);
		strcat_s(res, 250, temp);
		strcat_s(res, 250, " ");
	}
	strcat_s(res, 250, "\n");
	return res;
}

void SingleLinkedList::AddRange(const T*arr,uint size)
{
	for (int i = 0; i < size; i++)
		AddTail(arr[i]);
}

int SingleLinkedList::LastIndexOf(T data)
{
	int index = 0;
	int found = 0;
	Elem* temp = head;
	for (int i = 0; i < count; i++)
	{
		if (temp->data == data)
		found = index;
		temp = temp->next;
		index++;
	}	
		return found;
		return -1;
}

int SingleLinkedList::IndexOf(T data)
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

bool SingleLinkedList::Contains(const T some)
{
	return IndexOf(some);
}

int SingleLinkedList::operator[](uint index)const
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

void SingleLinkedList::operator=(SingleLinkedList& other)
{
	if (this != &other)
	{
		this->ClearList();
		this->CopyData(other);
	}
}

Elem *SingleLinkedList::GetElemAt(int index)
{
	if (index <=count - 1)
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

int SingleLinkedList::GetCopyData(uint index)const
{
	int temp = this->operator[](index);
	return temp;
}

bool SingleLinkedList::operator==(const SingleLinkedList& other)
{
	if (this->count != other.count)
		return false;
	for (uint i = 0; i < count; i++)
	{
		if (this->GetCopyData(i) != other.GetCopyData(i))
		return false;
	}
	return true;
}

bool SingleLinkedList::Equals(const SingleLinkedList& other)
{
	return this->operator==(other);
}

 ostream& operator<<(ostream& os,SingleLinkedList& other)
{
	 os << other.PrintListForIo();
	 return os;
}

 void SingleLinkedList::Insert(T data, uint index)
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
		 Elem*_new=new Elem;
			 _new->data = data;
			 _new->next = GetElemAt(index);
			 GetElemAt(index-1)->next = _new;
			 count++;
 }

 void SingleLinkedList::InsertRange(T index,T*arr,uint arr_size)
 {
	 for (int i =arr_size-1 ; i >=0; i--)
		 Insert(arr[i], index);
 }

 void SingleLinkedList::DeleteElem(uint index)
 {
	 Elem*temp = new Elem;
	 temp = GetElemAt(index);
	 GetElemAt(index - 1)->next = GetElemAt(index + 1);
		 delete[]temp;
		 temp = nullptr;
		 count--;
 }

 void SingleLinkedList::Remove(T number)
 {
	 for (int i = 0; i < count; i++)
		 if (GetCopyData(i) == number)
	 {
		 DeleteElem(i);
		 return;
	 }	 
 }

 void SingleLinkedList::RemoveAll(T number)
 {
	 for (int i = 0; i < count; i++)
		 Remove(number);
 }

 void SingleLinkedList::RemoveAt(int index)
 {
	 DeleteElem(index);
 }

 void SingleLinkedList::Reverse()
 {
	 int j = count-1;
	 for (int i = 0; i < count / 2; i++, j--)
	 {
		 swap(GetElemAt(i)->data, GetElemAt(j)->data);
	 }
 }

 void SingleLinkedList::Sort()
 {
	 for (int i = 1; i < count; i++)
	 for (int j = i; j>0 && GetElemAt(j)->data<GetElemAt(j - 1)->data;j--)
		 swap(GetElemAt(j)->data, GetElemAt(j-1)->data);

 }
			
 T* SingleLinkedList::ToArray()
 {
	 if (count)
	 {
		 T*arr = new T[count];
	 for (int i = 0; i < count; i++)
		 arr[i] = GetCopyData(i);
	 return arr;
	 }
 }
