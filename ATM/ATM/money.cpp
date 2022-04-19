#include "Money.h"

Money::Money(string Currency, long Sum){
	currency = Currency;
	sum = Sum;
	lim = 50000;
}

Money::Money(){
	currency = "Rub";
	sum = 15000;
	lim = 50000;
}

long double Money::getSum(){
	return sum;
}

long Money::getLim(){
	return lim;
}

string Money::getCurrency(){
	return currency;
}

void Money::setSum(long Sum){
	sum = Sum;
}

void Money::setLim(long Lim){
	lim = Lim;
}