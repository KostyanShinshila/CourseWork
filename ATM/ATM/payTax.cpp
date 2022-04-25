#pragma once
#include <iostream>
#include <string>
#include "PayTax.h"
using namespace std;

PayTax::PayTax(){
	serviceName = "Оплата налогов на ИНН";
	payNumbers = 12;
}

void PayTax::showService(Language&Language){
	cout << "	" << Language.getString("service_pay_tax_hub") << endl;
	cout << endl;
	cout << Language.getString("service_pay_tax_message_1") << endl;
	cout << Language.getString("service_pay_tax_message_2") << endl;
	cout << Language.getString("service_pay_tax_message_3") << endl;
	cout << Language.getString("service_pay_tax_message_4") << endl;
	cout << Language.getString("service_pay_tax_message_5") << endl;
	cout << endl;
	cout << Language.getString("service_pay_tax_message_6") << endl;
	cout << Language.getString("service_pay_tax_message_7") << endl;
}

void PayTax::payService(User&user, long sum){
	user.subMoney(sum);
}

void PayTax::writeCheck(Database&bd, string address, long sum){
	bd.addLogOperation(serviceName + " " + address + " - " + to_string(sum) + " Руб.");
}

int PayTax::getPayNumbers(){
	return payNumbers;
}