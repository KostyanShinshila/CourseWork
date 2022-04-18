#include "Account.h"

Account::Account(string FIO, long Ident, int Pin, Money M){
	fio = FIO;
	ident = Ident;
	pin = Pin;
	m = M;
}

void Account::addMoney(long Sum){
	setSum(sum + Sum);
}

	