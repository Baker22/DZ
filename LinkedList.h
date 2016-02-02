#include<iostream>
using namespace std;

typedef unsigned int uint;
typedef int T;
class SingleLinkedList
{
public:
	struct Elem
	{
		T data;
		Elem* next;
	};
private:
	Elem* head;
	Elem* tail;
	uint count;
public:
	SingleLinkedList();
	SingleLinkedList(SingleLinkedList& origin);
	~SingleLinkedList(){ ClearList(); }
	void AddTail(T data);
	void AddHead(T data);
	void RemoveHead();
	void ClearList();
	void PrintList()const;
	T GetCount()const{ return count; }
	void AddRange(const T*arr);//Adds the elements of the int-array to the end of the single linked list.
	bool Contains(const T some);//Determines whether an element is in the single linked list.
	void operator=(const SingleLinkedList& other);//���������� �������� ������������.
	bool operator==(const SingleLinkedList& other);//��������� ���� �������.
	friend ostream& operator<<(ostream& os, const SingleLinkedList& other);//���������� ���������� ������ �����(����� �� �����)
	T operator[](uint index);//������ � �������� ������ �� �������.
};