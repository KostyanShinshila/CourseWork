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

	string getFIO();

	int getPin();
	void setPin(int Pin);

	long getIdent();
};