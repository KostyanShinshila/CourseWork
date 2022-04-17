#include "Money.h"

Money::Money(string Currency, long Sum){
	currency = Currency;
	sum = Sum;
}

Money::Money(){
	currency = "$";
	sum = 15000;
}

long Money::getSum(){
	return sum;
}

void Money::setSum(long Sum){
	sum = Sum;
}
