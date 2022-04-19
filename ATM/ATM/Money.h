#pragma once
#include <iostream>
using namespace std;

class Money{
protected:
	string currency;
	long double sum;
	long lim;

public:
	Money(string Currency, long Sum);
	Money();

	void setSum(long Sum);
	void setLim(long Lim);

	long double getSum();
	long getLim();
	string getCurrency();
};