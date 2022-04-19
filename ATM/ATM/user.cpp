#pragma once
#include <iostream>
#include "User.h"
using namespace std;

User::User(){
	Account a;
	acc = a;
	isPin = false;
}

bool User::getIsPin(){
	if (isPin) return true;
	else return false;
}

void User::setIsPin(){
	isPin ? isPin = false : isPin = true;
}

User::~User(){

}