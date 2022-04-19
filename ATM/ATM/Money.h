#pragma once
#include <iostream>
using namespace std;

class Money{
protected:
	string currency;
	long sum;

public:
	Money(string Currency, long Sum);
	Money();
	void setSum(long Sum);
	long getSum();
};