//simple file factory definitions
//Author: Jeffrey Gong
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(string name) {
	const string txt = "txt";
	const string img = "img";
	AbstractFile* file = nullptr;
	if (name.find(txt) != string::npos) {
		file = new TextFile(name);
		//addFile(name, file);
	}
	else if (name.find(img) != string::npos) {
		file = new ImageFile(name);
		//addFile(name, file);
	}
	return file;
}
