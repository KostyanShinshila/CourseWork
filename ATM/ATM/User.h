#pragma once
#include <iostream>
#include "Account.h"
using namespace std;

class User: public Account{
private:
	bool isPin();
public:
	void getName();
};

