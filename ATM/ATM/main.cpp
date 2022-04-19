#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include "Interface.h"
#include "User.h"
using namespace std;

Interface c;
Language l;
User user;
User *pu = &user;

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
	//Money m("Доллары", 1500);
	//Account a("Пет", 123456, 0000, m);
	//a.addMoney(1500);
	//cout << a.getSum() << endl;
	//cout << a.getPin() << endl;

	int key;
	do{
		system("cls");
		cout << "	" << l.getString("auth_hub") << endl;;
		cout << l.getString("auth_card");
		/* If card in atm */
		if (user.getIsPin()){
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
			user.setIsPin();
			break;
		case 'd':
			if (user.getIsPin()){
				delete pu;
				//titulMenu();
				//system("pause");
			}
			break;
		}

		fflush(stdin);
	} while (key != 27);
	
	system("pause");
}

void main(){
	setlocale(LC_ALL, "Russian");
	system("color F0");
	titulMenu();
	auth();
	//menu();
}