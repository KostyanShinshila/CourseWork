#pragma once
#include "Language.h"

class Interface{
	friend class Language;
private:
	void alignCout(string &, char*);
	void getWindowSize(int &, int &);
public:
	Interface();
	void zastavka();
	void auth();
};