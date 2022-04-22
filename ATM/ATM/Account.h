#pragma once
#include <iostream>
#include "Money.h"
using namespace std;

class Account{
private:
	string fio;
	long id; //id
	int pin;
	Money m;
public:
	Account();
	Account(string FIO, long Ident, int Pin, Money M);
	void addMoney(long Sum);
	void subMoney(long Sum);
	
	string getFIO();
	int getPin();
	long double getBal();
	long getIdent();
	string getCurr();
	long getLimit();

	void setPin(int Pin);
	void setFIO(string FIO);
	void setCurr(string Curr);
};