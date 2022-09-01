//definitions of display command
//Author: Jeffrey Gong
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include "Utils.h"
#include <iostream>

using namespace std;

const string d_extension = "-d";
const string space__ = " ";

DisplayCommand::DisplayCommand(AbstractFileSystem* system) {
	this->system = system;
}

int DisplayCommand::execute(string input) {
	size_t position = input.find(space__);
	//only one input
	if (position == string::npos) {
		AbstractFile* file = system->openFile(input);
		//file does not exist
		if (file == nullptr) {
			return file_does_not_exist;
		}
		BasicDisplayVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);
		system->closeFile(file);
		bool result = visitor->result;
		delete visitor;
		if (result) {
			return _success;
		}
		return wrong_password;
	}
	//two input
	else {
		string first = input.substr(0, position);
		string second = input.substr(position + 1);
		//illegal extension
		if (second != d_extension) {
			return illegal_argument;
		}
		AbstractFile* file = system->openFile(first);
		if (file == nullptr) {
			return file_does_not_exist;
		}
		vector<char> contents = file->read();
		for (auto it = contents.begin(); it < contents.cend(); ++it) {
			cout << *it;
		}
		cout << endl;
		system->closeFile(file);
		return _success;
	}
}

void DisplayCommand::displayInfo() {
	cout << "ds displays the contents of a file, use -d to display unformatted, ds can be invoked with command: ds <file_name> [-d]" << endl;
}
