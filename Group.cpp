#include"Group.h"

Group::Group()
{
	group_size = 0;
	group_name = nullptr;
	group_spec = nullptr;
	course_num = nullptr;
}

Group::Group(char*group_name, char*group_spec, char*course_num)
{
	SetName(group_name);
	SetSpec(group_spec);
	SetNum(course_num);
}


Group::~Group()
{
	if (*group_name)
		delete[]students;
	students = nullptr;
	if (*group_spec)
		delete[]students;
	students = nullptr;
	if (*course_num)
		delete[]students;
	students = nullptr;
	
};
void Group::SetName(char*group_name)
{
	if (this->group_name)
	delete[]this->group_name;
	this->group_name = nullptr;
	this->group_name = new char[strlen(group_name) + 1];
	strcpy_s(this->group_name, strlen(group_name) + 1, group_name);
}

void Group::SetSpec(char*group_spec)
{
	if (this->group_spec)
	delete[]this->group_spec;
	this->group_spec = nullptr;
	this->group_spec = new char[strlen(group_spec) + 1];
	strcpy_s(this->group_spec,strlen(group_spec) + 1, group_spec);
}
void Group::SetNum(char*course_num)
{
	if (this->course_num)
		delete[]this->course_num;
	this->course_num = nullptr;
	this->course_num = new char[strlen(course_num) + 1];
	strcpy_s(this->course_num, strlen(course_num) + 1, course_num);
}
Group::Group(ushort group_size)
{
	if (!group_size)
		return;
	SetName("No group name");
	SetSpec("Not group spec");
	SetNum("Not course number");
	//this->group_size = group_size;
	Student *temp;
		for (int i = 0; i < group_size; i++)
		{
			temp = new Student("Not phone", "Not name", "Not secondname", "Not lastname");
		AddStudToGroup(*temp);
		}	
		delete[]temp;
}

char*Group::Getter(char*str)const
{
	char*temp = new char[strlen(str)+1];
	strcpy_s(temp, strlen(str) + 1, str);
	return temp;
}

char*Group::GetGroup_name()const
{
	return Getter(this->group_name);
}

char*Group::GetGroup_spec()const
{
	return Getter(this->group_spec);
}

char*Group::GetCourse_num()const
{
	return Getter(this->course_num);
}

void Group::AddStudToGroup(Student & student)
{
	Student**buf = new Student*[group_size + 1];
	if ((group_size + 1) < 30)	
	for (int i = 0; i < group_size; i++)
		buf[i] = &(*this->students[i]);
	buf[group_size] = &student;
	if (this->students)
		delete[]this->students;
	this->students = buf;
	group_size++;
}

Group::Group(Group & other)
{
	group_name = nullptr;
	group_spec = nullptr;
	course_num = nullptr;
	Group(other.group_name, other.group_spec, other.course_num);
	this->group_size =other.group_size ;
	for (int i = 0; i < other.group_size; i++)
		this->students[i] =other.students[i] ;
}

char*Group::GroupList()
{
	SortStud();
	ushort capasity = 250;
	char*temp = new char[capasity];
	strcpy_s(temp, strlen(GroupInfo()) + 1, GroupInfo());
	for (int i = 0; i < group_size; i++)
	{
		if (capasity < strlen(temp) + 50)
			capasity +=100;
		char*a = new char[3];
		_itoa_s(i + 1, a, 3, 10);
		strcat_s(temp, capasity, a);
		strcat_s(temp, capasity, ")");
		strcat_s(temp, capasity, (*students[i]).FullName());
		strcat_s(temp, capasity, "\n");

	}
		
	char*res = new char[strlen(temp) + 1];
	strcpy_s(res, strlen(temp) + 1, temp);
	return res;
}

char*Group::GroupInfo()
{
    char*temp = new char[250];
	strcpy_s(temp, strlen(GetGroup_spec()) + 1, GetGroup_spec());
	strcat_s(temp, 250, ",");
	strcat_s(temp, 250, GetGroup_name());
	strcat_s(temp, 250, "-");
	strcat_s(temp, 250, GetCourse_num());
	strcat_s(temp, 250, ":\n");
	char *res = new char[strlen(temp)+1];
	res = temp;
		return res;
}

void Group::GroupUnion(Group &some)
{
	if (!some.group_size)
		return;
	if (this->group_size + some.group_size > 30)
		return;
	for (int i = 0; i < some.group_size; i++)
		AddStudToGroup(*some.students[i]);
}

void Group::SortStud()
{
	if (group_size < 2)
		return;
	char * name1 = new char[255];
	char * name2 = new char[255];
	for (int i = 0; i < group_size-1; i++)
	{
		name1 = students[i]->GetLastname();
		name2 = students[i + 1]->GetLastname();
		if (_stricmp(name1,name2) < 0)
	  {
			Student*temp = students[i];
			students[i] = students[i + 1];
			students[i + 1] = temp;		
	  }
	}
}

void Group::StudDelete(ushort stud_num)
{
	if (group_size < stud_num)
		return;
	Student**temp=new Student*[group_size-1];
	for (int i= 0; i<stud_num-1 ; i++)
	{
		temp[i] = students[i];
	}
	for (int j = stud_num-1; j < group_size; j++)
		temp[j] = students[j + 1];
	group_size--;
	delete[]students;
	students = temp;

}
void Group::StudMove(Group &target,ushort stud_num)
{
	if (this->group_size < stud_num)
		return;
	target.AddStudToGroup (*this->students[stud_num - 1]);
	StudDelete(stud_num);
}

void Group::operator=(Group&other)
{
	SetName(other.group_name);
	SetSpec(other.group_spec);
	SetNum(other.course_num);
	this->group_size = other.group_size;
	for (int i = 0; i < other.group_size; i++)
		AddStudToGroup(*other.students[i]);
}

char*Group:: operator[](ushort num)
{
	return (*students[num - 1]).FullName();
}