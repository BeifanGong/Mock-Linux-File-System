// definitions of basic display visitor here
// Author: Jeffrey Gong
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> contents = file->read();
	for (auto i = contents.cbegin(); i < contents.cend(); ++i) {
		cout << *i;
	}
	cout << endl;
	//detect whether password is correct
	result = true;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	vector<char> contents = file->read();
	int size = static_cast<int>(sqrt(file->getSize()));
	for (int y = size-1; y >= 0; --y) {
		for (int x = 0; x < size; ++x) {
			int index = size * y + x;
			cout << contents[index];
		}
		cout << endl;
		result = true;
	}
}
