#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class Service{
private:
	string serviceName;
	int payNumbers;
public:
	Service();
	void showService(Language&Language);
	virtual void payService(User&user, long sum);
	virtual void writeCheck(Database&bd, long sum);
};