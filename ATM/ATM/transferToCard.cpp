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
	cout << "	" << l.getString("transfer_card_hub") << "\n";
	cout << l.getString("transfer_card_message") << "\n";
	cout << "\n";
	cout << l.getString("transfer_card_recent") << "\n";
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
