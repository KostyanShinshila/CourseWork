#pragma once
#include <iostream>
#include "User.h"
using namespace std;

User::User(){
	isPin = false;
}

bool User::getIsPin(){
	if (isPin) return true;
	else return false;
}

void User::setIsPin(){
	isPin ? isPin = false : isPin = true;
}

void User::setIsPin(bool arg){
	arg ? isPin = true : isPin = false;
}

User::~User(){
	isPin = false;
}