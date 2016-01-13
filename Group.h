#pragma once
#include<iostream>
#include"Student.h"
typedef unsigned short ushort;
using namespace std;


class Group
{
	Student**students;
	ushort group_size;
	char*group_name;
	char*group_spec;
	char*course_num;
	char*Getter(char*str)const;
public:
	void SetSize(ushort group_size);
	void SetName(char* group_name);
	void SetSpec(char*group_spec);
	void SetNum(char*course_num);

	ushort GetSize() const{ return this->group_size; }
	char*GetGroup_name()const;
	char*GetGroup_spec()const;
	char*GetCourse_num()const;
	
	Group();
	Group(char*group_name, char*group_spec, char*course_num);
	Group(ushort group_size);
	Group(Group & other);
	~Group(){};
	void AddStudToGroup(Student & student);
	Group GroupCopy(Group & other);
	char*GroupList();
	char*GroupInfo();
	char*StudentsInfo();
};