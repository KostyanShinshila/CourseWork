#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Database::Database() {};

string Database::getSettingsPath(){
	return settingsPath;
}

string Database::getPath(string path){
	ifstream file(settingsPath);
	if (!file){
		cout << "\nConfig file not found.\n" << endl;
		system("pause");
	}

	string str;
	while (getline(file, str)){
		auto pos = str.find("|");
		if (pos != string::npos){
			string checkStr = str.substr(0, pos);
			string returnStr = str.substr(pos + 1);
			if (checkStr == path)
				return(returnStr);
		}
	}
}

void Database::createFileLogs(){
	string operPath = getPath("Operations");
	ofstream ost(operPath); // create file
}

void Database::addLogOperation(string type){
	string path = getPath("Operations");
	ofstream file(path, ios::app);
	if (!file){
		cout << "\nWrite file error.\n" << endl;
		system("pause");
		return;
	}
	file << type << endl;
	file.close();
}

void Database::readLogOperation(){
	string path = getPath("Operations");
	ifstream file(path);
	if (!file){
		cout << "\nConfig file not found.\n" << endl;
		system("pause");
	}

	string str;
	while (getline(file, str)){
		cout << str << endl;
	}
}