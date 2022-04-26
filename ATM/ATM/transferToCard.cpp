#include <iostream>
#include <string>
#include "TransferToCard.h"
using namespace std;

TransferToCard::TransferToCard(){
	transferName = "Перевод на карту";
	recentTrans = 5;
}

void TransferToCard::showInfo(Language&l){
	system("cls");
	cout << "	" << l.getString("transfer_card_hub") << endl;
	cout << l.getString("transfer_card_message") << endl;
	cout << endl;
	cout << l.getString("transfer_card_recent") << endl;
}

void TransferToCard::payService(User&user, long sum){
	user.subMoney(sum);
}

void TransferToCard::showRecentTrans(Database&bd){
	bd.readAvailableCards(recentTrans);
}

void TransferToCard::writeCheck(Database&bd, string address, long sum){
	bd.addLogOperation(transferName + " " + address + " - " + to_string(sum) + " Руб.");
}

bool TransferToCard::checkCardOnValid(Database&bd, string card){
	if (bd.findCard(card))
		return true;
	else
		return false;
}
