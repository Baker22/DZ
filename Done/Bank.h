#pragma once
#include<iostream>
typedef unsigned int uint;
typedef unsigned short ushort;

class Bank
{
	uint filBall;
	ushort sizeFil;
	uint sizeDep;
	uint sizeCred;
	uint *filials;
	uint *deposit;
	uint*credit;
	uint*creditNum;
	ushort persent;
	void SetMainBall();
	void AddNewFil(uint ball);
	void SetSizeFill();
	static uint mainBall;
public:
	Bank();
	Bank(uint fillBall, ushort persent);
	uint GetFilBall()const;
	static uint GetMainBall();
	void SetFilBall(uint fillBall);
	void FormDeposit(uint dep);
	double FormCredit(double cred);
	double issueDeposit(double dep);
	uint issueCredit(double cred, double value);
	void payDepozTax(uint rate);
	void SetPersent(ushort persent);
	~Bank();
};