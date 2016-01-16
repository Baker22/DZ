#include"Vector.h"

Vector::Vector()
{
	count = 0;
	 capacity= 10;
	arr=new int[capacity];
}

Vector::Vector(uint capacity)
{
	SetCount(0);
	SetCapacity(capacity);
	arr = new int[capacity];
}

Vector::Vector(Vector & other)
{
	SetCount(other.count);
	this->capacity=other.capacity;
	arr = new int[capacity];
	for (uint i = 0; i < other.count; i++)
		this->arr[i] = other.arr[i];
}


Vector::~Vector()
{
	ClearArr();
	arr = nullptr;
}

void Vector::SetCount(uint count)
{
	this->count = count;
}

void Vector::SetCapacity(uint capacity)
{
	if (this->capacity == capacity)
		return;
	int arr_size;
	arr_size = (this->count < capacity) ? this->count : capacity;
	int*temp = new int[capacity];
	for (uint i = 0; i < arr_size; i++)
	temp[i] = arr[i];
	this->ClearArr();
	arr = temp;
	count = arr_size;
}


void Vector::FillArr()
{
	for (int i = 0; i < capacity; i++)
	{
	arr[i] = i + 1;
	count++;
	}
		
}
void Vector::Resize()
{
	int*temp = new int[capacity + 10];
	for (uint i = 0; i < count; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
	capacity += 10;
}
char*Vector::ShowVect()
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
	return res;
}
void Vector::AddValue(int value)
{
	if (capacity==count)
		Resize();	
	arr[count] = value;
	count++;
}
void Vector::RemoveValue()
{
	if (!count)
		return;
	arr[count-1] = 0;
	count--;
}
void Vector::ClearArr()
{
	for (; count > 0; count--, arr[count] = 0){}
}
int Vector::IndexOf(int value)
{
	for (uint i = 0; i < count; i++)
	{
		if (arr[i] == value)
		return i;
	}
	 return -1;
}
int Vector::LastIndexOf(int value)
{
	for (uint i = count-1; i >0; i--)
	{
		if (arr[i] == value)
		return i;
	}
	 return -1;
}
void Vector::Insert(uint index, int value)
{
	if (index > capacity-1)
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

void Vector::InsertPlus(uint index, int value)
{
	if (index > capacity-1)
		Resize();
	if (index > count - 1)
	{
		index = count;
		arr[index] = value;
	}
	else
	{
		for (int i = count - 1; i > index; i--)
		arr[i + 1] = arr[i];
	arr[index] = value;
	}
	count++;
}
void Vector::RemoveAt(uint index)
{
	if (index > count - 1)
		return;
	for (uint i = index; i < count; i++)
		arr[i] = arr[i+1];
	arr[count - 1] = 0;
	count--;
}
void Vector::Reverse()
{
	if (count < 2)
		return;
	for (uint i = 0,j = count - 1; i < (count / 2 ); i++, j--)
		swap(arr[i], arr[j]);
}
void Vector::Sort()
{
	if (count < 2)
		return;
	for (uint i = 1; i < count;i++)
	for (uint j = i; j>0 && arr[j] < arr[j - 1]; j--)
		swap(arr[j], arr[j - 1]);
}
void Vector::Shuffle()
{
	for (int i = 0; i < count; i++)
	{
		int index = rand() % count;
		swap(arr[i], arr[index]);
	}
}
bool Vector::operator==(Vector &other)
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
void Vector::operator()(uint capacity)
{
	if (this->capacity == capacity)
		return;
	int arr_size;
	arr_size = (this->count < capacity) ? this->count : capacity;
	int*temp = new int[capacity];
	for (uint i = 0; i < arr_size; i++)
		temp[i] = arr[i];
	this->ClearArr();
	arr = temp;
	count = arr_size;
}

int Vector::operator[](uint index)
{
	if (index>count - 1)
		return -1;
	return arr[index];
}
void Vector::operator+(Vector &other)
{
	for (uint i = 0; i < other.count; i++)
		this->AddValue(other.arr[i]);
}

ostream& operator<<(ostream& os, Vector& arr)
{
	os<< arr.ShowVect() ;
	return os;
}
istream& operator>>(istream& is, Vector& arr)
{
	int capacity;
	is >> capacity;
	arr.SetCapacity(capacity);
		return is;
		//SetCapacity()
}