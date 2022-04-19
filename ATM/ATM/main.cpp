#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include "Interface.h"
#include "Account.h"
using namespace std;

Interface c;
Language l;

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

void menu(){
	Money m("Доллары", 1500);
	Money *pm = &m;
	Account a("Пет", 123456, 0000, pm);
	a.addMoney(1500);
	cout << a.getSum() << endl;
	cout << a.getPin() << endl;
	system("pause");
}

void main(){
	setlocale(LC_ALL, "Russian");
	system("color F0");
	titulMenu();
	menu();
	//c.auth(l);
}