// Definition of TouchCommand
//Author: Sherry Zhang, Jeffrey Gong
#include "TouchCommand.h"
#include <iostream>
#include <sstream>
#include "Utils.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* fact) :
	fact(fact), system(system) {}

void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string s) {
	if (s == "") {
		displayInfo();
		return illegal_argument;
	}
	istringstream iss(s);
	string name, para;
	iss >> name;
	iss >> para;
	AbstractFile* temp = fact->createFile(name);

	if (para == "") {
		if (system->addFile(name, temp) != _success) {
			delete temp;
			return add_fail;
		}
		else {
			return _success;
		}
	}
	else if (para == "-p") {
		string password;
		cout << "What is the password?" << endl;
		getline(cin, password);
		PasswordProxy* PP = new PasswordProxy(temp, password);
		if (system->addFile(name, PP) != _success) {
			delete PP;
			return add_fail;
		}
		return _success;
	}
	else {
		displayInfo();
		return illegal_argument;
	}
}