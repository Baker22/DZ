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
	group_name = "Not yet info";
	group_spec = "Not yet info";
	course_num = "Not yet info";
	Student *buf;
	if ((this->group_size+group_size)<30)
	{
		for (int i = 0; i < group_size; i++)
		{
			buf = new Student("Not info", "Not info", "Not info", "Not info");
		AddStudToGroup(*buf);
		}
		
	}		
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
	Group(other.group_name, other.group_spec, other.course_num);
	other.group_size = this->group_size;
	for (int i = 0; i < other.group_size; i++)
		other.students[i] = this->students[i];
}

char*Group::GroupList()
{
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

char*Group::StudentsInfo()
{
	//for (int i = 0; i < group_size;i++)
	Student&ShowStud();
	return "1";
}