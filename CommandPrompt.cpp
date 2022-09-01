//definitions of commandprompt
//Author: Jeffrey Gong
#include "CommandPrompt.h"
#include <iostream>
#include "Utils.h"

using namespace std;

const string quit = "q";
const string help = "help";
const char space = ' ';
const string empty_string = "";

const int quit_ = -11;

CommandPrompt::CommandPrompt() :system(nullptr), fact(nullptr){
}

void CommandPrompt::setFileFactory(AbstractFileFactory* fact) {
	this->fact = fact;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* system) {
	this->system = system;
}

int CommandPrompt::addCommand(string name, AbstractCommand* command) {
	if (commands.find(name) != commands.cend()) {
		return already_exist;
	}
	commands[name] = command;
	return _success;
}

void CommandPrompt::listCommands() {
	for (auto it = commands.begin(); it != commands.cend(); ++it) {
		cout << it->first << endl;
	}
}

string CommandPrompt::prompt() {
	cout << "Enter a Command, q to quit, help for a list of commands, or" << endl;
	cout << "help followed by a command name for more information about that command." << endl;
	cout << "$   ";
	string instruction;
	getline(cin, instruction);
	return instruction;
}

int CommandPrompt::run() {
	string instruction = prompt();
	while (instruction != quit) {
		//command is help
		if (instruction == help) {
			listCommands();
			instruction = prompt();
			continue;
		}
		//one word
		size_t pos = instruction.find(space);
		if (pos == string::npos) {
			if (commands.find(instruction) == commands.cend()) {
				cout << "command does not exist" << endl;
				instruction = prompt();
				continue;
			}
			//command exists
			AbstractCommand* command = commands[instruction];
			int result = command->execute(empty_string);
			if (result != 0) {
				cout << "command fails" << endl;
			}
			instruction = prompt();
			continue;
		}

		//two word
		string inst_1 = instruction.substr(0, pos);
		string inst_2 = instruction.substr(pos + 1);

		//user ask for help
		if (inst_1 == help) {
			//command does not exist
			if (commands.find(inst_2) == commands.cend()) {
				cout << "command does not exist" << endl;
				instruction = prompt();
				continue;
			}

			//do exist
			AbstractCommand* command = commands[inst_2];
			command->displayInfo();
			instruction = prompt();
			continue;
		}

		//user does not ask for help
		//command does not exist
		if (commands.find(inst_1) == commands.cend()) {
			cout << "command does not exist" << endl;
			instruction = prompt();
			continue;
		}

		//do exist
		AbstractCommand* command = commands[inst_1];
		int result = command->execute(inst_2);
		if (result != 0) {
			cout << "command fails" << endl;
		}
		instruction = prompt();
		continue;
	}
	return quit_;
}