#include "Account.h"
#include <cstdlib>

Account::Account(){
	Money M;
	m = M;
	long ident = 000000 + rand() % 999999;
	fio = "Петр Сергеевич Кондратьев";
}

Account::Account(string FIO, long Ident, int Pin, Money M){
	fio = FIO;
	ident = Ident;
	pin = Pin;
	m = M;
}

int Account::getPin(){
	return pin;
}

void Account::addMoney(long Sum){
	setSum(sum + Sum);
}

	