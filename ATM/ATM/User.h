#pragma once
#include <iostream>
#include "Account.h"
#include "Language.h"
using namespace std;

class User: public Account{
private:
	bool isPin; // Card is ATM?
public:
	User();
	~User();
	void checkPin(Language&l);
	void addMoneyBal(Language&l);

	bool getIsPin();
	void setIsPin();
	void setIsPin(bool arg);
};

