#pragma once
#include<time.h>
#include<iostream>
//#include<string.h>
using namespace std;
typedef unsigned int uint;
class String
{
	char*str_arr;
	uint capacity;
	uint count;
public:
	String();//����������� �� ���������, ������� ������ ������ ������ (�� capacity= 80)
	explicit String(uint capacity);//explicit-����������� � 1 ���������� ���� int (����� capacity, � ��������� ��� ��������������� ������ 10)
	void SetCapacity(uint capacity);
	String(const char *str);// (��������� ������ �������� ����������� ��������� �� ������ char[], � ��������� - �� ������ �� ���������!)
	String(const String & origin);//����������� �����������)
	String(char *str, uint capacity);//����������� � 2 �����������- char* � int (��������� �� ������, ���������������)
    String(String& arr, int capacity);//����������� � 2 ����������� - String � int (��������� �� ������, ���������������)
	~String();
	void Initialize(uint count, uint capacity, char*str);
	int GetCount()const{ return this->count; }// -����� ������
	int GetCapacity()const{ return this->capacity; }//- ��������������� ������
	void Print()const; //-����� ������ �� �����
	void AddSim(char sim);
	void Resize(uint qty);// -��������� ���������� ��������, �� ���� - �������������)
	char GetSim(uint index)const;
	char*GetChar()const;
	String& operator=(const String & other);
	bool operator==(const String & other);// (������������������ ��������� ���� �����)
	bool operator>(const String & other);
	bool operator<(const String & other);
	bool operator>=(const String & other);
	bool operator<=(const String & other);
	bool operator!=(const String & other);
	void operator()(char*str, uint capacity, uint count);//(��������� ������������� ������)
	char operator[](uint index);//(������ � �������� ������ �� �������, ������������� ����������� ��������� � ��������������� ��������.
    void Clear();//- ������� ������
	String& operator+=(const String & other);//(������������ String)
	String& operator+=(const char*str);//(������������ char*)
	friend ostream & operator<<(ostream& os, String& arr);
	friend istream & operator>>(istream& is, String& arr);
	operator char*();//- �������������� � char*
	operator int();//- ����������� ������ � ����� ����� (���� ��� ��������)
    operator double();//- ����������� ������ � ������������ �����(���� ��� ��������)
	void PrintLn();//- ����� ������ �� ����� � ��������� ������� �� ��������� ������
	void GetLine();//- ���� ������ � ����������
	const String*GetString()const;//- ������� ������������ ��������� �� ������
	int CompareTo(String& other);// -��������� ����� ������ � ����� - �� ������ �������
	int CompareTo(char* str);//-��������� ����� ������ � ����� - �� ������ �������
	void Concat(String & other);//- ������������ � ����� ������ ���������� ������
	void Concat(char* str);//- ������������ � ����� ������ ���������� ������
	void Concat(int num);//- ������������ � ����� ������ ���������� ������
	void Concat(double num);//- ������������ � ����� ������ ���������� ������
	void Concat(String*other,int count);//- ������������ � ����� ������ �� ������� count ��������� ������� String'��
	bool Contains(char*text);// -���������, ���������� �� � ����� ������ ���������� ���������(� ����� �������)
	bool EndsWith(char*text);//- ���������, ������������� �� ���� ������ �������, ������� ������� � ���������
	bool StartsWith(char*text);//- ���������, ���������� �� ���� ������ �������, ������� ������� � ���������
	void CopyTo(String& other);//- ����������� ����� ����� ������ � ������ ������
	int IndexOf(char sim);//- �������� �� ��������� ������� � ������, � ���������� ������ ���������� ������������� ���������� �������(�� ������ ������).e��� ������ �� �������,���������� - 1.
	int LastIndexOf(char sim);//- �������� �� ��������� ������� � ������, � ���������� ������ ���������� ���������������� ���������� �������(����� � ����� ������).e��� ������ ���������, ���������� - 1.
	int IndexOf(char*str);// -�������� �� ��������� ��������� � ������, ����������� ������ ���������� ������������ ���������.e��� ������ �� �������, ���������� - 1.
	int LastIndexOf(String*str);// -�������� �� ��������� ��������� � ������, � ���������� ������ ���������� ������ ������ ���������(�� ����� ��� � ����� ������).e��� ������ ���������, ���������� - 1.
	int IndexOfAny(String*str);// -���������� �������� ������� �� ������� ��������, ����� ? ��� ���, ���� ���� �� ���������� �� ������� ���������� �������� ���������� � ����� ������, ����� �� ���������� ��� ������.��, ��� - 1, ���� ������ �� �������.
	void Normalize();// -����� ������� ��� ������� � ������ � � �����������, � ����� � � ��������(���� ��������� �������� ��� ������)
	void PadLeft(int value);// -��������� � ������ ������ ��������� ������������������
	void PadRight(int value);// -��������� � ����� ������ ��������� ������������������
	void PadLeft(int qty, char sim);// -��������� � ������ ������ ������������������� ��������� ��������
	void PadRight(int qty, char sim);// -��������� � ����� ������ ������������������� ��������� ��������
	void Remove(int index);// -�������� ���� �������� �� ����� ������, ������� �� ����������� �������
	void Remove(int index, int qty);// -�������� N ��������, ������� �� �������
	void Replace(char target, char value);// -������ � ������ ��� ��������� ������� target �� ���������� ������ value
	void Replace( String& substr, String& rep);// -�������� ��������� ��������� substr �� ������ rep
	String** Split(char separator, int& pieces);// -����� ���� ������ �� �������, ���������� �������� separator.��������� �� ������ �������� ������� �� �������.� pieces �������������������� ��������.
	String& ToLower();// -������ � ������� ��������(� ��� ����� � ����������� ������)
	String& ToUpper();// -������ � �������� ��������(� ��� ����� � ����������� ������)
	void Trim();// -������� ������ ������� � ������ � � ����� ������
	void TrimEnd();
	void TrimStart();
	void Reverse();// -��������� ������
	void SortAZ();// -���������� ���� �������� ������ � ���������� ������� ��� �� �
	void SortZA();//- ���������� ���� �������� ������ � ���������� ������� �� � �� �
	void Shuffle();// -��������� ������������� �������� ������
	void RandomFill();// -���������� ������ ���������� ���������(�� ����capacity)
	void Insert(String* str, int index);// -������� ��������� � ���� ������, ��������� ����������� �������*/
	
	
	
	
	
	static int Compare(const String& one, const String& two);// -��������� ���� �����(������� 0 ���� ���������, +1 ��� - 1 ���� �� ���������)
	static int Compare(const String& one, const char* two);
};
    
    String*operator+(const String & one, const String & two);
    String* operator+ (const String & origin,const char* str);//- ���������� ������������ 
	String* operator+(const char*str,const String & origin);
	String* operator+(const String & origin,const char sim);
	String* operator+(const char sim,const String & origin);