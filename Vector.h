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
	void AddValue(int value);//�������� ������� � ����� �������
	void RemoveValue();//�������� �������� � ����� �������
	void ClearArr();//��� �������� �������=0
	int IndexOf(int value);//�������� �� ������������ (����� �����)
	int LastIndexOf(int value);//�������� �� ������������ (����� ������)
	void Insert(uint index, int value);//������� �������� � ������ �� ���������� �������,� ������� ������������� (���� ����� ����), � ��������� �� ����� �� ������� ������� 
	void InsertPlus(uint index, int value);//������� �������� � ������ �� ���������� �������, � ��������� �� ����� �� ������� �������
	void RemoveAt(uint index);//�������� �������� �� ������� �� ���������� �������, � ��������� �� ����� �� ������� �������
	void Reverse();//��������� ������� ���������� ��������� � ������� �� ���������������
	void Sort();//����������
	void Shuffle();//�����
	bool operator==(Vector &other);// (��������� ���� ��������)
	void operator()(uint capacity); //(��������� capacity - ������������ Resize).
	int operator[](uint index);// (������ � �������� ������� �� ���������� �������, � ��������� �� ����� �� ������� �������).
	void operator+(Vector &other);// (������� ���� ��������)
	friend ostream& operator<<(ostream& os, Vector& arr);//����� �� �����
	friend istream& operator>>(istream& is, Vector& arr);//(���� � ����������)
	

	
};
