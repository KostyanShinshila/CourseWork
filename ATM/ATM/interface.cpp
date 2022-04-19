#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Interface.h"
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
using namespace std;

Interface::Interface(){}

void Interface::zastavka(Language&l){
	alignCout(l.getString(l, "zastavka_name"), "center");
	alignCout(l.getString(l, "zastavka_fac"), "left");
	alignCout(l.getString(l, "zastavka_kaf"), "left");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	alignCout(l.getString(l, "zastavka_curs"), "center");
	alignCout(l.getString(l, "zastavka_disciplina"), "center");
	alignCout(l.getString(l, "zastavka_tema"), "center");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << l.getString(l, "zastavka_rucovoditel");
	alignCout(l.getString(l, "zastavka_vipolnil"), "longcenter");
	cout << l.getString(l, "zastavka_prepod");
	alignCout(l.getString(l, "zastavka_student"), "longcenter");
	cout << l.getString(l, "zastavka_morozova");
	alignCout(l.getString(l, "zastavka_rudnev"), "longcenter");
	cout << l.getString(l, "zastavka_assistent") << endl;
	cout << l.getString(l, "zastavka_artemenko");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	alignCout(l.getString(l, "zastavka_doneck"), "center");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << l.getString(l, "zastavka_start");
	alignCout(l.getString(l, "zastavka_lang"), "longcenter");
	cout << l.getString(l, "zastavka_help");
	alignCout(l.getString(l, "zastavka_about_prog"), "longcenter");
}

//void auth(Language&l){
//	for (;;){
//		system("cls");
//		cout << "ÕÓÉ ÏÈÇÄÀ" << endl;
//	}
//}

/////////////////////////////////////////////////////////////////

void Interface::alignCout(string &s, char *type){
	int buffer_x_size, buffer_y_size;
	size_t width = s.length();
	size_t bord = 0;
	getWindowSize(buffer_x_size, buffer_y_size);
	if (strcmp("right", type) == 0) bord = (buffer_x_size - width);
	if (strcmp("center", type) == 0) bord = (buffer_x_size - width) / 2.;
	if (strcmp("longcenter", type) == 0) bord = (buffer_x_size - width) / 1.2;
	for (;;)
	{
		cout << setw(bord) << "";
		cout << s.substr(0u, width) << endl;
		s.erase(s.begin(), s.begin() + (s.size() < width ? s.size() : width));
		if (s.empty())
		{
			break;
		}
	}
}

void Interface::getWindowSize(int &x, int &y){
	HANDLE hWndConsole;
	if (hWndConsole = GetStdHandle(-12))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
		{
			x = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			y = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
		else
			printf("Error: %d\n", GetLastError());
	}
	else
		printf("Error: %d\n", GetLastError());
}