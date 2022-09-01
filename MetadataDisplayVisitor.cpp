// definitions of metadata visitor here
//Author: Jeffrey Gong
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	cout << setw(width) << file->getName();
	cout << setw(width) << "text";
	cout << setw(width) << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	cout << setw(width) << file->getName();
	cout << setw(width) << "image";
	cout << setw(width) << file->getSize() << endl;
}