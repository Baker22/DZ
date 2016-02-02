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
	String();//конструктор по умолчанию, который создаёт пустую строку (но capacity= 80)
	explicit String(uint capacity);//explicit-конструктор с 1 параметром типа int (задаёт capacity, с проверкой что вместительность больше 10)
	void SetCapacity(uint capacity);
	String(const char *str);// (формирует строку наоснове переданного указателя на массив char[], с проверкой - не пустой ли указатель!)
	String(const String & origin);//конструктор копирования)
	String(char *str, uint capacity);//конструктор с 2 параметрами- char* и int (указатель на строку, вместительность)
    String(String& arr, int capacity);//конструктор с 2 параметрами - String и int (указатель на строку, вместительность)
	~String();
	void Initialize(uint count, uint capacity, char*str);
	int GetCount()const{ return this->count; }// -длина строки
	int GetCapacity()const{ return this->capacity; }//- вместительность строки
	void Print()const; //-показ строки на экран
	void AddSim(char sim);
	void Resize(uint qty);// -изменение количества символов, по сути - обрезкастроки)
	char GetSim(uint index)const;
	char*GetChar()const;
	String& operator=(const String & other);
	bool operator==(const String & other);// (лексикографическое сравнение двух строк)
	bool operator>(const String & other);
	bool operator<(const String & other);
	bool operator>=(const String & other);
	bool operator<=(const String & other);
	bool operator!=(const String & other);
	void operator()(char*str, uint capacity, uint count);//(повторная инициализация строки)
	char operator[](uint index);//(доступ к элементу строки по индексу, предусмотреть возможность обращения к несуществующему элементу.
    void Clear();//- очистка строки
	String& operator+=(const String & other);//(конкатенация String)
	String& operator+=(const char*str);//(конкатенация char*)
	friend ostream & operator<<(ostream& os, String& arr);
	friend istream & operator>>(istream& is, String& arr);
	operator char*();//- преобразование в char*
	operator int();//- конвертация строки в целое число (если это возможно)
    operator double();//- конвертация строки в вещественное число(если это возможно)
	void PrintLn();//- показ строки на экран с переводом курсора на следующую строку
	void GetLine();//- ввод строки с клавиатуры
	const String*GetString()const;//- возврат константного указателя на объект
	int CompareTo(String& other);// -сравнение нашей строки с какой - то другой строкой
	int CompareTo(char* str);//-сравнение нашей строки с какой - то другой строкой
	void Concat(String & other);//- присоединить к нашей строке переданную строку
	void Concat(char* str);//- присоединить к нашей строке переданную строку
	void Concat(int num);//- присоединить к нашей строке переданную строку
	void Concat(double num);//- присоединить к нашей строке переданную строку
	void Concat(String*other,int count);//- присоединить к нашей строке по очереди count элементов массива String'ов
	bool Contains(char*text);// -проверить, содержится ли в нашей строке переданная подстрока(в любой позиции)
	bool EndsWith(char*text);//- проверить, заканчивается ли наша строка текстом, который передан в параметре
	bool StartsWith(char*text);//- проверить, начинается ли наша строка текстом, который передан в параметре
	void CopyTo(String& other);//- скопировать текст нашей строки в другую строку
	int IndexOf(char sim);//- проверка на вхождение символа в строку, в результате работы возвращает индекспервого найденного символа(от начала строки).eсли ничего не найдено,возвращает - 1.
	int LastIndexOf(char sim);//- проверка на вхождение символа в строку, в результате работы возвращает индекспоследнего найденного символа(поиск с конца строки).eсли ничего ненайдено, возвращает - 1.
	int IndexOf(char*str);// -проверка на вхождение подстроки в строку, врезультате работы возвращает индексначала вхождения.eсли ничего не найдено, возвращает - 1.
	int LastIndexOf(String*str);// -проверка на вхождение подстроки в строку, в результате работы возвращает индекс начала вхождения(но поиск идёт с конца строки).eсли ничего ненайдено, возвращает - 1.
	int IndexOfAny(String*str);// -переданный параметр состоит из массива символов, верно ? так вот, если хотя бы одинсимвол из массива переданных символов содержится в нашей строке, мытут же возвращаем его индекс.ну, или - 1, если ничего не найдено.
	void Normalize();// -метод убирает все пробелы в начале и в концестроки, а также в её середине(если несколько пробелов идёт подряд)
	void PadLeft(int value);// -добавляет в начало строки указанное количествопробелов
	void PadRight(int value);// -добавляет в конец строки указанное количествопробелов
	void PadLeft(int qty, char sim);// -добавляет в начало строки указанноеколичество указанных символов
	void PadRight(int qty, char sim);// -добавляет в конец строки указанноеколичество указанных символов
	void Remove(int index);// -удаление всех символов до конца строки, начиная от переданного индекса
	void Remove(int index, int qty);// -удаление N символов, начиная от индекса
	void Replace(char target, char value);// -меняет в строке все найденные символы target на переданный символ value
	void Replace( String& substr, String& rep);// -заменяет найденную подстроку substr на строку rep
	String** Split(char separator, int& pieces);// -делит нашу строку на кусочки, разделённые символом separator.указатель на массив кусочков вернётся из функции.в pieces завпишетсяколичество кусочков.
	String& ToLower();// -привод к нижнему регистру(в том числе и длярусского текста)
	String& ToUpper();// -привод к верхнему регистру(в том числе и длярусского текста)
	void Trim();// -убирает лишние пробелы в начале и в конце строки
	void TrimEnd();
	void TrimStart();
	void Reverse();// -переворот строки
	void SortAZ();// -сортировка всех символов строки в алфавитном порядке отА до Я
	void SortZA();//- сортировка всех символов строки в алфавитном порядке от Я до А
	void Shuffle();// -случайное перемешивание символов строки
	void RandomFill();// -заполнение строки случайными символами(на весьcapacity)
	void Insert(String* str, int index);// -вставка подстроки в нашу строку, начинаяот переданного индекса*/
	
	
	
	
	
	static int Compare(const String& one, const String& two);// -сравнение двух строк(возврат 0 если совпадают, +1 или - 1 если не совпадают)
	static int Compare(const String& one, const char* two);
};
    
    String*operator+(const String & one, const String & two);
    String* operator+ (const String & origin,const char* str);//- реализация конкатенации 
	String* operator+(const char*str,const String & origin);
	String* operator+(const String & origin,const char sim);
	String* operator+(const char sim,const String & origin);