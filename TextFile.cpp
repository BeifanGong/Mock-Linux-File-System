//  Define the TextFile class here
//Author: Jeffrey Gong
#include "TextFile.h"
#include <iostream>

using namespace std;

TextFile::TextFile(string str) {
	name = str;
}

unsigned int TextFile::getSize() {
	return static_cast<unsigned int> (contents.size());
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> v) {
	contents = v;
	return 0;
}

int TextFile::append(vector<char> v) {
	for (auto i = v.cbegin(); i != v.cend(); ++i) {
		contents.push_back(*i);
	}
	return 0;
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string name) {
	TextFile* file = new TextFile(name + ".txt");
	file->contents = this->contents;
	return file;
}
