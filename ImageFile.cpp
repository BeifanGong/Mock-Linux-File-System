// definition of ImageFile class here
//Author: Jeffrey Gong
#include "ImageFile.h"
#include <iostream>
#include "Utils.h"

using namespace std;


ImageFile::ImageFile(string name) {
	this->name = name;
	this->size = '0';
}

string ImageFile::getName() {
	return name;
}

unsigned int ImageFile::getSize() {
	return static_cast<unsigned int>(contents.size());
}

int ImageFile::write(vector<char> v) {
	if (v.size() == 0) {
		return illegal_argument;
	}
	int size = v[v.size() - 1] - '0';
	this->size = v[v.size() - 1];
	if (static_cast<int>(v.size()) != size * size + 1) {
		return illegal_argument;
	}
	for (size_t i = 0; i < v.size()-1; ++i) {
		if (v[i] != 'X' && v[i] != ' ') {
			this->size = '0';
			contents.clear();
			return illegal_argument;
		}
		else {
			contents.push_back(v[i]);
		}

	}
	return _success;
}

int ImageFile::append(vector<char>) {
	return unsupported_extension;
}

vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string name) {
	ImageFile* file = new ImageFile(name + ".img");
	file->contents = this->contents;
	return file;
}