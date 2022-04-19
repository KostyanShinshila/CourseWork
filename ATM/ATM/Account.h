#pragma once
#include <iostream>
#include "Money.h"
using namespace std;

class Account: public Money{
private:
	string fio;
	long ident; //id
	int pin;
	Money *m;
public:
	Account(string FIO, long Ident, int Pin, Money *M);
	void addMoney(long Sum);
	int getPin();
};