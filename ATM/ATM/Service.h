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
	void showInfo(Language&l);
	virtual void payService(User&user, long sum);
	virtual void writeCheck(Database&bd, string address, long sum);
	virtual int getPayNumbers();
};