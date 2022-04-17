#include "Database.h"
#include <iostream>
using namespace std;

Database::Database() {};

string Database::getSettingsPath(){
	return settingsPath;
}