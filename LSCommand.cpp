//Definition of LSCommand
//Author: Sherry Zhang, Jeffrey Gong
#include <string>
#include <iostream>
#include <iomanip>
#include "AbstractFile.h"
#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include "Utils.h"
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* A) : AFS(A) {}

void LSCommand::displayInfo() {
	cout << "ls lists current files in the system, with -m to visit metadata ls can be invoked by command: ls [-m]" << endl;
}

int LSCommand::execute(string s) {
	set<string> fileName = AFS->getFileNames();
	if (s == "") {
		unsigned int count = 0;
		for (auto it = fileName.begin(); it != fileName.end(); it++) {
			count++;
			cout << left << setw(width) << *it;
			if (count % namePerLine == changeLine) {
				cout << endl;
			}
		}
		if (count % namePerLine != changeLine) {
			cout << endl;
		}
	}
	else if (s == "-m") {
		AbstractFile* temp;
		MetadataDisplayVisitor v = MetadataDisplayVisitor();
		for (auto it = fileName.begin(); it != fileName.end(); it++) {
			temp = AFS->openFile(*it);
			temp->accept(&v);
			AFS->closeFile(temp);
		}
	}
	else {
		displayInfo();
		return illegal_argument;
	}
	return _success;
}