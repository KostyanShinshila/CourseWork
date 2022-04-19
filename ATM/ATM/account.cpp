#include "Account.h"
#include <cstdlib>


	/* Constructors */
Account::Account(){
	Money M;
	m = M;
	id = rand() % 999999 + 100000;
	fio = "Петр Сергеевич Кондратьев";
}

Account::Account(string FIO, long Ident, int Pin, Money M){
	fio = FIO;
	id = Ident;
	pin = Pin;
	m = M;
}

	/* Set-metods */
void Account::setPin(int Pin){
	pin = Pin;
}


	/* Get-metods */
string Account::getFIO(){
	return fio;
}

int Account::getPin(){
	return pin;
}

long Account::getIdent(){
	return id;
}

	/* Other */
void Account::addMoney(long Sum){
	m.setSum(m.getSum() + Sum);
}

	