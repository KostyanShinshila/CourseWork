﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Interface.h"
#include "Database.h"
#include "TransferToPhone.h"
#include "TransferToWallet.h"
#include "TransferToCard.h"
#include "PayTax.h"
#include "User.h"
using namespace std;

Interface c;
Language l;
Database bd;
Service ser;
TransferToCard toCard;
string card;

User *user = new User();

int getInt(int num){
	for (;;){
		int answ = scanf("%d", &num); // If answ = 1 -> enter int
		if (answ != 1){
			scanf("%*[^\n]"); // clear buffer
			cout << "> ";
		}
		else
			return num;
	}
}

int isInt(string str){
	for (int i = 0; i<str.size(); i++){
		if (str[i] < '0' || str[i] > '9'){
			return 0;
		}
	}
	return 1;
}

void titulMenu(){
	int key;
	do{
		c.zastavka(l);
		key = _getch();
		switch (key){
		case 'd':
			system("pause");
			break;
		case '\t':
			l.changeLang();
			break;
		
		case 13:
			return; // exit
			break;
		}

		fflush(stdin);
	} while (key != 27);
}

void auth(){
	int key;
	do{
		system("cls");
		cout << "	" << l.getString("auth_hub") << endl;;
		cout << l.getString("auth_message") << endl;
		cout << endl;
		cout << l.getString("auth_card");
		/* If card in atm */
		if (user->getIsPin()){
			cout << l.getString("auth_card_status_t") << endl; // В банкомате.
			cout << endl;
			cout << l.getString("auth_logoff") << endl; // Нажмите <d>, чтобы достать карту.
			cout << l.getString("auth_proceed") << endl; // Нажмите <s>, чтобы продолжить.
		}

		/* else */
		else{
			cout << l.getString("auth_card_status_f") << endl;
			cout << endl;
			cout << l.getString("auth_enter_card") << endl;
			cout << l.getString("auth_leave") << endl;
		}

		key = _getch();
		switch (key){
		case 's':
			user->setIsPin();
			break;
		case 'd':
			if (user->getIsPin()){
				key = 27;
			}
			else{
				system("cls");
				user->setIsPin(false);
				titulMenu();
			}
			break;
		}

		fflush(stdin);
	} while (key != 27);
	
	/* Enter pin */
	int inputPin;
	system("cls");
	cout << "	" << l.getString("auth_get_pin_hub") << endl;
	cout << l.getString("auth_get_pin_message") << endl;
	cout << l.getString("auth_get_pin_tip") << endl;
	cout << endl;
	cout << "> ";
	for (;;){
		int answ = scanf("%d", &inputPin); // If answ = 1 -> enter int
		if (answ != 1 || inputPin < 1000 || inputPin > 9999){
			scanf("%*[^\n]"); // clear buffer
			system("cls");
			cout << l.getString("auth_get_pin_error") << endl;
			cout << l.getString("auth_get_pin_reply") << endl;
			cout << "> ";
		}

		else break;
	}

	system("cls");
	user->setPin(inputPin);
	user->setFIO(l.getString("user_name"));
	user->setCurr(l.getString("currency"));
	cout << "	" << l.getString("auth_hello_hub") << endl;
	cout << l.getString("auth_delay") << endl;
	Sleep(2500); // delay 2.5s
	system("cls");
	cout << "	" << l.getString("auth_hello_hub") << endl;
	cout << user->getFIO() << l.getString("auth_hello") << endl;
	cout << endl;
	cout << l.getString("pause") << endl;
	//system("pause");
}

void menu(){
	int key;
	do{
		key = _getch();
		system("cls");
		cout << "	" << l.getString("menu_hub") << endl;
		cout << l.getString("bal") << user->getBal() << " " << user->getCurr() << " | ";
		cout << l.getString("lim") << user->getLimit() << " " << user->getCurr() << endl;
		cout << endl;
		cout << "1. " << l.getString("menu_list_addBal") << endl;
		cout << "2. " << l.getString("menu_list_subBal") << endl;
		cout << "3. " << l.getString("menu_list_history") << endl;
		cout << endl;
		cout << "4. " << l.getString("menu_list_transfer") << endl;
		cout << "5. " << l.getString("menu_list_service") << endl;
		cout << endl;
		cout << "6. " << l.getString("menu_list_cabinet") << endl;
		cout << "7. " << l.getString("menu_list_info") << endl;
		cout << endl;
		cout << "8. " << l.getString("menu_list_exit") << endl;
		switch (key){
		case '1':
			user->checkPin(l);
			user->addMoneyBal(l);
			break;

		case '2':
			user->checkPin(l);
			user->subMoneyBal(l);
			break;

		case '3':
			user->checkPin(l);
			user->showHistory(l, bd);
			break;

		case '4':
			user->checkPin(l);
			toCard.showInfo(l);
			toCard.showRecentTrans(bd);
			cout << endl;
			cout << l.getString("transfer_card_get_card") << endl;
			cout << l.getString("transfer_card_help") << endl;
			for (;;){
				cin.clear();
				getline(cin, card);
				if (toCard.checkCardOnValid(bd, card))
					break;
				cout << "> ";
			}
			cout << endl;
			cout << l.getString("transfer_card_sum") << endl;
			for (;;){
				long toCardSum = 0;
				cout << "> ";
				toCardSum = getInt(toCardSum);
				if (toCardSum == -1)
					break;
				if (toCardSum <= user->getBal() && toCardSum > 100){
					toCard.payService(*user, toCardSum);
					cout << l.getString("transfer_card_sum_good") << endl;
					toCard.writeCheck(bd, card, toCardSum);	
					cout << l.getString("pause") << endl;
					break;
				}
				cout << l.getString("transfer_card_sum_bad") << endl;
			}
			break;

		case '5':
			user->checkPin(l);
			for (;;){
				system("cls");
				ser.showInfo(l);
				cout << endl;
				cout << "> "; 
				int inputSer = 0;
				inputSer = getInt(inputSer);
				if (inputSer == 1){ // Пополнение телефона
					TransferToPhone toPhone;
					system("cls");
					toPhone.showService(l);
					string phone;
					int innSize = toPhone.getPayNumbers();
					for (;;){
						getline(cin, phone);
						int strlenght = phone.length();
						if (strlenght == innSize && isInt(phone) == 1)
							break;
						cout << "> ";
					}
					for (;;){
						cout << endl;
						cout << l.getString("service_to_phone_sum") << endl;
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1)
							break;
						if (getSum <= user->getBal()){
							toPhone.payService(*user, getSum);
							cout << l.getString("service_to_phone_good") << endl;
							toPhone.writeCheck(bd, phone, getSum);
							system("pause");
							break;
						}
						else{
							cout << l.getString("service_to_phone_bad") << endl;
						}
					}
				}
				if (inputSer == 2){
					system("cls");
					PayTax payTax;
					payTax.showService(l);
					string inn;
					int innSize = payTax.getPayNumbers();
					for (;;){ // проверка на 10 символов и на буквы
						//cin.ignore();

						getline(cin, inn);
						int strlenght = inn.length();
						if (strlenght == innSize && isInt(inn) == 1)
							break;
						cout << "> ";
					}
					for (;;){ // ввод суммы
						cout << endl;
						cout << l.getString("service_pay_tax_sum") << endl;
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1)
							break;
						if (getSum <= user->getBal()){
							payTax.payService(*user, getSum);
							cout << l.getString("service_pay_tax_good") << endl;
							payTax.writeCheck(bd, inn, getSum);
							system("pause");
							break;
						}
						else{
							cout << l.getString("service_pay_tax_bad") << endl;
						}
					}
				}
				if (inputSer == 3){ // Online wallet
					TransferToWallet toWallet;
					system("cls");
					toWallet.showService(l);
					string wallet;
					int innSize = toWallet.getPayNumbers();
					for (;;){
						getline(cin, wallet);
						int strlenght = wallet.length();
						if (strlenght == innSize && isInt(wallet) == 1)
							break;
						cout << "> ";
					}
					for (;;){
						cout << endl;
						cout << l.getString("service_pay_wallet_sum") << endl;
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1)
							break;
						if (getSum <= user->getBal()){
							toWallet.payService(*user, getSum);
							cout << l.getString("service_pay_wallet_good") << endl;
							toWallet.writeCheck(bd, wallet, getSum);
							system("pause");
							break;
						}
						else{
							cout << l.getString("service_pay_wallet_bad") << endl;
						}
					}
				}
				if (inputSer == 4){
					cout << l.getString("pause") << endl;
					break;
				}
				
			}
			break;

		case '6':
			user->checkPin(l);
			for (;;){
				user->showProfile(l);
				cout << "1. " << l.getString("profile_menu_ticket") << endl;
				cout << "2. " << l.getString("profile_menu_back") << endl;
				cout << endl;
				cout << "> ";
				int input = 0;
				input = getInt(input);
				if (input == 1) user->createTicket(l);
				if (input == 2){
					cout << l.getString("pause");
					break;
				}
			}
			break;
		
		case '7':                                                                    
			user->checkPin(l);
			for (;;){
				system("cls");
				cout << "	" << l.getString("settings_hub") << endl;
				cout << "1. " << l.getString("settings_lang") << endl;
				cout << "2. " << l.getString("settings_clear") << endl;
				cout << "3. " << l.getString("settings_null") << endl;
				cout << "4. " << l.getString("settings_back") << endl;
				int getInput = 0;
				cout << endl;
				cout << "> ";
				getInput = getInt(getInput);
				if (getInput == 1){
					l.changeLang();
					system("pause");
				}

				if (getInput == 2){
					user->resetAccount();
					cout << l.getString("settings_clear_message") << endl;
					system("pause");
				}

				if (getInput == 3){
					bd.createFileLogs();
					cout << l.getString("settings_null_message") << endl;
					system("pause");
				}

				if (getInput == 4)
					break;
			}
			cout << endl;
			cout << l.getString("pause") << endl;
			break;

		case '8':
			key = 27;
			break;
		}
		fflush(stdin);
	} while (key != 27);
}

void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	bd.createFileLogs();
	titulMenu();
	auth();
	menu();
}