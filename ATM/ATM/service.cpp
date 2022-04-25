#pragma once
#include <iostream>
#include <string>
#include "Service.h"
using namespace std;

Service::Service(){}

void Service::payService(User&user, long sum){}
void Service::writeCheck(Database&bd, string address, long sum){}
int Service::getPayNumbers(){ return 0; }

void Service::showInfo(Language&l){
	cout << "	" << l.getString("service_hub") << endl;
	cout << endl;
	cout << l.getString("service_message") << endl;
	cout << "1. " << l.getString("service_to_phone") << endl;
	cout << "2. " << l.getString("service_pay_tax") << endl;
	cout << "3. " << l.getString("service_to_wallet") << endl;
	cout << endl;
	cout << "4. " << l.getString("service_back") << endl;
}