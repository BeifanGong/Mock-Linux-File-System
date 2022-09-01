//definitions of remove parsing strategy
//Author: Jeffrey Gong

#include "RenameParsingStrategy.h"

using namespace std;

const string s_pace = " ";
const string empty__ = "";

vector<string> RenameParsingStrategy::parse(string input) {
	vector<string> result;
	result.push_back(input);
	size_t pos = input.find(s_pace);
	if (pos == string::npos) {
		result.push_back(empty__);
	}
	else {
		result.push_back(input.substr(0, pos));
	}
	return result;
}