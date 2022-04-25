#pragma once
#include <iostream>
#include <string>
#include "TransferToPhone.h"
using namespace std;

TransferToPhone::TransferToPhone(){
	serviceName = "Пополнение номера телефона";
	payNumbers = 10;
}

void TransferToPhone::showService(Language&Language){
	cout << "	" << Language.getString("service_to_phone_hub") << endl;
	cout << Language.getString("service_to_phone_message") << endl;
	cout << Language.getString("service_to_phone_help") << endl;
	cout << endl;
}

void TransferToPhone::payService(User&user, long sum){
	user.subMoney(sum);
}

void TransferToPhone::writeCheck(Database&bd, string address, long sum){
	bd.addLogOperation(serviceName + " +" + address + " - " + to_string(sum) + " Руб.");
}

int TransferToPhone::getPayNumbers(){
	return payNumbers;
}