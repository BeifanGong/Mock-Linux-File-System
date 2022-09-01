// define methods of SimpleFileSystem class here
//Author: Jeffrey Gong
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "Utils.h"

using namespace std;


int SimpleFileSystem::addFile(string name, AbstractFile* file) {
	if (all.find(name) != all.end()) {
		return already_exist;
	}
	if (file == nullptr) {
		return null_file;
	}
	all[name] = file;
	return _success;
}

AbstractFile* SimpleFileSystem::openFile(string name) {
	if (all.find(name) == all.end()) {
		return nullptr;
	}
	AbstractFile* file = all[name];
	if (open.find(file) != open.end()) {
		return nullptr;
	}
	open.insert(file);
	return file;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (open.find(file) == open.end()) {
		return not_open;
	}
	open.erase(file);
	return _success;
}

int SimpleFileSystem::deleteFile(string name) {
	if (all.find(name) == all.end()) {
		return file_does_not_exist;
	}
	AbstractFile* file = all[name];
	if (open.find(file) != open.end()) {
		return is_open;
	}
	all.erase(name);
	delete file;
	return _success;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> temp;
	for (auto it = all.begin(); it != all.end(); it++) {
		temp.insert({ it->first });
	}
	return temp;
}

SimpleFileSystem::~SimpleFileSystem() {
	for (auto it = all.begin(); it != all.cend(); ++it) {
		delete it->second;
	}
}