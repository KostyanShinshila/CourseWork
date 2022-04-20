#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <String>
#include <Windows.h>
#include "User.h"
#include "Language.h"
using namespace std;

User::User(){
	isPin = false;
}

User::~User(){
	isPin = false;
}

bool User::getIsPin(){
	if (isPin) return true;
	else return false;
}

void User::setIsPin(){
	isPin ? isPin = false : isPin = true;
}

void User::setIsPin(bool arg){
	arg ? isPin = true : isPin = false;
}


void User::checkPin(Language&l){
	int inputPin;
	system("cls");
	cout << "	" << l.getString("check_pin_hub") << endl;
	cout << l.getString("check_pin_message") << endl;
	cout << "> ";
	for (;;){
		int answ = scanf("%d", &inputPin); // If answ = 1 -> enter int
		if (answ != 1 || inputPin != getPin()){
			scanf("%*[^\n]");
			system("cls");
			cout << l.getString("check_pin_error") << endl;
			cout << l.getString("check_pin_reply") << endl;
			cout << "> ";
		}

		else break;
	}
	system("cls");
	cout << l.getString("check_pin_delay") << endl;
	Sleep(2500);
	cout << endl;
	cout << l.getString("pause") << endl;
}

void User::addMoneyBal(Language&l){
	system("cls");
	cout << "	" << l.getString("add_money_hub") << endl;
	cout << l.getString("bal") << getBal() << " " << getCurr() << " | ";
	cout << l.getString("lim") << getLimit() << " " << getCurr() << endl;
	cout << endl;
	cout << l.getString("add_money_message") << endl;
	cout << "> ";
	int inputSum;
	for (;;){
		int answ = scanf("%d", &inputSum); // If answ = 1 -> enter int
		if (answ != 1 || inputSum < 100 || getLimit() < getBal() + inputSum){
			cout << l.getString("add_money_blocked") << endl;
			scanf("%*[^\n]");
			system("cls");
			if (answ != 1){ // type error
				l.getString("add_money_blocked_error");
				break;
			}
			// errors 
			if (inputSum < 100 || inputSum > 50000){ // если слишком малый перевод или слишком большой
				cout << l.getString("add_money_blocked_odd") << endl;
				break;
			}

			if (getLimit() < getBal() + inputSum){
				l.getString("add_money_blocked_limit");
				break;
			}
			cout << "> ";
		}

		else break;
	}
	// inputSum + Money;
	system("cls");
	l.getString("add_money_delay");
	Sleep(2500);
	l.getString("add_money_ok");
	cout << endl;
	l.getString("pause");
}