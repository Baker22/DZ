#pragma once
#include<iostream>
#include<time.h>
using namespace std;
typedef unsigned int uint;

class Vector
{
	uint count;
	uint capacity;
	int*arr;
	void SetCount(uint count);
public:
	Vector();
	Vector(uint capasity);
	Vector(Vector & other);
	~Vector();
	uint GetCount(){ return count; }
	uint GetCapacity(){ return capacity; }
	void SetCapacity(uint capacity);
	void Resize();
	char*ShowVect();
	void FillArr();
	void AddValue(int value);//добавить элемент в конец массива
	void RemoveValue();//удаление элемента с конца массива
	void ClearArr();//все значения массива=0
	int IndexOf(int value);//проверка на подмножество (поиск слева)
	int LastIndexOf(int value);//проверка на подмножество (поиск справа)
	void Insert(uint index, int value);//вставка элемента в массив по указанному индексу,с заменой существующего (если такой есть), с проверкой на выход за пределы массива 
	void InsertPlus(uint index, int value);//вставка элемента в массив по указанному индексу, с проверкой на выход за пределы массива
	void RemoveAt(uint index);//удаление элемента из массива по указанному индексу, с проверкой на выход за пределы массива
	void Reverse();//изменение порядка следования элементов в массиве на противоположный
	void Sort();//сортировка
	void Shuffle();//пипец
	bool operator==(Vector &other);// (сравнение двух массивов)
	void operator()(uint capacity); //(изменение capacity - альтернатива Resize).
	int operator[](uint index);// (доступ к элементу массива по указанному индексу, с проверкой на выход за пределы массива).
	void operator+(Vector &other);// (слияние двух массивов)
	friend ostream& operator<<(ostream& os, Vector& arr);//вывод на экран
	friend istream& operator>>(istream& is, Vector& arr);//(ввод с клавиатуры)
	

	
};
