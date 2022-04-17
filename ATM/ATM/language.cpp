#include "Language.h"
#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Language::Language(){
	languages[0] = "RU";
	languages[1] = "EN";
	languages[2] = "DE";
	languageName = languages[0];
}

string Language::getPath(){
	Database d;
	string path = d.getSettingsPath();
	ifstream file(path);
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
			if (checkStr == languageName)
				return(returnStr);
		}
	}
	return("Error");
}

string Language::getString(string arg){
	string path = getPath();

	if (path != "Error"){
		ifstream file(path);
		if (!file){
			cout << "\nPath file not found.\n" << endl;
			system("pause");
		}

		string str;
		while (getline(file, str)){
			auto pos = str.find("|");
			if (pos != string::npos){
				string checkStr = str.substr(0, pos);
				string returnStr = str.substr(pos + 1);
				if (checkStr == arg)
					return(returnStr);
			}
		}
	}

	else{
		cout << "\nPath find error.\n" << endl;
		system("pause");
		return("Error");
	}
	return("Error");
}

string Language::getLanguageName(){
	return languageName;
}

void Language::setLanguageName(string arg){
	languageName = arg;
}

void Language::changeLang(){
	system("cls");
	cout << getString("switch_lang_sharp") << endl;
	cout << getString("switch_lang_name") << endl;
	cout << endl;
	cout << getString("switch_lang_all");
	for (int i = 0; i < languagesNum; i++){
		cout << languages[i] << "; ";
	}
	cout << endl;
	cout << getString("switch_lang_now") << languageName << endl;
	cout << getString("switch_lang_sm") << endl;
	string findLang;
	cin >> findLang;

	bool isFind = false;
	for (int i = 0; i < languagesNum; i++){
		if (findLang == languages[i]){
			setLanguageName(languages[i]);
			cout << getString("switch_lang_ok") << endl;
			isFind = true;
			break;
		}
	}

	if (!isFind) cout << getString("switch_lang_er") << endl;
	system("pause");
	system("cls");
}