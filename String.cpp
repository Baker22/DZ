#include"String.h"


String::String()
{
	count=1;
    capacity=80;
	str_arr = new char[80];
	*str_arr = '\0';
}

String::String (uint capacity)
{
	count = 0;
	SetCapacity(capacity);
	str_arr = new char[this->capacity];
}

String::String(char *str)
{
	if (!str) return;
	capacity = strlen(str)+80;
	str_arr = new char[capacity];
	strcpy_s(str_arr, strlen(str) + 1, str);
	count = strlen(str_arr)+1;
}

String::String(char *str, int capacity)
{
	if (!str) return;
	if (capacity<strlen(str)+1)
		this->capacity =strlen(str)+1;
	this->capacity = capacity;
	str_arr = new char[capacity];
	strcpy_s(str_arr, strlen(str) + 1, str);
	count = strlen(str_arr)+1;
}

String::String(const String & origin)
{
	this->count = origin.count;
	char*temp = new char[origin.GetCapacity()];
	strcpy_s(temp, strlen(origin.str_arr) + 1, origin.str_arr);
	delete[]str_arr;
	str_arr = temp;
	this->capacity = origin.GetCapacity();
}

String::String(String& arr, int capacity)
{
	this->capacity = capacity;
	if (capacity < arr.GetCount()) return;
	char*temp = new char[capacity];
	strcpy_s(temp, strlen(arr.GetChar()) + 1, arr.GetChar());
	delete[]str_arr;
	str_arr = temp;
	this->capacity = capacity;
	this->count = strlen(this->str_arr);
}

String::~String()
{
	delete[]str_arr;
	str_arr = nullptr;
	cout << "DestDone\n";
}

void String::Initialize(uint count, uint capacity, char*str)
{
	this->capacity = capacity;
	if (capacity < count || capacity<10)
	this->capacity = capacity + count * 2;
	if (!str)
	{
		this->count = count;
	}	
	else
	{
	char*temp = new char[this->GetCapacity()];
	strcpy_s(temp, strlen(str) + 1, str);
	delete[]str_arr;
	str_arr = temp;
	this->count = strlen(str) + 1;
	}
}

void String::Clear()
{
	this->count = 0;
	this->capacity = 0;
	delete[]str_arr;
	this->str_arr = nullptr;
}

void String::SetCapacity(uint capacity)
{
	this->capacity = capacity;
	if (capacity < 10)
	this->capacity = 10;
	char*temp = new char[this->capacity];
	if (this->GetCount())
	{
	uint size = (this->capacity < count) ? this->capacity : count;
	for (uint i = 0; i < size; i++)
	temp[i] = str_arr[i];
	temp[size] = '\0';
	this->count = strlen(this->GetChar())+1;
	}
	delete[]str_arr;
	str_arr = temp;
}

void String::AddSim(char sim)
{
	if (count == capacity) Resize(capacity+80);
	str_arr[GetCount()-1] = { sim };
	count++;
	str_arr[GetCount()-1] = { '\0' };
}

void String::Resize(uint qty)
{
	if (!qty)
	{
	Clear();
	return;
	}
		
	char*temp = new char[qty];
	if (qty < this->GetCount())
	{
	for (uint i = 0;i< qty-1; i++)
	temp[i]=str_arr[i];
	temp[qty-1] = '\0';
	}
	else
	{
		if (this->GetCount())
		strcpy_s(temp, strlen(this->GetChar()) + 1,this->GetChar());
	}
	delete[]str_arr;
	str_arr = temp;
	count = strlen(str_arr)+1;
	capacity = qty;
}

char String::GetSim(uint index)const
{
	char res = str_arr[index];
	return res;
}

char*String::GetChar()const
{
	if (!count) return "0";
		char*res = new char[strlen(str_arr) + 1];
	strcpy_s(res, strlen(str_arr) + 1, str_arr);
		return res;
}

void String::Print()const
{
	cout<< GetChar();
}

int String::Compare(const String& one,const String& two)
{
	if (one.GetCount() != two.GetCount()) return -1;
	uint size = one.GetCount();
	for (uint i = 0; i < size; i++)
	{
		if (one.GetSim(i) == two.GetSim(i)) continue;
		else return -1;		
	}
	return 0;
}

int String::Compare(const String& one, const char* two)
{
	if (strlen(one.GetChar()) != strlen(two)) return -1;
	uint size = strlen(two);
	for (uint i = 0; i < size; i++)
	{
		if (one.GetSim(i) == two[i]) continue;
	else return -1;
	}
	return 0;
}

String*operator+(const String & one, const String & two)
 {
	 if (sizeof(one) == 0 && sizeof(two) == 0) return 0;
	 char*st = new char[strlen(one.GetChar()) +strlen(two.GetChar())  + 1];
	 strcpy_s(st, strlen(one.GetChar()) + 1,one.GetChar());
	 strcat_s(st, strlen(one.GetChar()) + strlen(two.GetChar()) + 1,two.GetChar());
	 String* temp = new String(st);
	 return temp;
	 return 0;
 }

 String* operator+ (const String & origin,const char* str)
{
	 
	 if (sizeof(origin) == 0 && sizeof(str) == 0) return 0;
	 char*st = new char[strlen(origin.GetChar()) +strlen(str)+1];
	 strcpy_s(st, strlen(str)+1, str);
	 strcat_s(st, strlen(origin.GetChar()) + strlen(str) + 1,origin.GetChar());
	 String* temp = new String (st);
	 return temp;		 
}

 String* operator+(const char*str, const String & origin)
 {
	 if (sizeof(origin) == 0 && sizeof(str) == 0) return 0;
	 char*st = new char[strlen(origin.GetChar()) +strlen(str)+1];
	 strcpy_s(st, strlen(origin.GetChar())+1,origin.GetChar());
	 strcat_s(st,strlen(str) + strlen(origin.GetChar()) + 1,str);
	 String* temp = new String (st);
	 return temp;		 
 }

 String* operator+(const String & origin, const char sim)
 {
	 char str[] = { sim, '\0' };
	 String*temp = new String;
	 temp = operator+(str,origin );
	 return temp;
 }

 String* operator+(const char sim, const String & origin)
 {
	 char str[] = { sim, '\0' };
	 String*temp = new String;
	 temp = operator+(origin,str );
	 return temp;
 }

 String& String::operator=(const String & other)
 {
	 if (this != &other)
	 {
	 this->count = other.GetCount();
	 this->capacity = other.GetCapacity();
	 delete[]this->str_arr;
	 this->str_arr = other.GetChar();
	 return *this;
	 }
	 return *this;
 }

 bool String::operator==(const String & other)
 {
	 if (this->GetCount() != other.GetCount()) return false;
	 uint size = this->GetCount();
	 for (uint i = 0; i < size; i++)
	 {
		 if (this->GetSim(i) == other.GetSim(i)) continue;
		 else return false;
	 }
	 return true;
 }

 bool String::operator>(const String & other)
 {
	 if (this->GetCount() > other.GetCount()) 
	 return true;
	 return false;
 }

 bool String::operator<(const String & other)
 {
	 if (this->GetCount() < other.GetCount()) 
	 return true;
	 return false;
 }

 bool String::operator>=(const String & other)
 {
	 if (this->GetCount() >= other.GetCount()) 
	 return true;
	 return false;
 }

 bool String::operator<=(const String & other)
 {
	 if (this->GetCount() <= other.GetCount()) 
	 return true;
	 return false;
 }

 bool String::operator!=(const String & other)
 {
	 if (this->GetCount() != other.GetCount()) return true;
	 uint size = this->GetCount();
	 for (uint i = 0; i < size; i++)
	 {
		 if (this->GetSim(i) == other.GetSim(i)) continue;
		 else return true;
	 }
	 return false;
 }

 void String::operator()(char*str, uint capacity, uint count)
 {
	 Initialize(count, capacity, str);
 }

 char String::operator[](uint index)
 {
	 return GetSim(index);
 }

 String& String::operator+=(const String & other)
 {
	 if (other.GetCount())
	 {
		 if (this->GetCount() + other.GetCount() > this->capacity)
		 Resize((this->count + other.GetCount()) * 2);
		 strcat_s(this->str_arr, this->GetCapacity(), other.GetChar());
		 this->count = strlen(this->GetChar())+1;
	 }
	 return *this;
 }

 String& String::operator+=(const char*str)
 {
	 if (str)
	 {
		 if (this->count + strlen(str) > this->capacity)
		 Resize((this->count + strlen(str)) * 2);
		 strcat_s(this->str_arr, this->capacity, str);
		 this->count = strlen(this->str_arr);
	 }
	 return *this;
 }

 ostream & operator<<(ostream& os, String& arr)
 {
	 os << arr.GetChar();
	 return os;
 }

 istream & operator>>(istream& is, String& arr)
 {
	 char*temp = new char[250];
	 is >> temp;
	 arr+=(temp);
	 return is;
 }

 String::operator char*()
 {
	 return GetChar();
 }

 String::operator int()
 { 
	 return atoi(GetChar());
 }

 String::operator double()
 {
	 return atof(GetChar());
 }

 void String::PrintLn()
 {
	 if (this->GetCount() == 0 || this->GetSim(0) == '\0') return;
	 char end[2] = { '\n', '\0' };
	 char*temp = new char[strlen(GetChar()) + 2];
	 strcpy_s(temp, strlen(GetChar())+1, GetChar());
	 strcat_s(temp, strlen(GetChar()) + 2, end);
	 cout << temp;
 }

 void String::GetLine()
 {
	 char*buf = new char[250];
	 cin.getline(buf, 249);
	 cin.clear();
	 cin.sync();
	 this->operator+=(buf);
 }

 const String*String::GetString()const
 {
	 return this ;
 }

 int String::CompareTo(String& other)
 {
	 return Compare(*this, other);
 }

 int String::CompareTo(char* str)
 {
	 return Compare(*GetString(), str);
 }

 void String::Concat(String & other)
 {
	 *this += other;
 }

 void String::Concat(char* str)
 {
	 *this += str;
 }

 void String::Concat(int num)
 {
	 int size=1;
	 for (uint i = num; i > 0; i /= 10, size++);
	 char*temp = new char[250];
	 _itoa_s(num, temp, size, 10);
	 *this += temp;
 }

 void String::Concat(double num)
 {
	 int _int = (int)num;
	 int size_int = 1;
	 char*temp = new char[250];
	 for (uint i = _int; i > 0; i /= 10, size_int++);
    _itoa_s(_int, temp, size_int, 10);
     strcat_s(temp, 250, ",");

	 double numm = num;
	 int size_double = 1;
	 do
	 {
		 numm*=10;
		 size_double++;
	 }
	 while (numm - (int)numm>0&&numm<100000);
	 
	 int a =1;
	 for (int i = 0; i < size_double-1; i++, a *= 10);
	 int  _double= numm - _int*a;
	 char*temp2 = new char[250];
	 _itoa_s(_double, temp2, size_double, 10);
	 strcat_s(temp, 250, temp2);
	 *this += temp;
 }

 void String::Concat(String*other, int count)
 {
	 if (count<other->count)
	 for (int i = 0; i < count; i++)
		 AddSim(other->GetSim(i));
 }

 bool String::Contains(char*text)
 {
	 if (GetCount())
	 {
		 int count = 0;
	 for (int i = 0; i < GetCount(); i++)
	 {
		 if (str_arr[i] == text[0])
		 {
			 for (int j = 0; j < strlen(text); j++)
			 if (str_arr[j] == text[j])
				 count++;
			 if (count == strlen(text)) break;
		 }
		 else count = 0;
	 }
	 return count;
	 }
	 return false;
 }

 bool String::EndsWith(char*text)
 {
	 if (GetCount())
	 {
		 int count = 0;
		 if (str_arr[GetCount()] == text[strlen(text)])
		 {
			 int i = GetCount()-1;
			 for (int j =strlen(text)-1; j >=0; j--,i--)
			 if (str_arr[i] == text[j])
				 count++;
			 if (count == strlen(text))
				 return true;
				 return false;
		 }
		 return false; 
	 }
	 return false; 
	 }

 bool String::StartsWith(char*text)
 {
	 if (GetCount())
	 {
		 int count = 0;
		 if (str_arr[0] == text[0])
		 {
			 for (int j = 0; j < strlen(text); j++)
			 if (str_arr[j] == text[j])
				 count++;
			 if (count == strlen(text))
				 return true;
			 return false;
		 }
		 else return false;
	 }
	 return false;
 }

 void String::CopyTo(String& other)
 {
	 if (this->GetCount())
	 other.operator+=(*this);
 }
	 
 int String::IndexOf(char sim)
 {
	 if (GetCount())
	 {
		 for (int i = 0; i < GetCount(); i++)
		 {
			 if (str_arr[i] == sim)
		 return i;
		 }
		 return -1;
	 } 
	 else return -1;
 }

 int String::LastIndexOf(char sim)
 {
	 if (GetCount())
	 {
		 for (int i =GetCount();i>=0; i--)
		 {
			 if (str_arr[i] == sim)
		 return i;
		 }
		 return -1;
	 } 
	 else return -1;
 }

 int String::IndexOf(char*str)
 {
	 if (GetCount()&&str)
	 {
		 int index;
		 int count = 0;
		 for (uint i = 0; i < GetCount()-strlen(str);i++)
		 {
			 if (str_arr[i] == str[0])
			 {
				 for (uint j = 0; j < strlen(str); j++,i++)
			 {
				 if (str_arr[i] == str[j])
			 {
				 count++;
			 index = (i-count)+1;
			 }
			 if (count == strlen(str))
				 return index;
			 }
			 }
			 
			 
		 }
	 }
	 return -1;
 }

 int String::LastIndexOf(String*str)
 {
	 if (GetCount() && str)
	 {
		 int index;
		 int counter = 0;
		 int i =this-> GetCount()-2;
		 int k = str->GetCount() - 2;
		 for (; i > str->GetCount()-1;i--)
		 if (this->str_arr[i] == str->str_arr[k])
			 {
				 for (int j =str->GetCount()-2; j >=0,i>0; i--)
				 {
					 if (str_arr[i] == str->str_arr[j])
					 {
						 counter++;
						 index =i;
						 j--;
					 }
					 else
					 {
						 if (counter)
					     j =str->GetCount()-2;
						 counter = 0;
					 }
						 
					 if (counter == str->GetCount()-1)
						 return index;
				 }
			 }
		 }
	 return -1;
 }

 int String::IndexOfAny(String*str)
 {
	 int maxm = str->GetCount();
	 int maxs = this->GetCount();
	 for (int i = 0; i < maxm; i++)
	 {
		 for (int j = 0; j < maxs; j++)
		 {
			 if (this->str_arr[i] == str->str_arr[j])
				 return i;
		 }
		 
	 }
	 return -1;
 }
 
 void String::Normalize()
 {
	 if (this->count > 1)
	 {
	 int counter = 0;
	 int counter1 = 0;
	 int pos_1=0;
	 int pos_2 = GetCount()-2;
	 for (int i = 0; GetSim(i) == ' '; i++,pos_1=i ,counter++);
	 for (int j = GetCount()-2; GetSim(j) == ' '; --j,pos_2=j ,counter++);
	 for (int a = pos_1; a < pos_2; a++)
	 {
		 if (GetSim(a) == ' ')
			 counter1++;
		 else
		 {
			 if (counter1>1)
			 {
				 counter++; 
			 }
			 counter1= 0;
		 }
	 }
	 char*temp = new char[this->capacity];
	 int t = 0;
	 for (int b = pos_1; b <= pos_2+1; b++)
	 {
		 if (GetSim(b) != ' '||GetSim(b+1)!=' ')
		 { 
			 temp[t] = GetSim(b);
			 t++; 
		 }
	 }
	 if (temp[t] != '\0')
	 temp[t] = '\0';
	 delete[]str_arr;
	 str_arr = temp;
	 this->count = strlen(str_arr)+1; 
	 }
	 
 }

 void String::PadLeft(int value)
 {
	 if (this->GetCount() + value > this->capacity)
		 Resize(value + this->capacity + 80);
	 int j = GetCount() - 1;
	 for (int i = value + this->GetCount()-1; i >=value; i--, j--)
		 this->str_arr[i] = this->str_arr[j];
	 for (int a = 0; a < value; a++)
		 this->str_arr[a] =' ';
	 this->count = strlen(this->GetChar())+1;
 }

 void String::PadRight(int value)
 {
	 if (this->GetCount() + value>this->capacity)
		 Resize(value+this->capacity+80);
	 int i = 0;
	 while (i < value)
	 {
		 i++;
		 AddSim('#');
	 }
 }

 void String::PadLeft(int qty, char sim)
 {
	 if (this->GetCount() + qty > this->GetCapacity())
		 Resize(qty + this->GetCapacity() + 80);
	 int j = GetCount() - 1;
	 for (int i = qty + this->GetCount() - 1; i >= qty; i--, j--)
	 {
		 this->str_arr[i] = this->str_arr[j];
	 } 
	 for (int a = 0; a < qty; a++)
		 this->str_arr[a] = sim;
	 this->count = strlen(this->GetChar())+1;
 }

 void String::PadRight(int qty, char sim)
 {
	 if (this->GetCount() + qty>this->capacity)
		 Resize(qty + this->capacity + 80);
	 int i = 0;
	 while (i < qty)
	 {
		 i++;
		 AddSim(sim);
	 }
 }

 void String::Remove(int index)
 {
	 if (index < this->GetCount() - 1)
	 {
		 for (int i = index; i < this->GetCount(); i++)
		 str_arr[i] = '\0';
	 }
	 this->count = strlen(str_arr) + 1;
 }

 void String::Remove(int index, int qty)
 {
	 if (index < this->GetCount() - 1&&qty<this->GetCount()-1-index)
	 {
		 int j = qty+index;
		 for (int i = index; j < this->GetCount(); i++,j++)
		 str_arr[i] =str_arr[j] ;
	 }
	 this->count = strlen(str_arr) + 1;
 }

 void String::Replace(char target, char value)
 {
	 if (this->GetCount())
	 for (int i = 0; i < GetCount() - 1; i++)
	 {
		 if (GetSim(i) == target)
			 str_arr[i] = value;
	 }
 }

 void String::Replace(String& substr, String& rep)
 {
	 if (this->GetCount())
	 {
		 if (this->GetCount() + strlen(rep) > this->GetCapacity())
			 Resize(this->GetCapacity() + strlen(rep) + 80);
		 int index = LastIndexOf(&substr);
		 if (index > 0)
		 {
			 char*temp = new char[this->GetCapacity()];
			 uint i = 0;
			 for (; i < index; i++)
				 temp[i] = str_arr[i];
			 for (uint j = 0; j < strlen(rep); j++,i++)
				 temp[i] = rep[j];
			 for (uint k = index + strlen(rep); k < this->GetCount(); k++,i++)
				 temp[i] = str_arr[k];
			 strcpy_s(str_arr, strlen(temp) + 1, temp);
			 this->count = strlen(this->GetChar()) + 1;
		 }
	 }
 }

 String** String::Split(char separator, int& pieces)

 {
	  pieces= 1;
	 for (int i = 0; i < this->GetCount(); i++)
	 {
		 if (this->str_arr[i] == separator)
			 pieces++;
	 }
	 String**res = new String*[pieces];
	 int piec = 0;
	 int j = 0;
	 for (; piec < pieces; piec++)
	 {
		 res[piec] = new String;
	 for (; this->GetSim(j) != separator&&this->GetSim(j) !='\0'; j++)
	 {
		 res[piec]->AddSim(GetSim(j));
	 }
		 res[piec]->AddSim('\0');
		 j++;
	 }
	 
	 return res;
 }

 String& String::ToLower()
 {
	 if (this->count > 1)
	 {
		 for (uint i = 0; i < this->GetCount();i++)
		 if (((int)this->str_arr[i] >= 65 && (int)this->str_arr[i] <= 90) || ((int)this->str_arr[i] >= 192 && (int)this->str_arr[i] <= 223))
			 this -> str_arr[i] += 32;
	 }
	 return *this;
 }

 String& String::ToUpper()
 {
	 if (this->count > 1)
	 {
		 for (uint i = 0; i < this->GetCount();i++)
		 if (((int)this->str_arr[i] >= 97 && (int)this->str_arr[i] <= 122) || ((int)this->str_arr[i] >= 224 && (int)this->str_arr[i] <= 255))
			 this -> str_arr[i] -= 32;
	 }
	 return *this;
 }

 void String::Trim()
 {
	 if (this->count > 1)
	 {
		 int counter = 0;
		 int counter1 = 0;
		 int pos_1 = 0;
		 int pos_2 = GetCount() - 2;
		 for (int i = 0; GetSim(i) == ' '; i++, pos_1 = i, counter++);
		 for (int j = GetCount() - 2; GetSim(j) == ' '; --j, pos_2 = j, counter++);
		 char*temp = new char[this->capacity];
		 int t = 0;
		 for (int b = pos_1; b <= pos_2 + 1; b++)
		 {
				 temp[t] = GetSim(b);
				 t++;
		 }
		 if (temp[t] != '\0')
			 temp[t] = '\0';
		 delete[]str_arr;
		 str_arr = temp;
		 this->count = strlen(str_arr) + 1;
	 }
 }

 void String::TrimEnd()
 {
	 if (this->count > 1)
	 {
		 int counter = 0;
		 int counter1 = 0;
		 int pos_1 = 0;
		 int pos_2 = GetCount() - 2;
		 for (int j = GetCount() - 2; GetSim(j) == ' '; --j, pos_2 = j, counter++);
		 char*temp = new char[this->capacity];
		 int t = 0;
		 for (int b = pos_1; b <= pos_2 + 1; b++)
		 {
				 temp[t] = GetSim(b);
				 t++;
		 }
		 if (temp[t] != '\0')
			 temp[t] = '\0';
		 delete[]str_arr;
		 str_arr = temp;
		 this->count = strlen(str_arr) + 1;
	 }
 }

 void String::TrimStart()
 {
	 if (this->count > 1)
	 {
		 int counter = 0;
		 int counter1 = 0;
		 int pos_1 = 0;
		 int pos_2 = GetCount() - 2;
		 for (int i = 0; GetSim(i) == ' '; i++, pos_1 = i, counter++);
		 char*temp = new char[this->capacity];
		 int t = 0;
		 for (int b = pos_1; b <= pos_2 + 1; b++)
		 {
			 temp[t] = GetSim(b);
			 t++;
		 }
		 if (temp[t] != '\0')
			 temp[t] = '\0';
		 delete[]str_arr;
		 str_arr = temp;
		 this->count = strlen(str_arr) + 1;
	 }
 }

 void String::Reverse()
 {
	 if (this->GetCount() > 2)
	 {
		 int i = 0;
	 int j = this->GetCount() - 2;
	 int middle = j / 2;
	 for (; i < middle; i++, j--)
		 swap(str_arr[i], str_arr[j]);
	 }
 }

 void String::SortAZ()
 {
	 if (this->GetCount() > 2)
	 {
		 for (int i = 1; i < this->GetCount()-2; i++)
	 for (int j = i; j>0 && (int)str_arr[j] < (int)str_arr[j - 1]; j--)
		 swap(str_arr[j], str_arr[j - 1]);
	 } 
 }

 void String::SortZA()
 {
	 if (this->GetCount() > 2)
	 {
		 for (int i = 1; i < this->GetCount()-2; i++)
	 for (int j = i; j>0 && (int)str_arr[j] > (int)str_arr[j - 1]; j--)
		 swap(str_arr[j], str_arr[j - 1]);
	 }
	 
 }

 void String::Shuffle()
 {
	 if (this->GetCount() > 2)
	 {
	 uint max = this->GetCount() - 2;
	 int min = 0;
	 for (int i = 0; i <max ; i++)
	 {
		 swap(str_arr[rand() % max], str_arr[rand() % max]);
	 }
	 }
	 
 }

 void String::RandomFill()
 {
	 if (this->GetCapacity() > 2)
	 {
		 for (int i = 0; i < this->GetCapacity() - 1; i++)
		 this->str_arr[i] = (char)rand() % 250;
	 this->str_arr[this->GetCapacity() - 1] = '\0';
	 this->count = strlen(this->str_arr) + 1;
	 }
 }

 void String::Insert(String* str, int index)
 {
	 if (index < this->GetCount() - 1&&index > 0)
	 {
		 if (index + this->GetCount()>this->capacity)
			 Resize(index + this->capacity + 80);
			 char*temp = new char[this->GetCapacity()];
			 uint i = 0;
			 uint k = 0;
			 for (; i < index; i++,k++)
				 temp[i] = str_arr[k];
			 for (uint j = 0; j < strlen(str->str_arr); j++, i++)
				 temp[i] = str->str_arr[j];
			 for (; i < this->GetCount()+strlen(str->str_arr) + 2;i++,k++)
				 temp[i] =str_arr[k];
			 strcpy_s(str_arr, strlen(temp) + 1, temp);
			 this->count = strlen(this->GetChar()) + 1;
	 }
 }
 