#pragma once
#include "Language.h"

class Interface{
private:
	void alignCout(string &, char*);
	void getWindowSize(int &, int &);
public:
	Interface();
	void zastavka(Language&l);
	void auth(Language&l);
};