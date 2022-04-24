#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Interface.h"
#include "Database.h"
#include "PayTax.h"
#include "User.h"
using namespace std;

Interface c;
Language l;
Database bd;
Service ser;
PayTax payTax;
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

		case '5':
			user->checkPin(l);
			for (;;){
				ser.showInfo(l);
				int inputSer = 0;
				inputSer = getInt(inputSer);
				if (inputSer == 1){
					// номер телефона
				}
				if (inputSer == 2){
					system("cls");
					payTax.showService(l);
					string inn;
					for (;;){ // проверка на 10 символов и на буквы
						cout << "> ";
						cin.ignore();
						getline(cin, inn);
						int strlenght = inn.length();
						if (strlenght == payTax.getPayNumbers() && isInt(inn) == 1)
							break;
					}
					for (;;){ // ввод суммы
						cout << l.getString("service_pay_tax_sum") << endl;
						cout << "> ";
						long getSum = 0;
						getSum = getInt(getSum);
						if (getSum == -1)
							break;
						if (getSum < user->getBal()){
							payTax.payService(*user, getSum);
							cout << l.getString("service_pay_tax_good") << endl;
							payTax.writeCheck(bd, inn, getSum);
							break;
						}
						else{

						}
					}
				}
				if (inputSer == 4)
					break; 
				
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