#pragma once
#include <iostream>
#include "Account.h"
using namespace std;

class User: public Account{
private:
	Account acc;
	bool isPin; // Card is ATM?
public:
	User();
	~User();

	void getName();
	bool getIsPin();
	void setIsPin();
};

