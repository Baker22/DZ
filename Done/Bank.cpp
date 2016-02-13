#include"Bank.h"
using namespace std;

uint Bank::mainBall = 0;
Bank::Bank()
{
	uint fillBall = 0;
	ushort sizeFil = 0;
	uint sizeDep = 0;
	uint sizeCred = 0;
	uint *deposit = nullptr;
	uint*credit = nullptr;
	uint*creditNum = nullptr;
	uint *filials = nullptr;
	ushort persent = 0;
}
Bank::Bank(uint filBall, ushort persent)
{
	SetFilBall(filBall);
	SetPersent(persent);
}

Bank::~Bank()
{
	delete[]deposit;
	delete[]credit;
	delete[]creditNum;
	delete[]filials;
};
uint Bank::GetFilBall()const
{
	return filBall;
}

uint Bank::GetMainBall()
{
	return Bank::mainBall;
}

void Bank::SetFilBall(uint filBall)
{
	if (filBall>0)
		this->filBall = filBall;
	AddNewFil(this->filBall);
	SetMainBall();
}


void Bank::SetMainBall()
{
	for (int i = 0; i < sizeFil; i++)
		Bank::mainBall += filials[i];
}

void Bank::SetPersent(ushort persent)
{
	if (persent>0)
		this->persent = persent;
}
void Bank::AddNewFil(uint ball)
{
	uint*temp = new uint[sizeFil + 1];
	for (uint i = 0; i < sizeFil; i++)
		temp[i] = filials[i];
	temp[sizeFil] = ball;
	delete[]filials;
	filials = temp;
	sizeFil++;
}
void Bank::FormDeposit(uint dep)
{
	if (dep>0)
		Bank::mainBall += dep;
	uint*temp = new uint[sizeDep + 1];
	for (uint i = 0; i < sizeDep; i++)
		temp[i] = deposit[i];
	temp[sizeDep] = dep;
	delete[]deposit;
	deposit = temp;
	sizeDep++;
}
double Bank::FormCredit(double cred)
{
	if (cred>0)
		Bank::mainBall -= cred;
	uint*temp = new uint[sizeCred + 1];
	uint*tempNum = new uint[sizeCred + 1];
	for (uint i = 0; i < sizeCred; i++)
	{
		tempNum[i] = creditNum[i];
		temp[i] = credit[i];
	}
	tempNum[sizeCred] = cred;
	temp[sizeCred] = cred + ((cred / 100)*persent);
	delete[]credit;
	delete[]creditNum;
	creditNum = tempNum;
	credit = temp;
	sizeCred++;
	return cred;

}

double Bank::issueDeposit(double dep)
{
	double persents = 0;
	for (uint i = 0; i < sizeDep; i++)
	{
		if (deposit[i] == dep)
		{
			persents = (((dep / 100)*persent) + dep);
			Bank::mainBall -= persents;
			uint*temp = new uint[sizeDep - 1];
			for (uint j = i; j < sizeDep; j++)
				temp[j] = deposit[j + 1];
			delete[]deposit;
			deposit = temp;
			sizeDep--;
			return persents;
		}
		else continue;
	}
	return persents;
}

uint Bank::issueCredit(double cred, double value)
{
	int rest = 0;
	for (uint i = 0; i < sizeCred; i++)
	{
		if (creditNum[i] == cred)
		{
			if (value < credit[i])
			{
				Bank::mainBall += value;
				credit[i] -= value;
			}
			else
			{
				Bank::mainBall += credit[i];
				rest = value - credit[i];
				credit[i] = 0;
				uint*temp = new uint[sizeCred - 1];
				uint*tempNum = new uint[sizeCred - 1];
				for (uint j = i; i < sizeCred; i++)
				{
					temp[j] = credit[j + 1];
					tempNum[j] = creditNum[j + 1];
				}
				delete[]creditNum;
				delete[]credit;
				credit = temp;
				creditNum = tempNum;
				sizeCred--;

			}

		}
		else
			cout << "not found this credit" << endl;//сдесь очень хотел сделать "throw", но он у меня почему-то, ещё ни разу не получился (вылет программы).Поясните почему так.
	}
	return rest;
}