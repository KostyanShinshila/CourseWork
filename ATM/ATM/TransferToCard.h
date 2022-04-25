#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class TransferToCard{
private:
	string transferName;
	int payNumbers;
	int recentTrans; //  ол-во выводимых последних карт дл€ перевода

public:
	TransferToCard();
	void showInfo(Language&l);
	void showRecentTrans(Database&bd);
	bool checkCardOnValid();
	void writeCheck(Database&bd, string address, long sum);
	void payService(User&user, long sum);

	int getRecentTrans();
	int getPayNumbers();
};