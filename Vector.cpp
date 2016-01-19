#include"Vector.h"

Vector::Vector()

{
	count = 0;
	capacity = 10;
	arr = new int[capacity];
}

Vector::Vector(uint capacity)
{
	SetCount(0);
	SetCapacity(capacity);
	arr = new int[capacity];
}

Vector::Vector(const Vector & other)
{
	this->count = other.GetCount();
	this->capacity = other.GetCapacity();
	arr = new int[capacity];
	for (uint i = 0; i < other.count; i++)
		arr[i] = other.arr[i];
}


Vector::~Vector()
{

	ClearArr();
	cout << "DEST DONE\n";
}

void Vector::SetCount(uint count)
{
	this->count = count;
}

void Vector::SetCapacity(uint capacity)
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


void Vector::FillArr()
{
	for (uint i = 0; i < capacity; i++)
	{
		this->arr[i] = (i + 1);
		this->count++;
	}

}
void Vector::Resize()
{
	int*temp = new int[capacity + 10];
	for (uint i = 0; i < count; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;

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
	delete[]temp;
	return res;
}
void Vector::AddValue(int value)
{
	if (capacity == count)
		Resize();
	arr[count] = value;
	count++;
}
void Vector::RemoveValue()
{
	if (!count)
		return;
	arr[count - 1] = 0;
	count--;
}
void Vector::ClearArr()
{
	delete[]arr;
	arr = nullptr;
	count = 0;
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
	for (uint i = count - 1; i >0; i--)
	{
		if (arr[i] == value)
			return i;
	}
	return -1;
}
void Vector::Insert(uint index, int value)
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

void Vector::InsertPlus(uint index, int value)
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
void Vector::RemoveAt(uint index)
{
	if (index > count - 1)
		return;
	for (uint i = index; i < count - 1; i++)
		arr[i] = arr[i + 1];
	arr[count - 1] = 0;
	count--;
}
void Vector::Reverse()
{
	if (count < 2)
		return;
	for (uint i = 0, j = count - 1; i < (count / 2); i++, j--)
		swap(arr[i], arr[j]);
}
void Vector::Sort()
{
	if (count < 2)
		return;
	for (uint i = 1; i < count; i++)
	for (uint j = i; j>0 && arr[j] < arr[j - 1]; j--)
		swap(arr[j], arr[j - 1]);
}
void Vector::Shuffle()
{
	for (uint i = 0; i < count; i++)
	{
		int index = rand() % count;
		if (i == index)continue;
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
	int*temp = new int[capacity];
	int arr_size = (this->count < capacity) ? this->count : capacity;
	for (int i = 0; i < arr_size; i++)
		temp[i] = arr[i];
	delete[]this->arr;
	this->arr = temp;
	count = arr_size;
}

int Vector::operator[](uint index)
{

	if (index>count - 1)
		return -1;
	return arr[index];
}

Vector Vector::operator+(const Vector &other)
{
	int*temp_arr = new int[this->capacity + other.capacity];
	for (uint i = 0; i < this->count; i++)
		temp_arr[i] = this->arr[i];
	for (uint i = 0; i < other.count; i++)
		temp_arr[this->count + i] = other.arr[i];
	delete[]this->arr;
	arr = temp_arr;
	return *this;

}

ostream& operator<<(ostream& os, Vector& arr)
{
	os << arr.ShowVect();
	return os;
}
istream& operator>>(istream& is, Vector& arr)
{
	int capacity;
	is >> capacity;
	arr.SetCapacity(capacity);
	return is;
}