using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Students_Group
{
    public class Adress
    {
        string home;
        string street;
        string city;

        public string GetHome() { return home; }
        public string GetStreet() { return street; }
        public string GetCity() { return city; }
        public void SetHome(string home)
        {
            this.home = home;
        }
        public void SetStreet(string street)
        {
            this.street = street;
        }
        public void SetCity(string city)
        {
            this.city = city;
        }
        public Adress() : this("No home", "No street", "No city") { ;}
        public Adress(string home) : this(home, "No info", "No info") { ;}
        public Adress(string home, string street) : this(home, street, "No info") { ;}
        public Adress(string home, string street, string city)
        {
            SetHome(home);
            SetStreet(street);
            SetCity(city);
        }

    }
    public class Dob
    {
        ushort day;
        ushort month;
        ushort year;
        ushort AllowedDay()
        {
            ushort a=0;
            bool b = (year % 4 == 0 && this.year % 100 != 0 || this.year % 400 == 0);
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                a = 31;
            else if (month == 4 || month == 6 || month == 9 || month == 11) 
            a = 30;
            else if (month == 2 && b == true)
                a = 29;
            else if(month == 2 && b == false)
                a = 28;
            return a;
        }

        public ushort GetDay() { return this.day; }
        public ushort GetMonth() { return this.month; }
        public ushort GetYear() { return this.year; }
        public void SetDay(ushort day) { this.day = day; }
        public void SetMonth(ushort month) { this.month = month; }
        public void SetYear(ushort year) { this.year = year; }
        public Dob() : this(0, 0, 0) { ;}
        public Dob(ushort day, ushort month, ushort year)
        {
            SetDay(day);
            SetMonth(month);
            SetYear(year);
        }
        public void ShowDob()
        {
            Console.WriteLine("{0}. {1}. {2}", this.day, this.month, this.year);
        }
    }
    public class Student
    {
        string phone;
        string name;
        string secondname;
        string lastname;
        Adress adress;
        Dob birthday;
        ushort[] exams;
        ushort[] courses;
        ushort[] tests;
        ushort examsSize;
        ushort coursesSize;
        ushort testsSize;

        public string GetPhone() { return this.phone; }
        public string GetName() { return this.name; }
        public string GetSecondname() { return this.secondname; }
        public string GetLastname() { return this.lastname; }
        public string Get1Exam(ushort index) { return exams[index].ToString(); }
        public string Phone
        {
            set
            {
                try
                {
                    Convert.ToInt32(value);
                    phone=value;
                }
                catch(SystemException)
                {
                    Console.WriteLine("Need to enter a number");

                }
                
            }
            get {return phone;}  
            
        }
        public string Name
        {
            set
        {
            name = value;
        }
            get { return name; }

        }
        public string SecondName
        {
            set
            {
                secondname = value;
            }
            get { return secondname; }

        }
        public string LastName
        {
            set
            {
                lastname = value;
            }
            get { return lastname; }

        }
        public string GetExams()
        {
            string res = "Exams: ";
            for (ushort i = 0; i < examsSize; i++)
                res = res + (Get1Exam(i));
            return res;
        }
        public string GetAdress()
        {
            return (adress.GetCity().ToString() + " " + adress.GetStreet().ToString() + " " + adress.GetHome().ToString());
        }
        public string GetBirthday()
        {
            return (birthday.GetDay().ToString() + " " + birthday.GetMonth().ToString() + " " + birthday.GetYear().ToString());
        }
        public string FullName()
        {
            return (this.name + " " + this.secondname + " " + this.lastname);
        }
        public void StudentInfo()
        {
            Console.WriteLine(FullName());
            Console.WriteLine(GetBirthday());
            Console.WriteLine(GetAdress());

        }
        public void SetPhone(string phone) { this.phone = phone; }
        public void SetName(string name) { this.name = name; }
        public void SetSecondname(string secondname) { this.secondname = secondname; }
        public void SetLastname(string lastname) { this.lastname = lastname; }
        public void SetBirthday(Dob birthday) { this.birthday = birthday; }
        public void SetAdress(Adress adress) { this.adress = adress; }
        public void SetSomeGrade(ushort[] arr, ushort size, ushort grade)
        {
            ushort[] temp = new ushort[size + 1];
            foreach (ushort i in arr)
                temp[i] = i;
            temp[size] = grade;
            arr = temp;
            size++;
        }
        public void SetExam(ushort grade)
        {
            SetSomeGrade(exams, examsSize, grade);
        }
        public void SetCourse(ushort grade)
        {
            SetSomeGrade(courses, coursesSize, grade);
        }
        private void SetTest(ushort grade)
        {
            SetSomeGrade(tests, testsSize, grade);
        }

        public Student() : this("No Phone", "No Name", "No SecondName", "No LastName", new Dob(), new Adress()) { ;}
        public Student(string phone, string name, string secondname, string lastname) : this(phone, name, secondname, lastname, new Dob(), new Adress()) { ;}
        public Student(string phone, string name, string secondname, string lastname, Dob basic, Adress place)
        {
            SetPhone(phone);
            SetName(name);
            SetSecondname(secondname);
            SetLastname(lastname);
            SetBirthday(birthday);
            SetAdress(place);
        }

    }
    public class Group
    {
        Student[] students;
        ushort group_size;
        string group_name;
        string group_spec;
        string course_num;
        void SetSize()
        {
            this.group_size = 0;
            if (students != null)
                foreach (var item in students)
                    this.group_size += 1;
        }
        public void SetName(string group_name) { this.group_name = group_name; }
        public void SetSpec(string group_spec) { this.group_spec = group_spec; }
        public void SetNum(string course_num) { this.course_num = course_num; }

        public ushort GetSize() { return group_size; }
        public string GetGroup_name() { return group_name; }
        public string GetGroup_spec() { return group_spec; }
        public string GetCourse_num() { return course_num; }
        public Group() : this("group No name", "group No spec", "course No num") { ;}
        public Group(string group_name, string group_spec, string course_num)
        {
            SetName(group_name);
            SetSpec(group_spec);
            SetNum(course_num);
            SetSize();
        }
        public ushort GroupSize
        {
            get { return group_size; }
        }

        public string GroupName
        {
            set
            {
                group_name = value;
            }
            get { return group_name; }
        }

        public string GroupSpec
        {
            set
            {
                group_spec = value;
            }
            get{return group_spec;}
        }
        public string CourseNum
        {
            set
            {
                course_num = value;
            }
            get { return course_num; }
        }
        public void AddStudToGroup(Student student)
        {
            Student[] temp = new Student[group_size + 1];
            for (int i = 0; i < group_size; i++)
                temp[i] = students[i];
            temp[group_size] = student;
            this.students = temp;
            SetSize();
        }
        public string GroupList()
        {
            string res = "Group list: \n";
            foreach (var item in students)
                res = res + item.FullName() + '\n';
            return res;
        }
        public string GroupInfo()
        {
            string res = "Group info: \n";
            res = res + GetGroup_name() + ' ' + GetGroup_spec() + ' ' + GetCourse_num() + ' ' + GetSize().ToString() + " students";
            return res;
        }
        public void GroupUnion(Group some)
        {
            foreach (var item in some.students)
                AddStudToGroup(item);
            SetSize();
        }
        public void SortStud()
        {
            for (int i = 1; i < group_size; i++)
            {
                string name1 = students[i].GetLastname();
                string name2 = students[i - 1].GetLastname();
                if (string.Compare(name1, name2) > 0)
                {
                    Student tmp = students[i];
                    students[i] = students[i + 1];
                    students[i - 1] = tmp;
                    i--;
                }
            }
        }

        public void StudMove(Group target, ushort stud_num)
        {
            target.AddStudToGroup(this.students[stud_num]);
            StudDelete(stud_num);
        }
        public void StudDelete(ushort stud_num)
        {
            Student[] temp = new Student[group_size - 1];
            for (int i = 0; i < group_size; i++)
            {
                if (stud_num != i - 1)
                    temp[i] = students[i];
            }
            students = temp;
            SetSize();
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Student a = new Student();
            a.Phone = "123n";
            Student b = new Student("0663567899", "Alexandr", "Sergeevich", "Pushkin");
            Console.WriteLine(a.FullName());
            Console.WriteLine(b.FullName());
            Dob bb = new Dob(22, 10, 1981);
            b.SetBirthday(bb);
            b.StudentInfo();
            Group studs = new Group();
            studs.AddStudToGroup(b);
            studs.AddStudToGroup(a);
            Console.WriteLine(studs.GroupInfo());
            studs.GroupName = "newgrowp";
            studs.GroupSpec = "Killers";
            studs.CourseNum = "2016";
            Console.WriteLine(studs.GroupInfo());
        }
    }
}
