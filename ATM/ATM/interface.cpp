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

void Interface::zastavka(){
	alignCout(getString("zastavka_name"), "center");
	alignCout(getString("zastavka_fac"), "left");
	alignCout(getString("zastavka_kaf"), "left");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	alignCout(getString("zastavka_curs"), "center");
	alignCout(getString("zastavka_disciplina"), "center");
	alignCout(getString("zastavka_tema"), "center");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << getString("zastavka_rucovoditel");
	alignCout(getString("zastavka_vipolnil"), "longcenter");
	cout << getString("zastavka_prepod");
	alignCout(getString("zastavka_student"), "longcenter");
	cout << getString("zastavka_morozova");
	alignCout(getString("zastavka_rudnev"), "longcenter");
	cout << getString("zastavka_assistent");
	cout << getString("zastavka_artemenko");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	alignCout(getString("zastavka_doneck"), "center");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << getString("zastavka_start");
	alignCout(getString("zastavka_lang"), "longcenter");
	cout << getString("zastavka_help");
	alignCout(getString("zastavka_about_prog"), "longcenter");

	int key;
	do{
		key = _getch();
		switch (key){
		case 'd':
			system("pause");
			break;
		}
		fflush(stdin);
	} while (key != 27);

}

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