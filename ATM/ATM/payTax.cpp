#pragma once
#include <iostream>
#include <string>
#include "PayTax.h"
using namespace std;

PayTax::PayTax(){
	serviceName = "Оплата налогов";
	payNumbers = 10;
}

void PayTax::showService(Language&Language){
	cout << Language.getString("service_pay_tax_message_1") << endl;
	cout << Language.getString("service_pay_tax_message_2") << endl;
}

void PayTax::payService(User&user, long sum){
	user.subMoney(sum);
}

void PayTax::writeCheck(Database&bd, long sum){
	bd.addLogOperation(serviceName + to_string(sum));
}