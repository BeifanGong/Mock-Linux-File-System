//definitions of macro command
//Author: Jeffrey Gong

#include "MacroCommand.h"
#include <iostream>
#include "Utils.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* s) : strategy(nullptr), system(s) {
	
}

void MacroCommand::addCommand(AbstractCommand* command) {
	this->commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	this->strategy = strategy;
}

int MacroCommand::execute(string input) {
	vector<string> parsed = this->strategy->parse(input);
	for (size_t i = 0; i < commands.size(); ++i) {
		int result = commands[i]->execute(parsed[i]);
		if (result != _success) {
			return result;
		}
	}
	return _success;
}

void MacroCommand::displayInfo() {
	cout << "This is a macrocommand." << endl;
}