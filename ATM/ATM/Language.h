#pragma once
#include <iostream>
#include "Language.h"
using namespace std;

class Language{
	friend class Interface;
private:
	static const int languagesNum = 3;
	string languageName;
	string languages[languagesNum];
public:
	Language();
	string getString(string arg);
	string getPath();
	string getLanguageName();
	void changeLang();
	void setLanguageName(string arg);
};