//definitions of cat command
//Author: Jeffrey Gong
#include "CatCommand.h"
#include "Utils.h"
#include <iostream>

using namespace std;

const string _space = " ";
const string save_quit = ":wq";
const string _quit = ":q";
const string append = "-a";

void prompt1() {
	cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
}

void prompt2() {
	cout << "Enter data you would like to append to the file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
}

CatCommand::CatCommand(AbstractFileSystem* system) {
	this->system = system;
}

int CatCommand::execute(string input) {
	size_t position = input.find(_space);
	//no append
	if (position == string::npos) {
		AbstractFile* file = system->openFile(input);
		//file does not exist
		if (file == nullptr) {
			return file_does_not_exist;
		}
		vector<char> result;
		prompt1();
		string in;
		getline(cin, in);
		bool newLine = false;
		while (in != save_quit && in != _quit) {
			if (newLine) {
				result.push_back('\n');
			}
			for (auto it = in.begin(); it < in.cend(); ++it) {
				result.push_back(*it);
			}
			newLine = true;
			getline(cin, in);
		}
		//no save
		if (in == _quit) {
			system->closeFile(file);
			return _success;
		}
		//save
		int r = file->write(result);
		system->closeFile(file);
		return r;
	}
	//with -a
	else {
		string first = input.substr(0, position);
		string second = input.substr(position + 1);
		//wrong argument
		if (second != append) {
			return illegal_argument;
		}
		AbstractFile* file = system->openFile(first);
		//file does not exist
		if (file == nullptr) {
			return file_does_not_exist;
		}
		vector<char> contents = file->read();
		cout << file->getName() << endl;
		for (auto it = contents.begin(); it < contents.cend(); ++it) {
			cout << *it;
		}
		cout << endl;
		vector<char> result;
		prompt2();
		string in;
		getline(cin, in);
		bool newLine = false;
		while (in != save_quit && in != _quit) {
			if (newLine) {
				result.push_back('\n');
			}
			for (auto it = in.begin(); it < in.cend(); ++it) {
				result.push_back(*it);
			}
			newLine = true;
			getline(cin, in);
		}
		//no save
		if (in == _quit) {
			system->closeFile(file);
			return _success;
		}
		//save
		int r = file->append(result);
		system->closeFile(file);
		return r;
	}
}

void CatCommand::displayInfo() {
	cout << "cat writes to a file, use -a to append instead, cat can be invoked by command: cat <file_name> [-a]" << endl;
}