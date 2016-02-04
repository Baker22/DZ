#pragma once
#include<iostream>
using namespace std;

typedef unsigned int uint;
typedef int T;

struct Elem
	{
		T data;
		Elem* next;
	};
class SingleLinkedList
{
public:
	
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
	void CopyData(SingleLinkedList& other);
	void ClearList();
	void PrintList()const;
	int GetCopyData(uint index)const;
	Elem* GetElemAt(int index);// -получение указателя на элемент списка.
	T GetCount()const{ return count; }
	void AddRange(const T*arr,uint size);//Adds the elements of the int-array to the end of the single linked list.
	int LastIndexOf(T data);// -Searches for the specified number and returns the zero - based index of the last occurrence within the entire single linked list.
	int IndexOf(T data);// -Searches for the specified number and returns the zero - based index of the first occurrence within the entire single linked list.
	bool Contains(const T some);//Determines whether an element is in the single linked list.
	int operator[](uint index)const;//доступ к элементу списка по индексу.
	void operator=(SingleLinkedList& other);//перегрузка операции присваивания.
	bool operator==(const SingleLinkedList& other);//сравнение двух списков.
	bool Equals(const SingleLinkedList& other); //-сравнение с другим односвязным списком.
	char* SingleLinkedList::PrintListForIo()const;
	friend ostream& operator<<(ostream& os,SingleLinkedList& other);//перегрузка побитового сдвига влево(показ на экран)
	void Insert(T data,uint index);// -Inserts an element into the single linked list at the specified index.
	void InsertRange(T index, T*arr, uint arr_size);// -Inserts the elements of a int - array into the single linked list at the specified index.
	void Remove(T number);// -Removes the first occurrence of a specific number from the single linked list.
	void DeleteElem(uint index);
	void RemoveAll(T number);// -удаляет все вхождения number в односвязный список.
	void RemoveAt(int index);// -Removes the element at the specified index of the single linked list.
	void Reverse();// -Reverses the order of the elements in the entire single linked list.
	void Sort();// -Sorts the elements in the entire single linked list using the quick sorting.
	T* ToArray();// -Copies the elements of the single linked list to a new int - array.

};