//definitions of copy command
//Author: Jeffrey Gong
#include "CopyCommand.h"
#include <iostream>
#include "Utils.h"

using namespace std;

const string space_ = " ";

CopyCommand::CopyCommand(AbstractFileSystem* system){
	this->system = system;
}

int CopyCommand::execute(string input) {
	size_t position = input.find(space_);
	if (position == string::npos) {
		return illegal_argument;
	}
	string first = input.substr(0, position);
	string second = input.substr(position + 1);
	AbstractFile* file = system->openFile(first);
	if (file == nullptr) {
		return file_does_not_exist;
	}
	AbstractFile* newFile = file->clone(second);
	int result = system->addFile(newFile->getName(), newFile);
	if (result != _success) {
		delete newFile;
	}
	system->closeFile(file);
	return result;
}

void CopyCommand::displayInfo() {
	cout << "cp copys a file, cp can be invoked with command: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}