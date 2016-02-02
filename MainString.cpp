#include<iostream>
#include"String.h"
using namespace std;

void main()
{
	srand(time(0));
	String a;
	a.SetCapacity(23);
	cout << a.GetChar() << endl;
	a.Resize(5);

	String b("test test test");
	cout << b.GetChar() << endl;
	b.SetCapacity(20);
	cout << b.GetChar() << endl;
	b.Resize(5);

	String c(b);
	cout << c.GetChar() << endl;
	c.SetCapacity(20);
	cout << c.GetChar() << endl;
	c.Resize(5);

	String d(b,20);
	cout << d.GetChar() << endl;
	d.SetCapacity(20);
	cout << d.GetChar() << endl;
	d.Resize(5);
	
	String i("Hello",6);
	cout << i.GetChar() << endl;
	cout << i.GetChar() << endl;
	i.Resize(5);

	i.AddSim(' ');
	i.AddSim('!');
	cout << i.GetChar() << endl;
	a.Resize(5);
	cout<<i.GetCount()<<endl;
	cout<<i.GetCapacity()<<endl;
	b.Print();
	cout << endl;

	i.Print();
	cout << endl;
	i.Resize(20);
	i.Print();
	cout << endl;

	cout<<i.GetSim(0)<<endl;

	i.operator=(b);
	i.Print();
	

	cout << i.operator>=(d) << endl;

	a.operator()("Hello World", 30, 12);
	a.Print();
	cout << endl;

	cout << a.operator[](4)<<endl;

	a.operator+=(i);
	a.Print();
	cout << endl;
	a.SetCapacity(23);
	d.operator+=("Friends");
	d.Print();
	cout << endl;
	cout << a << b << c << d << i << endl;
	
	String *o = a + b;
	o->Print();
	//cin >> b;
	//cout << b;
	

	char*temp =b;
	cout << temp<<endl;
	
	delete[]temp;
	String _int("345");
	int temp_1 = _int;
	cout << temp_1<<endl;
	
	String _double("345.202");
	double temp_2 = _double;
	cout << temp_2<<endl;
	String *p = _int + _double;
	d.PrintLn();
	
	
	//d.GetLine();
	d.PrintLn();
	cout<<d.CompareTo(a)<<endl;
	cout<<d.CompareTo("test test testFriends")<<endl;
	
	i.Concat(d);
	i.PrintLn();
	
	i.Concat("My");
	i.PrintLn();
	
	i.Concat(123);
	i.PrintLn();
	
	i.Concat(123.689);
	i.PrintLn();
	
	i.Concat(&d, 3);
	i.PrintLn();
	cout<<i.Contains("test")<<endl;
	cout << i.EndsWith("tes")<<endl;
	cout << i.StartsWith("testo") << endl;
	i.CopyTo(a);
	a.Resize(10);
	a.PrintLn();
	cout << a.IndexOf('f') << endl;
	cout << a.LastIndexOf('F') << endl;
	c.SetCapacity(23);
	String hello("Hellllllo");
	cout << hello.IndexOf("lo") << endl;
	String one("ohPotato");
	String two("Potato");
	one.Resize(30);
	cout << one.LastIndexOf(&two) << endl;
	cout<<one.IndexOfAny(&two) << endl;
	String text("   I   like     the    way   ");
	text.Normalize(); 
	text.PrintLn();
	text.PadLeft(1);
	text.PrintLn();
	text.PadLeft(5);
	text.PrintLn();
	
	text.PadRight(1);
	text.SetCapacity(23);
	text.PrintLn();
	text.SetCapacity(23);
	text.PrintLn();
	text.PadLeft(5,'(');
	text.PrintLn();
	text.SetCapacity(28);
	text.PadRight(3, '!');
	text.PrintLn();
	text.SetCapacity(100);
	text.Remove(0);
	text.PrintLn();
	String numbs("123456789");
	String numbs2("123456789987654321");
	String numbs3("8998");
	String simbs("ABCDXYZ");
	numbs.PrintLn();
	numbs.Remove(3, 6);
	numbs.PrintLn();
	numbs.Replace('9', '!');
	numbs.PrintLn();
	numbs2.PrintLn();
	numbs2.Replace(numbs3, simbs);
	numbs2.PrintLn();
	String numbs4("123!456!78998!765!4321");
	int pieces = 0;
	String**tmp=numbs4.Split('!', pieces);
	tmp[0]->PrintLn();
	tmp[1]->PrintLn();
	tmp[2]->PrintLn();
	tmp[3]->PrintLn();
	tmp[4]->PrintLn();
	simbs.ToLower();
	simbs.PrintLn();
	simbs.ToUpper();
	simbs.PrintLn();
	String tt("   I   like     the    way   ");
	//tt.Trim();
	tt.PrintLn();
	//tt.TrimEnd();
	//tt.TrimStart();
	tt.Reverse();
	tt.PrintLn();
	tt.SortAZ();
	tt.PrintLn();
	tt.SortZA();
	tt.PrintLn();
	tt.Shuffle();
	tt.PrintLn();
	String rand(10);
	rand.RandomFill();
	rand.PrintLn();
	rand.Insert(&simbs, 3);
	rand.PrintLn();
	simbs.PrintLn();
	simbs.Initialize(9, 9, "abcdxyzzz");
	simbs.PrintLn();
	
	String a_a("three");
	String b_b("!two!!two!");
	String *c_c = ( "two"+ a_a);
	c_c->PrintLn();
	cout<<a_a.operator!= (b_b)<<endl;
	cout << c_c->CompareTo("twoonee") << endl;
	c_c->LastIndexOf('a');
	String bas("threetwoone");
	//bas.Replace(a_a, b_b);
	bas.PrintLn();
	cout<<bas.IndexOf("one")<<endl;
}