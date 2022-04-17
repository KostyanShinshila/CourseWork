#pragma once
#include <iostream>
using namespace std;

class Money{
protected:
	string currency;
	long sum;
	void setSum(long Sum);

public:
	Money(string Currency, long Sum);
	Money();
	long getSum();
};