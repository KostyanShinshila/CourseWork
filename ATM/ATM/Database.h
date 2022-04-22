#pragma once
#include <iostream>
using namespace std;

class Database{
private:
	const string settingsPath = "D:\\course work list\\config.txt";
	friend class Language;
public:
	Database();
	string getSettingsPath();
	string getPath(string path);
	void addLogOperation(string type);
	void readLogOperation();
	void createFileLogs();
};