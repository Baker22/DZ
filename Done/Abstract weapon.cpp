#include<iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Weapon abstract
{
public:
	virtual void Shoot() = 0;
	virtual void Reload() = 0;
};

class Scope :public Weapon
{
	int bullets;
public:
	Scope()
	{
		bullets = 10;
	}
	void Shoot()
	{
		if (bullets == 0)
		{
			cout << "\apress 0 for reload\n";
			return;
		}
		cout << "Scope shootting...\n";
		bullets--;
	}
	void Reload()
	{
		cout << "reloading ";
		for (int i = 0; i < 4; i++)
		{
			cout << "/";
			Sleep(1000);
		}
		cout << endl;
		bullets = 10;
		cout << "Scope reloaded...\n";
	}
};

class Kalshnikov :public Weapon
{
	int bullets;
public:
	
	Kalshnikov()
	{
		bullets = 30;
	}
	void Shoot()
	{
		if (bullets == 0)
		{
			cout << "\apress 0 for reload\n";
			return;
		}
		cout << "Kalshnikov shootting...\n";
		bullets--;
	}
	void Reload()
	{
		cout << "reloading ";
		for (int i = 0; i < 4; i++)
		{
			cout << "/";
			Sleep(1000);
		}
		cout << endl;
		cout << "Kalshnikov reloaded...\n";
		bullets = 30;
	}
};

class Makarov :public Weapon
{
	int bullets;
public:
	
	Makarov()
	{
		bullets = 8;
	}
	void Shoot()
	{
		if (bullets == 0)
		{
			cout << "\apress 0 for reload\n";
			return;
		}
		cout << "Makarov shootting...\n";
		bullets--;
	}
	void Reload()
	{
		cout << "reloading ";
		for (int i = 0; i < 4; i++)
		{		
			cout << "/";
			Sleep(1000);
		}
		cout << endl;
		cout << "Makarov reloaded...";
		bullets = 8;
	}
};

class Shotgun :public Weapon
{
	int bullets;
public:

	Shotgun()
	{
		bullets = 12;
	}
	void Shoot()
	{
		if (bullets == 0)
		{
			cout << "\apress 0 for reload\n";
			return;
		}
		cout << "Shotgun shootting...\n";
		bullets--;
	}
	void Reload()
	{
		cout << "reloading ";
		for (int i = 0; i < 4; i++)
		{
			cout << "/";
			Sleep(1000);
		}
		cout << endl;
		cout << "Shotgun reloaded...\n";
		bullets = 12;
	}
};

class Grenades :public Weapon
{
	int bullets;
public:

	Grenades()
	{
		bullets = 2;
	}
	void Shoot()
	{
		if (bullets == 0)
		{
			cout << "\aNo more grenades\n";
			return;
		}
		cout << "Grenade thrown...\n";
		bullets--;
	}
	void Reload()
	{
		cout << "need to visit the weapon shop!\n";
	}
};

class Knife :public Weapon
{
	int handed;
public:

	Knife()
	{
		handed = 1;
	}
	void Shoot()
	{
		cout << "Knife hit...\n";
	}
	void Reload()
	{
		if (handed)
		{
			cout << "Knife on left hand\n";
		handed--;
		}
		else
		{
			cout << "Knife on right hand\n";
			handed++;
		}
	}
};

class RPG :public Weapon
{
	int bullets;
public:

	RPG()
	{
		bullets = 3;
	}
	void Shoot()
	{
		if (bullets == 0)
		{
			cout << "\aNo more rockets\n";
			return;
		}
		cout << "rocket launched\n";
		bullets--;
	}
	void Reload()
	{
		cout << "Try another weapon!\n";
	}
};


void Play(Weapon&weap)
	{
	cout << "1 for shoot\n" << "0 for reload\n" << "3 for other weapon\n";
		int SelectKey;
		do
		{
			SelectKey=_getch();
			switch (SelectKey)
			{
			case 49: weap.Shoot(); break;
			case 48:weap.Reload(); break;
			case 51:return; break;
			}
		} while (true);
	}

void main()
{
	Scope scope;
	Kalshnikov kalashnikov;
	Makarov makarov;
	Shotgun shotgun;
	Grenades grenades;
	Knife knife;
	RPG rpg;
	bool flag;
		int SelectKey;
		do
		{
			flag = true;
			cout << "select your weapon:\n" << "1-scope;\n" << "2-kalashnikov;\n" << "3-makarov;\n";
			cout << "4-shotgun\n" << "5-grenades;\n" << "6-knife;\n" << "7-rpg;\n" << "ESC-EXIT"<<endl;
			SelectKey=_getch();
			switch (SelectKey)
			{
			case 49:cout << "Scope armed\n"; Play(scope); break;
			case 50:cout << "Kalashnikov armed\n"; Play(kalashnikov); break;
			case 51:cout << "Makarov armed\n"; Play(makarov); break;
			case 52:cout << "Shotgun armed\n"; Play(shotgun); break;
			case 53:cout << "Grenade armed\n"; Play(grenades); break;
			case 54:cout << "Knife armed on right hand\n"; Play(knife); break;
			case 55:cout << "RPG armed\n"; Play(rpg); break;
			case 27:cout << "Game is over\n\a."; Sleep(1000);
				cout<<"\a.\a."; Sleep(1000);
				cout<<"\a.\a."; Sleep(1000);
				cout<<"\a.\a.\a."; Sleep(500);
				flag = false; break;
			default:cout << "not enough weapon?\n"; break;
			}
		} while (flag);
	
}