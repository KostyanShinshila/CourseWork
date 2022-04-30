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
	cout << "	" << l.getString("service_hub") << "\n";
	cout << "\n";
	cout << l.getString("service_message") << "\n";;
	cout << "1. " << l.getString("service_to_phone") << "\n";
	cout << "2. " << l.getString("service_pay_tax") << "\n";
	cout << "3. " << l.getString("service_to_wallet") << "\n";
	cout << "\n";
	cout << "4. " << l.getString("service_back") << "\n";
}