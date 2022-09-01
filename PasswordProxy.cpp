//definitions of passwordproxy
//Author: Jeffrey Gong

#include "PasswordProxy.h"
#include <iostream>
#include "Utils.h"

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* realFile, string password) : realFile(realFile), password(password) {

}

PasswordProxy::~PasswordProxy(){
	delete realFile;
}

string PasswordProxy::passwordPrompt() {
	cout << "Please enter the password for: " + this->getName() << endl;
	string entered;
	getline(cin, entered);
	return entered;
}

bool PasswordProxy::checkPassword(string entered) {
	return password == entered;
}

vector<char> PasswordProxy::read(){
	string entered = passwordPrompt();
	vector<char> result;
	if (checkPassword(entered)) {
		return realFile->read();
	}
	cout << "wrong password." << endl;
	return result;
}

int PasswordProxy::write(vector<char> v) {
	string entered = passwordPrompt();
	if (checkPassword(entered)) {
		return realFile->write(v);
	}
	cout << "wrong password." << endl;
	return wrong_password;
}

int PasswordProxy::append(vector<char> v) {
	string entered = passwordPrompt();
	if (checkPassword(entered)) {
		return realFile->append(v);
	}
	cout << "wrong password." << endl;
	return wrong_password;
}

unsigned int PasswordProxy::getSize() {
	return realFile->getSize();
}

string PasswordProxy::getName() {
	return realFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	string entered = passwordPrompt();
	if (checkPassword(entered)) {
		realFile->accept(visitor);
	}
	else {
		cout << "wrong password." << endl;
	}
}

AbstractFile* PasswordProxy::clone(std::string name) {
	AbstractFile* newRealFile = realFile->clone(name);
	AbstractFile* file = new PasswordProxy(newRealFile, password);
	return file;
}