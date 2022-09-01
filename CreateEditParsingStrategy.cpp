//definitions of our own macrocommand's parsing strategy
//Author: Jeffrey Gong
#include "CreateEditParsingStrategy.h"

using namespace std;

const string space = " ";

vector<string> CreateEditParsingStrategy::parse(string input) {
	vector<string> result;
	result.push_back(input);
	size_t position = input.find(space);
	if (position == string::npos) {
		result.push_back(input);
	}
	else {
		string first = input.substr(0, position);
		result.push_back(first);
	}
	return result;
}