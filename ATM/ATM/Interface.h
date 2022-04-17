#pragma once
#include "Language.h"

class Interface : public Language{
private:
	void alignCout(string &, char*);
	void getWindowSize(int &, int &);
public:
	Interface();
	void zastavka();
	void exit();
};