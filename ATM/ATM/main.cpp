#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Interface.h"
#include "Database.h"
#include "User.h"
using namespace std;

Interface c;
Language l;
Database bd;
User *user = new User();

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

		case '6':
			user->checkPin(l);
			user->showProfile(l);
			cout << "1. " << l.getString("profile_menu_ticket") << endl;
			cout << "2. " << l.getString("profile_menu_back") << endl;
			int input;
			cin >> input;
			if (input == 1) user->createTicket(l);
			cout << l.getString("pause");
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