#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include "Interface.h"
using namespace std;

Interface c;
Language l;

void titulMenu(){
	int key;
	do{
		c.zastavka();
		key = _getch();
		switch (key){
		case 'd':
			system("pause");
			break;
		case '\t':
			c.changeLang();
			break;
		
		case 13:
			return; // exit
			break;
		}

		fflush(stdin);
	} while (key != 27);
}

void main(){
	setlocale(LC_ALL, "Russian");
	system("color F0");
	titulMenu();
}