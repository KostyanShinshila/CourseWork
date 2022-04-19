#pragma once
#include <iostream>
#include "Account.h"
using namespace std;

class User: public Account{
private:
	Account acc;
	bool isPin;
public:
	void getName();
	bool getIsPin();
	User();
};

