#include <iostream>
#include <string>
#include "TransferToCard.h"
using namespace std;

TransferToCard::TransferToCard(){
	transferName = "Перевод на карту";
	payNumbers = 16;
	recentTrans = 5;
}

void showInfo(Language&l){
	cout << "	" << l.getString("transfer_card_hub") << endl;
}