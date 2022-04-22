#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <String>
#include <Windows.h>
#include "User.h"
#include "Database.h"
#include "Language.h"
using namespace std;

User::User(){
	isPin = false;
	gender = "male";
	birthday = "02/11/1999";
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

string User::getGender(){
	return gender;
}

string User::getBirthday(){
	return birthday;
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
	//cout << l.getString("pause") << endl;
	system("pause");
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
		if (inputSum == -1){
			cout << l.getString("pause");
			return;
		}
		if (answ != 1 || inputSum < 100 || getLimit() < getBal() + inputSum){
			scanf("%*[^\n]");
			system("cls");
			cout << l.getString("add_money_blocked") << endl;
			if (answ != 1){ // type error
				l.getString("add_money_blocked_error");
			}
			// errors 
			if (inputSum < 100 || inputSum > 50000){ // если слишком малый перевод или слишком большой
				cout << l.getString("add_money_blocked_odd") << endl;
			}

			if (getLimit() < getBal() + inputSum){
				l.getString("add_money_blocked_limit");
			}
			cout << l.getString("add_money_blocked_reply") << endl;
			cout << "> ";
		}

		else break;
	}
	// inputSum + Money;
	system("cls");
	cout << l.getString("add_money_delay") << endl;
	addMoney(inputSum);
	Database bd;
	bd.addLogOperation(l.getString("add_log_addbal") + to_string(inputSum) + " " + getCurr());
	Sleep(2500);
	cout << l.getString("add_money_ok") << endl;
	cout << endl;
	cout << l.getString("pause");
}

void User::subMoneyBal(Language&l){
	system("cls");
	cout << "	" << l.getString("sub_money_hub") << endl;
	cout << l.getString("bal") << getBal() << " " << getCurr() << " | ";
	cout << l.getString("lim") << getLimit() << " " << getCurr() << endl;
	cout << endl;
	cout << l.getString("sub_money_message") << endl;
	cout << "> ";
	int inputSum;
	for (;;){
		int answ = scanf("%d", &inputSum); // If answ = 1 -> enter int
		if (inputSum == -1){
			cout << l.getString("pause");
			return;
		}
		if (answ != 1 || inputSum < 100 || getBal() - inputSum < 0 || inputSum > 50000){
			scanf("%*[^\n]");
			system("cls");
			cout << l.getString("sub_money_blocked") << endl;
			if (answ != 1){ // type error
				l.getString("sub_money_blocked_error");
			}
			// errors 
			if (inputSum < 100 || inputSum > 50000){ // если слишком малый перевод или слишком большой
				cout << l.getString("sub_money_blocked_odd") << endl;
			}
			cout << l.getString("sub_money_blocked_reply") << endl;
			cout << "> ";
		}

		else break;
	}
	// inputSum + Money;
	system("cls");
	cout << l.getString("sub_money_delay") << endl;
	subMoney(inputSum);
	Database bd;
	bd.addLogOperation(l.getString("add_log_subbal") + to_string(inputSum) + " " + getCurr());
	Sleep(2500);
	cout << l.getString("sub_money_ok") << endl;
	cout << endl;
	cout << l.getString("pause");
}

void User::showHistory(Language&l, Database&bd){
	system("cls");
	cout << "	" << l.getString("history_hub") << endl;
	cout << l.getString("history_message") << endl;
	cout << endl;
	bd.readLogOperation();
	cout << endl;
	cout << l.getString("pause") << endl;
}

void User::createTicket(Language&l){
	Database bd;
	int input;
	system("cls");
	cout << l.getString("ticket_hub") << endl;
	cout << l.getString("ticket_message") << endl;
	cout << endl;
	cout << "1. " << l.getString("ticket_fio") << endl;
	cout << "2. " << l.getString("ticket_birthday") << endl;
	cout << "3. " << l.getString("ticket_card_name") << endl;
	cout << "4. " << l.getString("ticket_card_time") << endl;
	cout << "5. " << l.getString("ticket_limit") << endl;
	cout << "6. " << l.getString("ticket_answer") << endl;
	cout << "7. " << l.getString("ticket_back") << endl;
	cout << endl;
	cout << l.getString("ticket_ans_message") << endl;
	for (;;){
		cout << "> ";
		int check = scanf("%d", &input);
		if (check != 1){
			scanf("%*[^\n]");
			cout << "6. " << l.getString("ticket_error") << endl;
		}
		else break;
	}

	system("cls");
	string change;
	switch (input)
	{
	case 1:
		cout << l.getString("ticket_ans_message") << endl;
		cout << "> ";
		cin.ignore();
		getline(cin, change);
		cout << l.getString("ticket_ans_good") << endl;
		setFIO(change);
		Sleep(3000);
		cout << l.getString("ticket_ans_finish") << endl;
		bd.addLogOperation(l.getString("add_log_change_name") + change);
		break;
	case 6:
		return;
		break;
	}
}

void User::showProfile(Language&l){
	system("cls");
	cout << "	" << l.getString("profile_hub") << endl;
	cout << l.getString("profile_message") << endl;
	cout << l.getString("profile_edit") << endl;
	cout << endl;
	cout << l.getString("profile_id") << getIdent() << endl;
	cout << l.getString("profile_fio") << getFIO() << endl;
	cout << l.getString("profile_gender") << l.getString(getGender()) << endl;
	cout << l.getString("profile_birthday") << getBirthday() << endl;
	cout << endl;
	cout << l.getString("profile_card") << getCardNumber() << endl;
	cout << l.getString("profile_card_name") << getCardName() << endl;
	cout << l.getString("profile_card_time") << getCardTime() << endl;
	cout << endl;
	cout << l.getString("profile_bal") << getBal() << endl;
	cout << l.getString("profile_limit") << getLimit() << endl;
	cout << endl;
}