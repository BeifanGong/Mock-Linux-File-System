//Definition of RemoveCommand
//Author: Sherry Zhang, Jeffrey Gong
#include <string>
#include <iostream>
#include <iomanip>
#include "AbstractFile.h"
#include "RemoveCommand.h"
#include "MetadataDisplayVisitor.h"
#include "Utils.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* A) : AFS(A) {}

void RemoveCommand::displayInfo() {
	cout << "rm removes a file from the system, remove can be invoked by command: rm <file_name>" << endl;
}

int RemoveCommand::execute(string s) {
	if (AFS->deleteFile(s) != _success) {
		displayInfo();
		return delete_fail;
	}
	return _success;
}