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
	void SetSize(ushort group_size);
public:
	
	void SetName(const char* group_name);
	void SetSpec(const char*group_spec);
	void SetNum(const char*course_num);

	ushort GetSize() const{ return this->group_size; }
	char*GetGroup_name()const;
	char*GetGroup_spec()const;
	char*GetCourse_num()const;
	Group();
	Group(const char*group_name, const char*group_spec, const char*course_num);
	Group(ushort group_size);
	Group(Group & other);
	~Group();
	void AddStudToGroup(Student & student);
	char*GroupList();
	char*GroupInfo();
	void GroupUnion(Group &some);
	void SortStud();
	void StudMove(Group &target, ushort stud_num);
	void StudDelete(ushort stud_num);
	Group& operator=(Group&other);
	char* operator[](ushort num);
};